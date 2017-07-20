
#include <iostream>

#include <baselib/baselib.h>
#include "maze/maze.h"
int main(int /*argc*/, char* /*argv*/ []) {
  baselib::printInfo();
  std::cout << "========================================" << std::endl;
  maze::printMaze();
  std::cout << std::endl;
  // Main
  std::cout << "========================================" << std::endl;
  std::cout << "Main" << std::endl;
  std::cout << std::endl;

  return 0;
}
