#include "maze/maze.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>  // unique_ptr
#include "maze/room.h"
// #include "boost/multi_array.hpp"

#include "maze/utils.h"
using namespace utils;
namespace maze {

// Constructor
Maze::Maze(int rows, int columns) : _rows{rows}, _columns{columns} {
  for (int x = 1; x <= _rows; ++x) {
    for (int y = 1; y <= _columns; ++y) {
      Position position{x, y};
      Room room{position};
      _rooms.push_back(room);
    }
  }
}

boost::optional<Room*>
Maze::find_room(const Position& position) const  {
  auto it = find_if(_rooms.begin(), _rooms.end(), [position](const Room& room) {
    return room.position() == position;
  });
  if (it != _rooms.end()) {
    boost::optional<Room*> room_ptr = const_cast<Room*>(&(*it));
    return room_ptr;
  }
  return boost::none;
};


boost::optional< Room*>
Maze::fr(const Position& position)   {
  auto it = find_if(_rooms.begin(), _rooms.end(), [position]( Room& room) {
    return room.position() == position;
  });
  if (it != _rooms.end()) {
    boost::optional<Room*> lala =  &(*it);
    return lala;
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


const std::vector<Room>&
Maze::rooms() const { return _rooms;}

const int& Maze::rows() const { return _rows; }
const int& Maze::columns() const {return _columns;}


}  // namespace maze
