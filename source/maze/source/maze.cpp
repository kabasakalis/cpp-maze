#include "maze/maze.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <memory>  // unique_ptr
#include "maze/room.h"
// #include "boost/multi_array.hpp"
namespace maze {

// Constructor
Maze::Maze(int rows = 10, int columns = 10) {
  for (int x = 0; i < rows; ++x) {
    for (int y = 0; y < columns; ++y) {
      Position position{x, y};
      Room room{position};
      rooms.push_back(room);
    }
  }
}

auto Maze::find_room(Position& position) {
  auto it = find_if(rooms.begin(), rooms.end(), [position](const Room& room) {
    return room.position == position;
  });
  if (it != rooms.end()) return **it;
  return boost::none;
};

auto Maze::find_room(int x, int y) {
  Position position{x, y};
  find_room(position);
};

auto Maze::all_rooms_visited(){
    return std::all_of(rooms.begin(), rooms.end(),
                       [](Room room) { room.visited(); })};

}  // namespace maze
