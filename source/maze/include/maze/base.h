#pragma once

#include <maze/maze_api.h>
#include <map>
namespace maze {

 const int ROWS_MIN = 1;
 const int  ROWS_MAX = 40;
 const int COLUMNS_MIN = 1;
 const int COLUMNS_MAX = 73;
 const int CANVAS_SLEEP_MAX = 1.0;


MAZE_API void printMaze();
MAZE_API void testfunction();

enum Direction { LEFT, RIGHT, DOWN, UP };
std::map< Direction, Direction > opposite_direction {
  std::make_pair(Direction::LEFT, Direction::RIGHT),
  std::make_pair(Direction::RIGHT, Direction::LEFT),
  std::make_pair(Direction::UP, Direction::DOWN),
  std::make_pair(Direction::DOWN, Direction::UP)
};

}  // namespace maze

