#pragma once

#include <maze/maze_api.h>
#include <map>
namespace maze {

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
