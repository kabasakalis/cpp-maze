#pragma once
#include <maze/maze_api.h>
#include <string>
#include <vector>
#include "maze/room.h"
#include <boost/optional.hpp>

namespace maze {

class MAZE_API Maze final {
  public:
    explicit Maze( int rows, int columns);             // constructor
      MAZE_API boost::optional<Room> find_room(Position&  position) const;
      MAZE_API const Room& find_room(int x, int y) const ;
      MAZE_API bool all_rooms_visited() const;
  private:
    std::vector<Room> rooms;
    std::int rows;
    std::int columns;
  };

}  // namespace maze
