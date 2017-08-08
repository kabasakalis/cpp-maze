
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

  boost::optional<Room*> find_room(const Position& position) const;
  boost::optional<Room*> find_room(int x, int y);
  std::vector<Room>& rooms();
  const int& rows() const;
  const int& columns() const;
  bool all_rooms_visited() const;

 private:
  int _columns;
  int _rows;
  std::vector<Room> _rooms;
};

}  // namespace maze
