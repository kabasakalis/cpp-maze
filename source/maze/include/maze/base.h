#pragma once

#include <maze/maze_api.h>
#include <map>
#include <ostream>
// #include "maze/room.h"
namespace maze {
class Room; //forward declaration

const int ROWS_MIN = 1;
const int ROWS_MAX = 40;
const int COLUMNS_MIN = 1;
const int COLUMNS_MAX = 73;
const int CANVAS_SLEEP_MAX = 1.0;

enum Direction { LEFT, RIGHT, DOWN, UP };
// std::map<Direction, Direction> opposite_direction;

struct Position {int x; int y;};

MAZE_API void printMaze();
MAZE_API void testfunction();



}  // namespace maze

MAZE_API  std::ostream& operator<< (std::ostream& stream, const maze::Position&);
MAZE_API  std::ostream& operator<< (std::ostream& stream, const maze::Room&);

