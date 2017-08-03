#pragma once
#include <maze/maze_api.h>
#include <string>
#include <vector>
#include "maze/room.h"
#include <boost/optional.hpp>
#include <functional>   // std::reference_wrapper

namespace maze {

  // typedef std::vector<std::reference_wrapper<Room>> Rooms;
  // typedef std::reference_wrapper<Room> RoomRef;


class MAZE_API Maze final {
  public:
    explicit Maze( int rows = 10, int columns = 10);             // constructor


      // MAZE_API boost::optional<Room> find_room(Position&  position) const;
      boost::optional< Room*>
      find_room(const Position& position) const;


      boost::optional< Room*>
      fr(const Position& position);


      boost::optional< Room*>
      find_room(int x, int y) ;

      bool all_rooms_visited() const;

      std::vector<Room>& rooms() ;
      // std::vector<Room>& rooms();

      // Rooms rooms();

      const int& rows() const;
      const int& columns() const;
      std::vector<Room> _rooms;
  private:
    int _rows;
    int _columns;
  };

}  // namespace maze
