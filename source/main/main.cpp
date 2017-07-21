
#include <iostream>

#include <baselib/baselib.h>
#include "maze/base.h"
using namespace maze;

int main(int /*argc*/, char* /*argv*/ []) {
  baselib::printInfo();
  std::cout << "========================================" << std::endl;
  printMaze();
  testfunction();

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
