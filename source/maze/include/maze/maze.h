#pragma once
#include <maze/maze_api.h>
#include <string>
#include <vector>
#include "maze/room.h"
#include <boost/optional.hpp>

namespace maze {

class MAZE_API Maze final {
  public:
    explicit Maze( int rows = 10, int columns = 10);             // constructor
      // MAZE_API boost::optional<Room> find_room(Position&  position) const;
      boost::optional< Room>
      find_room(const Position& position) const;

      boost::optional< Room>
      find_room(int x, int y) const ;

      bool all_rooms_visited() const;

      const std::vector<Room>& rooms() const;
      const int& rows() const;
      const int& columns() const;
  private:
    std::vector<Room> _rooms;
    int _rows;
    int _columns;
  };

}  // namespace maze
