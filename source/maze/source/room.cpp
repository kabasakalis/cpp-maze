
//#include <memory>  // unique_ptr
#include "maze/room.h"

namespace maze {

  // Default constructor
  Room::Room() {}

  // Constructor
   Room::Room(const Position& t_position)
    : _position{t_position}
    { _x =  _position.x ;  _y = _position.y ; }
  // Special Member functions

  //virtual Room()::~Room() = default                   // dtor
  //Room::Room(const Room& rhs) = default;                   // copy constructor
  //Room& Room::operator=(const Room& rhs) = default;         // copy assignment
  //Room::Room(Room&& rhs) = default;                         // move constructor
  //Room& Room::operator=(Room&& rhs ) = default;             // move assignment


  // Member functions

    // Getters
   const Position& Room::position() const { return _position; };
   const int& Room::x() const { return _x;}
   const int& Room::y() const { return _y;}
   const std::vector<Direction>& Room::visits_from() const {return _visits_from;}
   const std::vector<Direction>& Room::available_exits() const {return _available_exits;}
   const std::vector<Direction>& Room::used_exits() const { return _used_exits;}


}  // namespace room
