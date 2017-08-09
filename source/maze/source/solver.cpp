
#include <chrono>
#include "maze/solver.h"
#include <boost/optional/optional_io.hpp>
#include <vector>
#include "maze/base.h"
#include "maze/builder.h"
namespace maze {

// Default constructor
Solver::Solver(){};

// Constructor
Solver::Solver(const Maze& maze, const Position& starting_position,
               const Position& goal_position)
    : _starting_position{starting_position}, _goal_position{goal_position} {
  _maze = maze;
}

void Solver::reset_maze() {
  for (Room& room : _maze.rooms()) {
    room.visits_from().clear();
  }
  _path.clear();
  _visited_positions.clear();
  _path.push_back(_starting_position);
  _visited_positions.push_back(_starting_position);
}

boost::optional<Direction>
Solver::use_smart_strategy_to_choose_next_forward_move() {
  auto goal_position_ = look_for_exit_leading_to_goal_in_next_room();
  if (goal_position_ != boost::none) return *goal_position_;

  auto current_room_ = current_room();
  auto current_room_less_used_available_exits_ =
      (**current_room_).less_used_available_exits();

  auto exit_iter =
      std::find_if(current_room_less_used_available_exits_.begin(),
                   current_room_less_used_available_exits_.end(),
                   [this, current_room_](Direction exit) mutable -> bool {
                     return (exit != (**current_room_).visits_from().back());
                   });
  if (exit_iter != current_room_less_used_available_exits_.end())
    return *exit_iter;
  return boost::none;
}

boost::optional<Direction>
Solver::look_for_exit_leading_to_goal_in_next_room() {
  auto current_room_ = current_room();
  auto& available_exits_ = (**current_room_).available_exits();
  auto exit_iter =
      std::find_if(available_exits_.begin(), available_exits_.end(),
                   [this](Direction exit) mutable -> bool {

                     const auto& current_position_ = current_position();
                     const auto& next_position_ =
                         (current_position_ != boost::none)
                             ? next_position(exit, *current_position_)
                             : boost::none;
                     auto room_to_exit = (next_position_ != boost::none)
                                             ? room(*next_position_)
                                             : boost::none;
                     return (room_to_exit != boost::none &&
                             (**room_to_exit).position() == _goal_position);
                   });

  if (exit_iter != available_exits_.end()) return *exit_iter;
  return boost::none;
}

void Solver::solve_maze() {
  reset_maze();
  printf("Started solving  maze of %lu rooms.\n", _maze.rooms().size());
  auto start = std::chrono::high_resolution_clock::now();
  while (*(current_position()) != _goal_position) {
    auto current_position_ = current_position();
    auto current_room_ = current_room();

    if (use_smart_strategy_to_choose_next_forward_move() != boost::none) {
      auto next_direction_ =
          *(use_smart_strategy_to_choose_next_forward_move());

      auto next_position_ =
          (current_position_ != boost::none)
              ? next_position(next_direction_, *current_position_)
              : boost::none;
      auto next_room_ =
          (next_position_ != boost::none) ? room(*next_position_) : boost::none;

      (**current_room_).used_exits().push_back(next_direction_);
      _path.push_back((**next_room_).position());
      _visited_positions.push_back((**next_room_).position());
      (**next_room_)
          .visits_from()
          .push_back(maze::opposite_direction.at(next_direction_));

    } else {
      go_back_to_previous_visited_room();
      _path.push_back((**current_room()).position());
    };  // if

  };  // while

  auto end = std::chrono::high_resolution_clock::now();
  auto execution_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  printf("Maze solved in %lu steps, %lu.%lu seconds. \n", _path.size(), execution_time/1000, execution_time%1000 );
}

}  // namespace maze
