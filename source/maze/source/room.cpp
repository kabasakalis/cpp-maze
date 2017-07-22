
#include "maze/room.h"
#include <memory>  // unique_ptr

#include <algorithm>
#include <boost/range/adaptor/map.hpp>
#include <boost/range/algorithm/copy.hpp>
#include <iostream>
namespace maze {

// Default constructor
Room::Room() {}

// Constructor
Room::Room(const Position& t_position) : _position{t_position} {
  _x = _position.x;
  _y = _position.y;
}
// Special Member functions

// virtual Room()::~Room() = default                   // dtor
// Room::Room(const Room& rhs) = default;                   // copy constructor
// Room& Room::operator=(const Room& rhs) = default;         // copy assignment
// Room::Room(Room&& rhs) = default;                         // move constructor
// Room& Room::operator=(Room&& rhs ) = default;             // move assignment

// Member functions

// Getters
const Position& Room::position() const { return _position; };
const int& Room::x() const { return _x; }
const int& Room::y() const { return _y; }
const std::vector<Direction>& Room::visits_from() const { return _visits_from; }
const std::vector<Direction>& Room::available_exits() const {
  return _available_exits;
}
const std::vector<Direction>& Room::used_exits() const { return _used_exits; }

bool Room::is_exit_free(const Direction& exit) const {
  if (std::find(_available_exits.begin(), _available_exits.end(), exit) !=
      _available_exits.end()) {
    return true;
  } else {
    return false;
  }
}

bool Room::visited() const { return !_visits_from.empty() ? true : false; }

// def times_used_to_exits
//   available_exits.group_by do |exit|
//     used_exits.count(exit)
//   end
// end
const std::map<long, std::vector<Direction>> Room::times_used_to_exits() const {
  std::map<long, std::vector<Direction>> times_used_to_exits;
  for (auto direction : _available_exits) {
    auto cnt = count(_used_exits.begin(), _used_exits.end(), direction);
    times_used_to_exits[cnt].push_back(direction);
  };
  return times_used_to_exits;
}

std::vector<Direction> Room::less_used_available_exits() {
  std::vector<long> keys;
  // Retrieve all keys
  boost::copy(Room::times_used_to_exits() | boost::adaptors::map_keys,
              std::back_inserter(keys));

  auto less_used_frequency = *std::min_element(keys.begin(), keys.end());
  auto tmo = times_used_to_exits();
  return tmo[less_used_frequency];
}

}  // namespace room
