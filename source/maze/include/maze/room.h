
#pragma once
//#ifndef ROOM_H
//#define ROOM_H

#include <memory>  // unique_ptr
#include <maze/maze_api.h>
#include <vector>
#include <map>
#include "maze/base.h"
namespace maze {

class MAZE_API Room final {
 public:
  explicit Room();
  explicit Room(const Position& t_position);  // constructor

  // Getter functions

  const Position& position() const;
  MAZE_API const int& x() const;
  MAZE_API const int& y() const;
  MAZE_API const std::vector<Direction>& visits_from() const;
  MAZE_API const std::vector<Direction>& available_exits() const;
  MAZE_API const std::vector<Direction>& used_exits() const;
  MAZE_API bool is_exit_free(const Direction& ) const;
  MAZE_API bool visited() const;
  MAZE_API const std::map<long, std::vector<Direction>> times_used_to_exits() const;
  MAZE_API std::vector<Direction> less_used_available_exits() ;




  // def less_used_available_exits
  //   times_used_to_exits[times_used_to_exits.keys.min]
  // end
  //
  // def unused_available_exits
  //   times_used_to_exits[0] || []
  // end

  std::vector<Direction> _visits_from;
  std::vector<Direction> _used_exits;
  std::vector<Direction> _available_exits;
 private:
  int _x;
  int _y;
  Position _position;
};

}  // namespace room

//#endif /* ROOM_H */
