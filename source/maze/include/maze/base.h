#pragma once

#include <maze/maze_api.h>
#include <array>
#include <map>
#include <iostream>
#include <vector>
namespace maze {
class Room;  // forward declaration

const int ROWS_MIN = 1;
const int ROWS_MAX = 40;
const int COLUMNS_MIN = 1;
const int COLUMNS_MAX = 73;
const int CANVAS_SLEEP_MAX = 1.0;

enum Direction { LEFT, RIGHT, UP, DOWN };
const std::vector<Direction> DIRECTIONS{
    {Direction::LEFT, Direction::RIGHT, Direction::UP, Direction::DOWN}};

class Position {
  public:
  int x, y;

friend bool operator==(const maze::Position&, const maze::Position&);
friend bool operator!=(const maze::Position&, const maze::Position&);

};


// std::map<Direction, Direction> opposite_direction;


MAZE_API void printMaze();
MAZE_API void testfunction();
MAZE_API void logDirVector(const std::vector<Direction>&, std::string);


}  // namespace maze



MAZE_API bool maze::operator==(const maze::Position& , const maze::Position& rhs) ;
MAZE_API std::ostream& operator<<(std::ostream& stream, const maze::Position&);
MAZE_API std::ostream& operator<<(std::ostream& stream, const maze::Room&);
MAZE_API std::ostream& operator<<(std::ostream& stream, const maze::Direction);

#include "maze/utils.h"
