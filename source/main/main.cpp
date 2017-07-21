
#include <iostream>

#include <baselib/baselib.h>
#include "maze/base.h"
#include "maze/room.h"
using namespace maze;

int main(int /*argc*/, char* /*argv*/ []) {
  baselib::printInfo();
  std::cout << "========================================" << std::endl;
  printMaze();
  testfunction();
  Position p{10, 20};
  Room r{p};

   std::cout << "p x: "<< p.x << std::endl;
   std::cout << "p y: "<< p.y << std::endl;
   std::cout << "room p x: "<< r.position().x << std::endl;
   std::cout << "room p y: "<< r.position().y << std::endl;
   std::cout << "room x: "<< r.x() << std::endl;
   std::cout << "room y: "<< r.y() << std::endl;
    // std::cout << ROWS_MAX << std::endl;
  // std::cout <<  Directions::LEFT<< std::endl;
  // std::cout <<  int(Direction::UP)<< std::endl;
  // std::cout <<  opposite_direction[Direction::LEFT]<< std::endl;
  // std::cout <<  opposite_direction[Direction::RIGHT]<< std::endl;
   std::cout << std::endl;
  // Main
  std::cout << "========================================" << std::endl;
  std::cout << "Main" << std::endl;
  std::cout << std::endl;

  return 0;
}
