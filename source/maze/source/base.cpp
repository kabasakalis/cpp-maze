
#include "maze/base.h"
#include <iostream>

#include "maze/room.h"
namespace maze {
void testfunction() { std::cout << "testfunction ran" << std::endl; }
void printMaze() { std::cout << "maze::printMaze" << std::endl; }

std::map<Direction, Direction> opposite_direction{
    std::make_pair(Direction::LEFT, Direction::RIGHT),
    std::make_pair(Direction::RIGHT, Direction::LEFT),
    std::make_pair(Direction::UP, Direction::DOWN),
    std::make_pair(Direction::DOWN, Direction::UP)};

}


std::ostream& operator<<(std::ostream& stream,
                         const maze::Position& pos) {

  std::printf("Point at x: %d, y: %d", pos.x, pos.y );
  return stream;
 }

std::ostream& operator<<(std::ostream& stream,
                         const maze::Room& room) {

  std::printf("Room  at x: %d, y: %d", room.position().x, room.position().y );
  return stream;
 }
