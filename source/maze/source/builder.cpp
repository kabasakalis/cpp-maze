
//#include <memory>  // unique_ptr

#include "maze/builder.h"
#include <algorithm>
#include <boost/optional.hpp>
#include <random>
#include <chrono>
using namespace utils;
namespace maze {

std::map<Direction, Direction> opposite_direction{
    {Direction::LEFT, Direction::RIGHT},
    {Direction::RIGHT, Direction::LEFT},
    {Direction::UP, Direction::DOWN},
    {Direction::DOWN, Direction::UP}};



// Constructor
Builder::Builder(const Maze& maze) : _maze{maze} {
    Position start{ _random_integer(0, _maze.rows()), _random_integer(0, _maze.columns())};
    _path.push_back(std::move(start));
    _visited_positions.push_back(std::move(start));
}

int Builder::_random_integer(int lower, int upper) const {
  auto  seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator(seed);
  std::uniform_int_distribution<int> distribution(lower, upper);
  return distribution(generator);
}

boost::optional<Position>  Builder::current_position() const {
  boost::optional<Position>  last = _visited_positions.rbegin()[0];
if (_visited_positions.size() >= 1 && last != boost::none )  return last;
return boost::none;
}

boost::optional<Position> Builder::previous_position() const {
  boost::optional<Position>  second_to_last = _visited_positions.rbegin()[1];
if (_visited_positions.size() >= 2 && second_to_last != boost::none )  return second_to_last;
return boost::none;
}

void Builder::go_back_to_previous_visited_room() {
  if (!_visited_positions.empty()) _visited_positions.pop_back();
}
boost::optional<Room> Builder::room(
    const Position& position) const {
  return _maze.find_room(position);
}

boost::optional<Room> Builder::current_room() { return room(*current_position());}


boost::optional<const Position> Builder::next_position(
    const Direction& direction, const Position& position) const {
  int next_position_x, next_position_y;
  boost::optional<const Position> next;
  switch (direction) {
    case Direction::LEFT: {
      if (position.x - 1 >= 1) {
         next_position_x = position.x - 1 ;
         next_position_y = position.y;
         // next->x = position.x - 1;
         // next->y = position.y ;
      } else {
         next = boost::none;
      }
      break;
    }
    case Direction::RIGHT: {
      if (position.x + 1 <= _maze.columns()) {
         next_position_x = position.x + 1 ;
         next_position_y = position.y;
        // Position next{position.x + 1, position.y};
      } else {
       next = boost::none;
      }
      break;
    }
    case Direction::DOWN: {
      if (position.y + 1 <= _maze.rows()) {
        // Position next{position.x, position.y + 1};
         next_position_x = position.x ;
         next_position_y = position.y + 1;

      } else {
         next = boost::none;
      }
      break;
    }
    case Direction::UP: {
      if (position.y - 1 >= 1) {
         next_position_x = position.x;
         next_position_y = position.y - 1;
        // Position next{position.x, position.y - 1};
      } else {
         next = boost::none;
      }
      break;
    }
    default: {  next = boost::none; }
  }
  if (next == boost::none) return boost::none;
  Position  next_position{next_position_x, next_position_y};
  return next_position;
}

boost::optional< Room> Builder::room_to_left() const {
  boost::optional<const Position> _next_position = next_position(Direction::LEFT, *Builder::current_position());
  return  (_next_position == boost::none) ? boost::none : room(*_next_position);
}

boost::optional< Room> Builder::room_to_right() const {
  boost::optional<const Position> _next_position = next_position(Direction::RIGHT, *Builder::current_position());
  return  (_next_position == boost::none) ? boost::none : room(*_next_position);
}


boost::optional< Room> Builder::room_to_up() const {
  boost::optional<const Position> _next_position = next_position(Direction::UP, *Builder::current_position());
  return  (_next_position == boost::none) ? boost::none : room(*_next_position);
}


boost::optional< Room> Builder::room_to_down() const {
  boost::optional<const Position> _next_position = next_position(Direction::DOWN, *Builder::current_position());
  return  (_next_position == boost::none) ? boost::none : room(*_next_position);
}

boost::optional<Direction>
    Builder::determine_direction(const Room& next_room) const {
  boost::optional<Direction> direction_to_next_room;

auto direction_iter = std::find_if(DIRECTIONS.begin(), DIRECTIONS.end(), [this, nr = next_room](Direction direction)->bool {

    auto room_to_direction =
        this->room( *(this->next_position(direction, *(this->current_position()))) );
    return (room_to_direction != boost::none &&
            room_to_direction->position() == nr.position());
    });
  // auto lala = ( direction_iter != directions.end()) ?  direction_iter : boost::none;
// return *lala;

if ( direction_iter != DIRECTIONS.end()) return *direction_iter;
return boost::none;

}

std::vector<Room> Builder::valid_rooms_to_build() const {
  std::vector<Room> valid_rooms;

  for (auto direction : DIRECTIONS) {
    auto room_to_direction = room(*next_position(direction, *current_position()));
    if (room_to_direction != boost::none && !room_to_direction->visited()) {
      valid_rooms.push_back(*room_to_direction);
    }
  }

  if (previous_position() != boost::none) {
    auto previous_room = room(*previous_position());
    valid_rooms.erase(
        std::remove_if(std::begin(valid_rooms), std::end(valid_rooms),
                       [&previous_room](Room r) {
                         return r.position() == previous_room->position();
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
  logVar("", "Started Building Maze.");

  while (!_maze.all_rooms_visited()) {

    auto valid_rooms_to_build_ = valid_rooms_to_build();
    auto current_room_ = current_room();
    if  (!valid_rooms_to_build_.empty()) {
        auto next_room = valid_rooms_to_build_.front();
        auto direction = determine_direction(next_room);
        build_room( *current_room_, *direction);
        _path.push_back(next_room.position());
        _visited_positions.push_back(next_room.position());
         build_room(next_room, maze::opposite_direction.at(*direction));
      }
    else {
      go_back_to_previous_visited_room();
      _path.push_back(current_room_->position());
    }  // if
  }  // while

  logVar("", "Completed in :");
  logVar(_path.size(), " steps: ");
  // hello
}

}  // namespace maze
