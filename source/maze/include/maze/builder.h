#pragma once
#include <functional>  // std::reference_wrapper
#include <vector>
#include "maze/base.h"
#include "maze/maze.h"
namespace maze {

class MAZE_API Builder {
  typedef std::vector<std::reference_wrapper<Room>> Rooms;
  typedef std::reference_wrapper<Room> RoomRef;
 public:

  explicit Builder();             // default constructor
  explicit Builder(const Maze&);  // constructor
  virtual ~Builder() = default;   // dtor

  void build_maze();
  virtual const Maze& maze() const;
  virtual const std::vector<Position>& path() const;

 protected:
  virtual boost::optional<const Position> next_position(const Direction&,
                                                        const Position&) const;
  virtual boost::optional<Room*> current_room();
  virtual boost::optional<Room*> room(const Position&) const;
  virtual void go_back_to_previous_visited_room();
  virtual boost::optional<Position> previous_position() const;
  virtual boost::optional<Position> current_position() const;
  Maze _maze;
  std::vector<Position> _path;
  std::vector<Position> _visited_positions;

 private:
  boost::optional<Direction> determine_direction(const Room& next_room) const;
  Rooms valid_rooms_to_build() const;
  void build_room(Room& a_room, const Direction& exit_to_free);
};

}  // namespace maze
