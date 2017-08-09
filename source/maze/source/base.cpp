
#include "maze/base.h"
#include <iostream>
#include "maze/room.h"

using namespace utils;

namespace maze {

std::map<Direction, std::string> direction_name{
    {Direction::LEFT, "LEFT"},
    {Direction::RIGHT, "RIGHT"},
    {Direction::UP, "UP"},
    {Direction::DOWN, "DOWN"},
};

const std::map<Direction, Direction> opposite_direction{
    {Direction::LEFT, Direction::RIGHT},
    {Direction::RIGHT, Direction::LEFT},
    {Direction::UP, Direction::DOWN},
    {Direction::DOWN, Direction::UP}};

void logDirVector(const std::vector<Direction>& v, std::string message) {
  std::cout << message << std::endl;
  for (auto it = v.begin(); it != v.end(); ++it) {
    std::cout << *it;
    if (it != (--v.end())) std::cout << ", ";
  }
  std::cout << "\n";
}

bool operator==(const maze::Position& lhs, const maze::Position& rhs) {
  return (lhs.x == rhs.x && lhs.y == rhs.y);
}

bool operator!=(const maze::Position& lhs, const maze::Position& rhs) {
  return (lhs.x != rhs.x || lhs.y != rhs.y);
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
