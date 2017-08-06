
//#include <memory>  // unique_ptr

#include "maze/builder.h"
#include "maze/utils.h"
#include <algorithm>
#include <boost/optional.hpp>
#include <boost/optional/optional_io.hpp>
#include <functional>   // std::reference_wrapper
class Room;
using namespace utils;

namespace maze {
  typedef std::vector<std::reference_wrapper<Room>> Rooms;
  typedef std::reference_wrapper<Room> RoomRef;

std::map<Direction, Direction> opposite_direction{
    {Direction::LEFT, Direction::RIGHT},
    {Direction::RIGHT, Direction::LEFT},
    {Direction::UP, Direction::DOWN},
    {Direction::DOWN, Direction::UP}};

Builder::Builder() {};

// Constructor
Builder::Builder(const Maze& maze) : _maze{maze} {
    Position start{ random_integer(1, _maze.rows()), random_integer(1, _maze.columns())};
    _path.push_back(std::move(start));
    _visited_positions.push_back(std::move(start));
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
 boost::optional<Room*> Builder::room(
    const Position& position) const {
  return _maze.find_room(position);
}

 boost::optional<Room*> Builder::current_room() {
   auto current_position_ = current_position();
   logVar( *current_position_, "current Posito = boost::none");
    if ( current_position_ != boost::none) return room(*current_position_);
    return boost::none;
}

 boost::optional<const Position> Builder::next_position(
    const Direction& direction, const Position& position) const {
  int next_position_x, next_position_y;
  bool out_of_bounds{false};
  // boost::optional<const Position> next;
  switch (direction) {
    case Direction::LEFT: {
      if (position.x - 1 >= 1) {

         // logVar("", "CASE LEFT");
         next_position_x = position.x - 1 ;
         next_position_y = position.y;
         // next->x = position.x - 1;
         // next->y = position.y ;
      } else {
        out_of_bounds = true;
      }
      break;
    }
    case Direction::RIGHT: {
      if (position.x + 1 <= _maze.columns()) {

         // logVar("", "CASE RIGHT");
         next_position_x = position.x + 1 ;
         next_position_y = position.y;
        // Position next{position.x + 1, position.y};
      } else {
        out_of_bounds = true;
      }
      break;
    }
    case Direction::DOWN: {

      if (position.y + 1 <= _maze.rows()) {
        // logVar("", "CASE DOWN");
        // Position next{position.x, position.y + 1};
         next_position_x = position.x ;
         next_position_y = position.y + 1;

      } else {

        out_of_bounds = true;
      }
      break;
    }
    case Direction::UP: {

      if (position.y - 1 >= 1) {
        // logVar("", "CASE UP");
         next_position_x = position.x;
         next_position_y = position.y - 1;
        // Position next{position.x, position.y - 1};
      } else {

        out_of_bounds = true;
      }
      break;
    }
    default: {return boost::none;break; }
  }
  if (out_of_bounds) return boost::none;
  Position  next_position{next_position_x, next_position_y};
  // logVar(next_position,   "next position");
  return next_position;
}

// boost::optional< Room> Builder::room_to_left() const {
//   boost::optional<const Position> _next_position = next_position(Direction::LEFT, *Builder::current_position());
//   return  (_next_position == boost::none) ? boost::none : room(*_next_position);
// }
//
// boost::optional< Room> Builder::room_to_right() const {
//   boost::optional<const Position> _next_position = next_position(Direction::RIGHT, *Builder::current_position());
//   return  (_next_position == boost::none) ? boost::none : room(*_next_position);
// }
//
//
// boost::optional< Room> Builder::room_to_up() const {
//   boost::optional<const Position> _next_position = next_position(Direction::UP, *Builder::current_position());
//   return  (_next_position == boost::none) ? boost::none : room(*_next_position);
// }
//
//
// boost::optional< Room> Builder::room_to_down() const {
//   boost::optional<const Position> _next_position = next_position(Direction::DOWN, *Builder::current_position());
//   return  (_next_position == boost::none) ? boost::none : room(*_next_position);
// }

boost::optional<Direction>
    Builder::determine_direction(const Room& next_room) const {
  boost::optional<Direction> direction_to_next_room;

        // logVar("", "Determine direction 1");
auto direction_iter = std::find_if(DIRECTIONS.begin(), DIRECTIONS.end(), [ this, nr = next_room](Direction direction) mutable ->bool {

        // logVar("", "Determine direction 2");
        // logVar(nr, "NEXT ROOM");
  auto   current_position_ = current_position();
auto next_position_ = (current_position_  != boost::none ) ?  next_position(direction, *current_position_): boost::none;
auto room_to_direction = (next_position_  != boost::none ) ?  room(*next_position_ ) : boost::none;

        // logVar("", "Determine direction 3");
    return (room_to_direction != boost::none &&
            (**room_to_direction).position() == nr.position());
    });

if ( direction_iter != DIRECTIONS.end()) return *direction_iter;
return boost::none;

}

// std::vector<Room> Builder::valid_rooms_to_build() const {
//   std::vector<Room> valid_rooms;
//
//   for (auto direction : DIRECTIONS) {
//     auto cp_ptr = current_position();
//
//     // logVar(*cp_ptr, "Current Position");
//     auto np = next_position(direction, *cp_ptr);
//
//     // logVar(np == boost::none, "np == none?");
//     // if (np != boost::none)  logVar(*np, "np");
//     // if (np != boost::none)  logVar(*(room(*np)), "room(*np)");
//     auto room_to_direction = (np == boost::none || room(*np) == boost::none ) ? boost::none  : room(*np);
//
//     // logVar(room_to_direction == boost::none, "room_to_direction = none");
//     // logVar(*room_to_direction, "room to direction");
//     // auto room_to_direction = room(*next_position(direction, *current_position()));
//     if (room_to_direction != boost::none && !(**room_to_direction).visited()) {
//     logVar(**room_to_direction, "Pushing to valid rooms");
//       valid_rooms.push_back(**room_to_direction);
//     }
//   }
//
//     logVar(valid_rooms.size(), "Valid Rooms Size before");
//     auto pp = previous_position();
//     // logVar(pp== boost::none, "pp is none");
//   if ( pp != boost::none) {
//
//     logVar("", "Removing previous from valid rooms.");
//     // logVar("", "Removing previous room from valid rooms. ");
//     auto previous_room = room(*pp);
//     valid_rooms.erase(
//         std::remove_if(std::begin(valid_rooms), std::end(valid_rooms),
//                        [&previous_room](Room r) {
//                        logVar(r.position() == (**previous_room).position(), "POS EQ");
//                          return r.position() == (**previous_room).position();
//
//                        }),
//         std::end(valid_rooms));
//   };
//
//     logVar(valid_rooms.size(), "Valid Rooms After ");
//   return valid_rooms;
// };


Rooms Builder::valid_rooms_to_build() const {
  // std::vector<Room*> valid_rooms;
  Rooms valid_rooms;

  for (auto direction : DIRECTIONS) {
    auto cp_ptr = current_position();

    // logVar(*cp_ptr, "Current Position");
    auto np = next_position(direction, *cp_ptr);

    // logVar(np == boost::none, "np == none?");
    // if (np != boost::none)  logVar(*np, "np");
    // if (np != boost::none)  logVar(*(room(*np)), "room(*np)");
    auto room_to_direction = (np == boost::none || room(*np) == boost::none ) ? boost::none  : room(*np);

    // logVar(room_to_direction == boost::none, "room_to_direction = none");
    // logVar(*room_to_direction, "room to direction");
    // auto room_to_direction = room(*next_position(direction, *current_position()));
    if (room_to_direction != boost::none && !(**room_to_direction).visited()) {
    logVar(**room_to_direction, "Pushing to valid rooms");
      valid_rooms.push_back(**room_to_direction);
    }
  }

    logVar(valid_rooms.size(), "Valid Rooms Size before");
    auto pp = previous_position();
    // logVar(pp== boost::none, "pp is none");
  if ( pp != boost::none) {

    logVar("", "Removing previous from valid rooms.");
    // logVar("", "Removing previous room from valid rooms. ");
    auto previous_room = room(*pp);
    valid_rooms.erase(
        std::remove_if(std::begin(valid_rooms), std::end(valid_rooms),
                       [&previous_room](RoomRef r) {
                       logVar(r.get().position() == (**previous_room).position(), "POS EQ");
                         return r.get().position() == (**previous_room).position();

                       }),
        std::end(valid_rooms));
  };

    logVar(valid_rooms.size(), "Valid Rooms After ");
  return valid_rooms;
};




void Builder::build_room(Room& a_room, const Direction& exit_to_free) {
  a_room._available_exits.push_back(exit_to_free);
  a_room._visits_from.push_back(exit_to_free);

   logVar(a_room, "Building Room");
  logDirVector( a_room._visits_from, "visits_from:");
}

void Builder::build_maze() {
  logVar("", "Started Building Maze.");

  logVar(_path.back(), "start"  );
  logVar(_path.size(),"PATH SIZE START");
  while (!_maze.all_rooms_visited()) {
    // for (int i = 0; i < 4; i++) {

    auto valid_rooms_to_build_ = valid_rooms_to_build();

    auto current_room_ = current_room();

    logVar( **current_room_,  "Current room");
     // logVar(current_room_ == boost::none, "CURRENT ROOM = NONE");
    if  (!valid_rooms_to_build_.empty()) {
        logVar( valid_rooms_to_build_.size(),  "Valid rooms number in buildmaze");
        // Room& next_room = valid_rooms_to_build_.back().get();
        // auto random_index = static_cast<unsigned int>(random_integer(0, valid_rooms_to_build_.size() - 1 ));
        // Room& next_room = valid_rooms_to_build_.at(random_index).get();
        Room& next_room = random_element(valid_rooms_to_build_).get();
        //   Room& next_room = valid_rooms_to_build_.at(_random_integer(0, valid_rooms_to_build_.size() - 1 )).get();
        logVar(next_room, " next_room to build");
        auto direction = determine_direction(next_room);
        logVar(*direction, "DETERMINED DIR");
       // if (direction != boost::none) build_room( *current_room_, *direction);
          build_room( **current_room_, *direction);
        _path.push_back(next_room.position());
        _visited_positions.push_back(next_room.position());
        logVar(maze::opposite_direction.at(*direction), "OPPOSITE DIRE");
        build_room(next_room, maze::opposite_direction.at(*direction));
         // break;
        // logVar(valid_rooms_to_build_.size(), "valid_rooms_to_build_.");
      }
    else {

      logVar("", "GOING BACK");
      go_back_to_previous_visited_room();
      // _path.push_back(current_room_->position());
      // _path.push_back((**(current_room())).position());
      // _path.push_back((**current_room_).position());
      _path.push_back((**current_room()).position());
    }  // if
  }  // while


  logVar("", "Maze built in :");
  logVar(_path.size(), " steps: ");


   Position p11{1,1};
   Position p12{1,2};
   Position p22{2,2};
   Position p21{2,1};
   Position p99{9,9};

   auto r11= _maze.find_room(p11);
   auto r12= _maze.find_room(p12);
   auto r21= _maze.find_room(p21);
   auto r22= _maze.find_room(p22);
   auto r99= _maze.find_room(p99);

  logDirVector( (**r11)._visits_from, "r11.visits_from");
  logDirVector( (**r12)._visits_from, "r12.visits_from");
  logDirVector( (**r21)._visits_from, "r21.visits_from");
  logDirVector( (**r22)._visits_from, "r22.visits_from");
  logDirVector( (**r99)._visits_from, "r99.visits_from");

  // hello
}


const Maze& Builder::maze() const {return _maze;}
const std::vector<Position>& Builder::path() const {return _path;}


}  // namespace maze
