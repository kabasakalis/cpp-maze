
#pragma once

#include <maze/maze_api.h>
#include <vector>
#include <map>
#include "maze/base.h"
#include <boost/optional.hpp>

namespace maze {

class MAZE_API Room final {
 public:
  explicit Room();
  explicit Room(const Position& t_position);  // constructor

   const int& x() const;
   const int& y() const;
   const Position& position() const;
   std::vector<Direction>& visits_from();
   std::vector<Direction>& available_exits();
   std::vector<Direction>& used_exits() ;
   bool is_exit_free(const Direction& ) const;
   bool visited() const;
   const std::map<long, std::vector<Direction>> times_used_to_exits() const;
   std::vector<Direction> less_used_available_exits();
   boost::optional<std::vector<Direction>>  unused_available_exits();

 private:
  int _x;
  int _y;
  std::vector<Direction> _visits_from;
  std::vector<Direction> _used_exits;
  std::vector<Direction> _available_exits;
  Position _position;
};

}  // namespace room
