
#pragma once

#include <maze/maze_api.h>
#include "maze/base.h"
#include "maze/builder.h"

namespace maze {

class MAZE_API Solver : public Builder {
 public:
  explicit Solver(const Maze& maze, const Position& starting_position,
                  const Position& goal_position);

  MAZE_API void solve_maze();

 private:
  boost::optional<Direction> use_smart_strategy_to_choose_next_forward_move();
  boost::optional<Direction> look_for_exit_leading_to_goal_in_next_room();
  void reset_maze();
  Position _starting_position;
  Position _goal_position;
};

}  // namespace maze
