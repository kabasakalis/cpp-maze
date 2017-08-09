
#include "maze/maze.h"
#include <algorithm>
#include "maze/room.h"
#include "maze/utils.h"
using namespace utils;
namespace maze {

// Constructor
Maze::Maze(int columns, int rows) : _columns{columns}, _rows{rows}  {
  for (int x = 1; x <= _rows; ++x) {
    for (int y = 1; y <= _columns; ++y) {
      Position position{y, x};
      Room room{position};
      _rooms.push_back(room);
    }
  }
}

boost::optional<Room*>
Maze::find_room(const Position& position) const  {
  auto it = find_if(_rooms.begin(), _rooms.end(), [&position](const Room& room) {
    return room.position() == position;
  });
  if (it != _rooms.end()) {
    boost::optional<Room*> room_ptr = const_cast<Room*>(&(*it));
    return room_ptr;
  }
  return boost::none;
};

boost::optional<Room*>
Maze::find_room(int x, int y)  {
  Position position{x, y};
 return  find_room(position);
};

bool Maze::all_rooms_visited() const{
    return std::all_of(_rooms.begin(), _rooms.end(),
                       [](Room room) { return room.visited(); });};

std::vector<Room>&
Maze::rooms()  { return _rooms;}
const int& Maze::rows() const { return _rows; }
const int& Maze::columns() const {return _columns;}

}  // namespace maze
