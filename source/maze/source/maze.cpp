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
#include "boost/multi_array.hpp"
#include <cassert>
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

    // Create a 3D array that is 3 x 4 x 2
  typedef boost::multi_array<double, 3> array_type;
  typedef array_type::index index;
  array_type A(boost::extents[3][4][2]);

  // Assign values to the elements
  int values = 0;
  for(index i = 0; i != 3; ++i)
    for(index j = 0; j != 4; ++j)
      for(index k = 0; k != 2; ++k)
        A[i][j][k] = values++;

  // Verify values
  int verify = 0;
  for(index i = 0; i != 3; ++i)
    for(index j = 0; j != 4; ++j)
      for(index k = 0; k != 2; ++k)
        // assert(A[i][j][k] == verify++);
        std::cout << "Multiarray element at" << i << j << k << ": " << A[i][j][k]  << std::endl;
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

