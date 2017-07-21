
#pragma once
//#ifndef ROOM_H
//#define ROOM_H

//#include <memory>  // unique_ptr
#include <maze/maze_api.h>
#include <vector>
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






    // DIRECTIONS.each do |exit|
    //   define_method "#{exit}?" do
    //     return true if available_exits.include?(exit)
    //     return false
    //   end
    // end
    //
    // def visited?
    //   !visits_from.empty?
    // end
    //
    // def times_used_to_exits
    //   available_exits.group_by do |exit|
    //     used_exits.count(exit)
    //   end
    // end
    //
    // def less_used_available_exits
    //   times_used_to_exits[times_used_to_exits.keys.min]
    // end
    //
    // def unused_available_exits
    //   times_used_to_exits[0] || []
    // end

 private:
  int _x;
  int _y;
  Position _position;
  std::vector<Direction> _visits_from;
  std::vector<Direction> _available_exits;
  std::vector<Direction> _used_exits;
};

}  // namespace room

//#endif /* ROOM_H */
