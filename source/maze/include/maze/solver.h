
#pragma once

#include <maze/maze_api.h>

namespace maze {

class MAZE_API Solver : public  Builder {
  public:
    explicit Solver( const Maze& maze,
        const Position& starting_position,
        const Position& goal_position );

      // maze.rooms.each { |room| room.visits_from = [] }

    //reset _path
    //reset _visited positions

       } ; // constructor

    // def initialize(options)
    //   @maze = options[:maze]
    //   @starting_position = options[:starting_position]
    //   @goal_position = options[:goal_position]
    //   @path = [@starting_position]
    //   @visited_positions = @path.dup
    // end

    // Special member functions, consider cases.
    // 1. Rule Of Zero (If applies)
    // Don't declare or default any special member function.
    // 2. Base class to inherit from.
    // Uncomment dtor for virtual destructor, default the rest special members below,
    // remove final from class declaration.

    //virtual ~Solver();                               // dtor
    //Solver(const Solver& rhs);                         // copy constructor
    //Solver& operator=(const Solver& rhs);              // copy assignment
    //Solver(Solver&& rhs);                              // move constructor
    //Solver& operator=(Solver&& rhs );                  // move assignment


    //Member functions

  //Builder overrides
  // virtual  boost::optional<Position> current_position() const override;
  // virtual  boost::optional<Position> previous_position() const override;
  // virtual  void go_back_to_previous_visited_room() override;
  //
  // virtual  boost::optional<Room*> room(const Position&) const override;
  // virtual boost::optional<Room*> current_room() override;
  // virtual boost::optional<const Position> next_position(const Direction&,
  //                                                      const Position&) const override;
  //


  MAZE_API boost::optional<Direction> use_smart_strategy_to_choose_next_forward_move() const;
  MAZE_API boost::optional<Direction> look_for_exit_leading_to_goal_in_next_room() const;
  MAZE_API void solve_maze();

  private:
    void reset_maze();
    Position  _starting_position;
    Position  goal_position;
};

}  // namespace solver

//#endif /*  */
