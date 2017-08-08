
#pragma once
#include <maze/maze_api.h>
#include <boost/optional.hpp>
#include <functional>  // std::reference_wrapper
#include <string>
#include <vector>
#include "maze/room.h"

namespace maze {

class MAZE_API Maze final {
 public:
  explicit Maze(int rows = 10, int columns = 10);  // constructor

  MAZE_API boost::optional<Room*> find_room(const Position& position) const;
  MAZE_API boost::optional<Room*> find_room(int x, int y);
  MAZE_API std::vector<Room>& rooms();
  MAZE_API const int& rows() const;
  MAZE_API const int& columns() const;
  MAZE_API bool all_rooms_visited() const;

 private:
  int _columns;
  int _rows;
  std::vector<Room> _rooms;
};

}  // namespace maze
