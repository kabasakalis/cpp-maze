#pragma once

#include <maze/maze_api.h>
#include <map>
namespace maze {

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

