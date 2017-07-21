
#include "maze/base.h"
#include <iostream>
namespace maze {
void testfunction() { std::cout << "testfunction ran" << std::endl; }
void printMaze() { std::cout << "maze::printMaze" << std::endl; }

std::map<Direction, Direction> opposite_direction{
    std::make_pair(Direction::LEFT, Direction::RIGHT),
    std::make_pair(Direction::RIGHT, Direction::LEFT),
    std::make_pair(Direction::UP, Direction::DOWN),
    std::make_pair(Direction::DOWN, Direction::UP)};

}
