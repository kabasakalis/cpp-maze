#pragma once
#include <vector>
#include "maze/maze.h"
#include "maze/base.h"
#include <functional>   // std::reference_wrapper
namespace maze {

class MAZE_API Builder {
 public:
  typedef std::vector<std::reference_wrapper<Room>> Rooms;
  typedef std::reference_wrapper<Room> RoomRef;

  explicit Builder();  // default constructor
  explicit Builder(const Maze&);  // constructor

  virtual ~Builder() = default;                    // dtor
  // Builder(const Builder& rhs) = delete;         // copy constructor
  // Builder& operator=(const Builder& rhs) = delete;  // copy assignment
  // Builder(Builder&& rhs) = delete;                  // move constructor
  // Builder& operator=(Builder&& rhs) = delete;       // move assignment

  // Member functions
 void build_maze();
//  private:

  virtual  boost::optional<Position> current_position() const;
  virtual  boost::optional<Position> previous_position() const;
  virtual  void go_back_to_previous_visited_room();

  virtual  boost::optional<Room*> room(const Position&) const;
  virtual boost::optional<Room*> current_room();
  virtual boost::optional<const Position> next_position(const Direction&,
                                                       const Position&) const;
  virtual const Maze& maze() const;
  virtual const std::vector<Position>& path() const;
  // MAZE_API boost::optional< Room> room_to_left() const;
  // MAZE_API boost::optional< Room> room_to_right() const;
  // MAZE_API boost::optional< Room> room_to_up() const;
  // MAZE_API boost::optional< Room> room_to_down() const;

  boost::optional<Direction> determine_direction(const Room& next_room) const;
  MAZE_API Rooms valid_rooms_to_build() const;
  MAZE_API void  build_room( Room& a_room, const Direction& exit_to_free);

  MAZE_API int _random_integer(int upper, int lower) const;

//  protected:
  Maze _maze;
  std::vector<Position> _path;
  std::vector<Position> _visited_positions;

};

}  // namespace maze
