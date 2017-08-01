
#include "maze/solver.h"
#include <boost/optional/optional_io.hpp>
#include "maze/base.h"

namespace maze {

// Constructor
Solver::Solver(std::string string_)
    : _maze(maze),
      _starting_position{starting_position},
      _goal_position{goal_position} {}
// Special Member functions

// virtual Solver()::~Solver() = default                   // dtor
// Solver::Solver(const Solver& rhs) = default;                   // copy
// constructor
// Solver& Solver::operator=(const Solver& rhs) = default;         // copy
// assignment
// Solver::Solver(Solver&& rhs) = default;                         // move
// constructor
// Solver& Solver::operator=(Solver&& rhs ) = default;             // move
// assignment

// Member functions
Solver::reset_maze() {
  for (Room& room : _maze.rooms()) {
    room.visits_from().clear();
  }
  _path.reset();
  _visited_positions.reset();
  _path.push_back(_starting_position);
  _visited_positions.push_back(_starting_position);
}

// def use_smart_strategy_to_choose_next_forward_move
//   look_for_exit_leading_to_goal_in_next_room ||
//     current_room.less_used_available_exits.detect { |exit| exit !=
//     current_room.visits_from.last }
// end

boost::optional<Direction>
Solver::use_smart_strategy_to_choose_next_forward_move() const {
  auto goal_position_ = look_for_exit_leading_to_goal_in_next_room();
  if (goal_position_ != boost::none) return goal_position_;

  auto& current_room_less_used_available_exits_ =
      current_room().less_used_available_exits();

  auto exit_iter =
      std::find_if(current_room_less_used_available_exits_.begin(),
                   current_room_less_used_available_exits_.end(),
                   [this](Direction exit) mutable -> bool {
                     return (exit != current_room().visits_from().back());
                   });
  if (exit_iter != current_room_less_used_available_exits_.end())
    return *exit_iter;
  return boost::none;
}

// def look_for_exit_leading_to_goal_in_next_room
//    current_room.available_exits.find { |exit| send("room_#{exit}").position
//    == goal_position }
//  end

boost::optional<Direction> Solver::look_for_exit_leading_to_goal_in_next_room()
    const {
  auto& available_exits_ = current_room().available_exits();
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

// def solve_maze
//       self.class.log.info 'Maze is now being solved,please wait.'
//       reset_rooms_visits_from
//       until current_position == goal_position
//         if use_smart_strategy_to_choose_next_forward_move
//           next_direction = use_smart_strategy_to_choose_next_forward_move
//           next_room = send "room_#{next_direction}"
//           current_room.used_exits << next_direction
//           path << next_room.position
//           visited_positions << next_room.position
//           next_room.visits_from << OPPOSITE_DIRECTION[next_direction]
//         else # go back
//           go_back_to_previous_visited_room
//           path << current_room.position
//         end
//       end
//
//       self.class.log.info "Solver Path:   #{path.map { |p| [p.x, p.y]
//       }.inspect}"
//       self.class.log.info "Maze Solved after #{path.size} steps"
//     end

void Solver::solve_maze() {
  logVar("", "Maze is now being solved, please wait.");
  reset_maze();
  while ( *(current_position()) != _goal_position) {
    auto current_position_ = current_position();
    auto current_room_ = current_room();

    if (use_smart_strategy_to_choose_next_forward_move() != boost::none) {
      auto next_direction_ =
          *(use_smart_strategy_to_choose_next_forward_move());

      auto next_position_ =
          (current_position_ != boost::none)
              ? next_position(next_direction_, *current_position_)
              : boost::none;
      auto  next_room_ =
          (next_position_ != boost::none) ? room(*next_position_) : boost::none;

      (**current_room_).used_exits().push_back(next_direction_);
      _path.push_back((**next_room_).position());
      _visited_positions.push_back((**next_room_).position());
      (**next_room_).visits_from().push_back(
          maze::opposite_direction.at(next_direction_));

    } else {
      logVar("", "GOING BACK");
      go_back_to_previous_visited_room();
      _path.push_back((**current_room()).position());
    };  // if

  };  // while

  logVar("", "Maze solved in :");
  logVar(_path.size(), " steps: ");
}

}  // namespace maze
