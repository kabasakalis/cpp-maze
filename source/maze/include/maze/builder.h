#pragma once
#include <vector>
#include "maze/maze.h"
namespace maze {

class MAZE_API Builder {
 public:
  explicit Builder(const Maze&);  // constructor

  virtual Builder()::~Builder() = default                    // dtor
      Builder::Builder(const Builder& rhs) = delete;         // copy constructor
  Builder& Builder::operator=(const Builder& rhs) = delete;  // copy assignment
  Builder::Builder(Builder&& rhs) = delete;                  // move constructor
  Builder& Builder::operator=(Builder&& rhs) = delete;       // move assignment

  // Member functions
 void build_maze();
 private:
  Maze _maze;
  std::vector<Position> _path;
  std::vector<Position> _visited_positions;

  auto current_position() const;
  auto previous_position() const;
  void go_back_to_previous_visited_room() const;

  MAZE_API boost::optional<std::vector<Room>> room(const Position&) const;
  MAZE_API boost::optional<std::vector<Room>> current_room(const Position&) const;
  MAZE_API boost::optional<std::vector<Position>> next_position(const Direction&,
                                                       const Position&) const;

  MAZE_API boost::optional<std::vector<Room>> room_to_left() const;
  MAZE_API boost::optional<std::vector<Room>> room_to_right() const;
  MAZE_API boost::optional<std::vector<Room>> room_to_up() const;
  MAZE_API boost::optional<std::vector<Room>> room_to_down() const;

  MAZE_API boost::optional<Direction>> determine_direction(const Room& next_room) const;
  MAZE_API std::vector<Room> valid_rooms_to_build() const;
  MAZE_API void  build_room( Room& a_room, const Direction& exit_to_free);

  MAZE_API const int _random_integer(int upper, int lower) const;
};

}  // namespace maze
