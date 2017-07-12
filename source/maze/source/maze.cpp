
#include <iostream>
#include <fstream>
#include <maze/maze-version.h>


#include <maze/maze.h>

namespace maze {


Maze::Maze(){

}

Maze::~Maze(){

}


int Maze::returnOne(){ return 1; }

void printMaze(){
    // Library name
    std::cout << "========================================" << std::endl;
    std::cout << "mylib::printMaze" << std::endl;
}

} // namespace cppmaze
