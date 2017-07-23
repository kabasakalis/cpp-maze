
#include "maze/base.h"
#include <iostream>

#include "maze/room.h"
using namespace utils;
namespace maze {
void testfunction() { std::cout << "testfunction ran" << std::endl; }
void printMaze() { std::cout << "maze::printMaze" << std::endl; }

std::map<Direction, Direction> opposite_direction{
    {Direction::LEFT, Direction::RIGHT},
    {Direction::RIGHT, Direction::LEFT},
    {Direction::UP, Direction::DOWN},
    {Direction::DOWN, Direction::UP}};

std::map<Direction, std::string> direction_name{
    {Direction::LEFT, "LEFT"},
    {Direction::RIGHT, "RIGHT"},
    {Direction::UP, "UP"},
    {Direction::DOWN, "DOWN"},
};

void logDirVector(const std::vector<Direction>& v, std::string message) {
  std::cout << message << std::endl;
  for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it;
    if (it != (--v.end())) std::cout << ", ";
  }
  std::cout << "\n";
}
}

std::ostream& operator<<(std::ostream& stream, const maze::Position& pos) {
  std::printf("Point x: %d, y: %d", pos.x, pos.y);
  return stream;
}

std::ostream& operator<<(std::ostream& stream, const maze::Room& room) {
  std::printf("Room at x: %d, y: %d", room.position().x, room.position().y);
  return stream;
}

std::ostream& operator<<(std::ostream& stream,
                         const maze::Direction direction) {
  std::cout << maze::direction_name[direction];
  return stream;
}
