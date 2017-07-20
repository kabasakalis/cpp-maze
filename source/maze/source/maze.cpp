//
// #include <maze/maze.h>
// #include <fstream>
// #include <iostream>
//
// namespace maze {
//
// Maze::Maze() {}
//
// Maze::~Maze() {}
//
// int Maze::returnOne() { return 1; }
//
// void printMaze() {
//   // Library name
//   std::cout << "mylib::printMaze" << std::endl;
//   int kaka = 99;
// }
//
// }  // namespace maze




//#include <memory>  // unique_ptr

#include "maze/maze.h"
#include <fstream>
#include <iostream>

namespace maze {

  // Default constructor
  Maze::Maze() {}

  // Constructor
  Maze::Maze(std::string string_)
    : mString{string_}
    {}


  int Maze::returnOne() { return 1; }

  // Special Member functions

  //virtual Maze()::~Maze() = default                   // dtor
  //Maze::Maze(const Maze& rhs) = default;                   // copy constructor
  //Maze& Maze::operator=(const Maze& rhs) = default;         // copy assignment
  //Maze::Maze(Maze&& rhs) = default;                         // move constructor
  //Maze& Maze::operator=(Maze&& rhs ) = default;             // move assignment


  void printMaze() {
    std::cout << "maze::printMaze" << std::endl;
  }
  //
  // SharedResource& Maze::get_SharedResource(){
  //   return m_SharedResource*;
  // }
  //
  // const std::string& Maze::get_string(){
  //   return mString;
  // }

} // namespace maze

