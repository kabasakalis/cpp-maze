
#pragma once

#include <maze/maze_api.h>
#include <array>
#include <iostream>
#include <map>
#include <vector>

namespace maze {
class Room;  // forward declaration

const int ROWS_MIN = 1;
const int ROWS_MAX = 38;
const int COLUMNS_MIN = 1;
const int COLUMNS_MAX = 73;

enum Direction { LEFT, RIGHT, UP, DOWN };
enum Mode { BUILD, SOLVE };

const std::vector<Direction> DIRECTIONS{
    {Direction::LEFT, Direction::RIGHT, Direction::UP, Direction::DOWN}};

const extern std::map<Direction, Direction> opposite_direction;

class Position {
 public:
  int x, y;
  // friend bool operator==(const maze::Position&, const maze::Position&);
  // friend bool operator!=(const maze::Position&, const maze::Position&);
};

MAZE_API  bool operator==(const maze::Position&, const maze::Position& rhs);
MAZE_API  bool operator!=(const maze::Position&, const maze::Position& rhs);

MAZE_API extern void logDirVector(const std::vector<Direction>&, std::string);
}  // namespace maze

MAZE_API std::ostream& operator<<(std::ostream& stream, const maze::Position&);
MAZE_API std::ostream& operator<<(std::ostream& stream, const maze::Room&);
MAZE_API std::ostream& operator<<(std::ostream& stream, const maze::Direction);

#include "maze/utils.h"
