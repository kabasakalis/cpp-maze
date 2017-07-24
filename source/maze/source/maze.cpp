#include "maze/maze.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>  // unique_ptr
#include "maze/room.h"
// #include "boost/multi_array.hpp"
namespace maze {

// Constructor
Maze::Maze(int rows, int columns) : _rows{rows}, _columns{columns} {
  for (int x = 0; x < _rows; ++x) {
    for (int y = 0; y < _columns; ++y) {
      Position position{x, y};
      Room room{position};
      _rooms.push_back(room);
    }
  }
}

boost::optional<const Room&>
Maze::find_room(Position& position) const {
  auto it = find_if(_rooms.begin(), _rooms.end(), [position](const Room& room) {
    return room.position() == position;
  });
  if (it != _rooms.end()) return *it;
  return boost::none;
};

boost::optional<const Room&>
Maze::find_room(int x, int y) const {
  Position position{x, y};
 return  find_room(position);
};

auto Maze::all_rooms_visited() const{
    return std::all_of(_rooms.begin(), _rooms.end(),
                       [](Room room) { return room.visited(); });};


const std::vector<Room>&
Maze::rooms() const { return _rooms;}


}  // namespace maze
