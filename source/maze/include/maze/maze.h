#pragma once
//#ifndef MAZE_H
//#define MAZE_H

//#include <memory>  // unique_ptr
#include <maze/maze_api.h>
#include <string>
namespace maze {

class MAZE_API Maze final {
  public:
    explicit Maze();                                 // default constructor
    explicit Maze( const std::string );             // constructor

    //virtual ~Maze();                               // dtor
    //Maze(const Maze& rhs);                         // copy constructor
    //Maze& operator=(const Maze& rhs);              // copy assignment
    //Maze(Maze&& rhs);                              // move constructor
    //Maze& operator=(Maze&& rhs );                  // move assignment

    //Member functions

    MAZE_API int returnOne();

  private:
    std::string mString;
  };


}  // namespace maze

//#endif /* MAZE_H */
