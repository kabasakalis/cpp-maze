
#include "maze/base.h"
#include <iostream>

#include "maze/room.h"
using namespace utils;
namespace maze {
void testfunction() { std::cout << "testfunction ran" << std::endl; }
void printMaze() { std::cout << "maze::printMaze" << std::endl; }



// bool Position::operator==(const Position& rhs) const {
//  return (x == rhs.x && y == rhs.y);
// };




// bool Position::operator==(const Position& rhs)const{
//   std::cout << "Positionoperator overloaded ==  " << rhs.y;
//  return (x == rhs.x && y == rhs.y);
// }



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


bool maze::operator== (const maze::Position& lhs, const maze::Position& rhs) { return (lhs.x == rhs.x && lhs.y == rhs.y);}


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


