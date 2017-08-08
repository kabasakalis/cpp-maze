
#include "maze/builder.h"
#include <algorithm>
#include <boost/optional.hpp>
#include <boost/optional/optional_io.hpp>
#include <chrono>
#include <functional>  // std::reference_wrapper
#include "maze/utils.h"
#include "maze/base.h"

class Room;  // forward declaration
using namespace utils;

namespace maze {
typedef std::vector<std::reference_wrapper<Room>> Rooms;
typedef std::reference_wrapper<Room> RoomRef;

// Default constructor
Builder::Builder(){};

// Constructor
Builder::Builder(const Maze& maze) : _maze{maze} {
  Position start{random_integer(1, _maze.columns()),
                 random_integer(1, _maze.rows())};
  _path.push_back(std::move(start));
  _visited_positions.push_back(std::move(start));
}

boost::optional<Position> Builder::current_position() const {
  boost::optional<Position> last = _visited_positions.rbegin()[0];
  if (_visited_positions.size() >= 1 && last != boost::none) return last;
  return boost::none;
}

boost::optional<Position> Builder::previous_position() const {
  boost::optional<Position> second_to_last = _visited_positions.rbegin()[1];
  if (_visited_positions.size() >= 2 && second_to_last != boost::none)
    return second_to_last;
  return boost::none;
}

void Builder::go_back_to_previous_visited_room() {
  if (!_visited_positions.empty()) _visited_positions.pop_back();
}

boost::optional<Room*> Builder::room(const Position& position) const {
  return _maze.find_room(position);
}

boost::optional<Room*> Builder::current_room() {
  auto current_position_ = current_position();
  if (current_position_ != boost::none) return room(*current_position_);
  return boost::none;
}

boost::optional<const Position> Builder::next_position(
    const Direction& direction, const Position& position) const {
  int next_position_x, next_position_y;
  bool out_of_bounds{false};
  switch (direction) {
    case Direction::LEFT: {
      if (position.x - 1 >= 1) {
        next_position_x = position.x - 1;
        next_position_y = position.y;
      } else {
        out_of_bounds = true;
      }
      break;
    }
    case Direction::RIGHT: {
      if (position.x + 1 <= _maze.columns()) {
        next_position_x = position.x + 1;
        next_position_y = position.y;
      } else {
        out_of_bounds = true;
      }
      break;
    }
    case Direction::DOWN: {
      if (position.y + 1 <= _maze.rows()) {
        next_position_x = position.x;
        next_position_y = position.y + 1;

      } else {
        out_of_bounds = true;
      }
      break;
    }
    case Direction::UP: {
      if (position.y - 1 >= 1) {
        next_position_x = position.x;
        next_position_y = position.y - 1;
      } else {
        out_of_bounds = true;
      }
      break;
    }
    default: {
      return boost::none;
      break;
    }
  }
  if (out_of_bounds) return boost::none;
  Position next_position{next_position_x, next_position_y};
  return next_position;
}

boost::optional<Direction> Builder::determine_direction(
    const Room& next_room) const {
  boost::optional<Direction> direction_to_next_room;
  auto direction_iter = std::find_if(
      DIRECTIONS.begin(), DIRECTIONS.end(),
      [ this, nr = next_room ](Direction direction) mutable->bool {
        auto current_position_ = current_position();
        auto next_position_ = (current_position_ != boost::none)
                                  ? next_position(direction, *current_position_)
                                  : boost::none;
        auto room_to_direction = (next_position_ != boost::none)
                                     ? room(*next_position_)
                                     : boost::none;
        return (room_to_direction != boost::none &&
                (**room_to_direction).position() == nr.position());
      });
  if (direction_iter != DIRECTIONS.end()) return *direction_iter;
  return boost::none;
}

Rooms Builder::valid_rooms_to_build() const {
  Rooms valid_rooms;
  for (auto direction : DIRECTIONS) {
    auto cp_ptr = current_position();
    auto np = next_position(direction, *cp_ptr);
    auto room_to_direction = (np == boost::none || room(*np) == boost::none)
                                 ? boost::none
                                 : room(*np);
    if (room_to_direction != boost::none && !(**room_to_direction).visited()) {
      valid_rooms.push_back(**room_to_direction);
    }
  }

  auto pp = previous_position();
  if (pp != boost::none) {
    auto previous_room = room(*pp);
    valid_rooms.erase(
        std::remove_if(std::begin(valid_rooms), std::end(valid_rooms),
                       [&previous_room](RoomRef r) {
                         return r.get().position() ==
                                (**previous_room).position();
                       }),
        std::end(valid_rooms));
  };
  return valid_rooms;
};

void Builder::build_room(Room& a_room, const Direction& exit_to_free) {
  a_room.available_exits().push_back(exit_to_free);
  a_room.visits_from().push_back(exit_to_free);
}

void Builder::build_maze() {
  printf("Started building maze of %lu rooms.\n", _maze.rooms().size());
  auto start = std::chrono::high_resolution_clock::now();
  while (!_maze.all_rooms_visited()) {
    auto valid_rooms_to_build_ = valid_rooms_to_build();
    auto current_room_ = current_room();
    if (!valid_rooms_to_build_.empty()) {
      Room& next_room = random_element(valid_rooms_to_build_).get();
      auto direction = determine_direction(next_room);
      build_room(**current_room_, *direction);
      _path.push_back(next_room.position());
      _visited_positions.push_back(next_room.position());
      build_room(next_room, maze::opposite_direction.at(*direction));
    } else {
      go_back_to_previous_visited_room();
      _path.push_back((**current_room()).position());
    }
  }
  auto end = std::chrono::high_resolution_clock::now();
  auto execution_time =
      std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
          .count();
  printf("Maze built in %lu steps, %lu.%lu seconds. \n", _path.size(),
         execution_time / 1000, execution_time % 1000);
}

const Maze& Builder::maze() const { return _maze; }
const std::vector<Position>& Builder::path() const { return _path; }

}  // namespace maze
