
#include "maze/room.h"
#include <algorithm>
#include <boost/range/adaptor/map.hpp>
#include <boost/range/algorithm/copy.hpp>
#include <iostream>
#include "maze/base.h"

using namespace utils;

namespace maze {

// Default constructor
Room::Room() {}

// Constructor
Room::Room(const Position& t_position) : _position{t_position} {
  _x = _position.x;
  _y = _position.y;
}

const Position& Room::position() const { return _position; };
const int& Room::x() const { return _x; }
const int& Room::y() const { return _y; }
std::vector<Direction>& Room::visits_from() { return _visits_from; }
std::vector<Direction>& Room::available_exits() { return _available_exits;}
std::vector<Direction>& Room::used_exits() { return _used_exits; }
bool Room::is_exit_free(const Direction& exit) const {
  if (std::find(_available_exits.begin(), _available_exits.end(), exit) !=
      _available_exits.end()) {
    return true;
  } else {
    return false;
  }
}
bool Room::visited() const { return !_visits_from.empty() ? true : false; }

const std::map<long, std::vector<Direction>>
Room::times_used_to_exits() const {
  std::map<long, std::vector<Direction>> times_used_to_exits;
  for (auto direction : _available_exits) {
    auto cnt = count(_used_exits.begin(), _used_exits.end(), direction);
    times_used_to_exits[cnt].push_back(direction);
  };
  return times_used_to_exits;
}

std::vector<Direction> Room::less_used_available_exits() {
  std::vector<long> frequencies;
  boost::copy(Room::times_used_to_exits() | boost::adaptors::map_keys,
              std::back_inserter(frequencies));
  auto less_used_frequency =
      *std::min_element(frequencies.begin(), frequencies.end());
  return times_used_to_exits().at(less_used_frequency);
}

boost::optional<std::vector<Direction>> Room::unused_available_exits() {
  auto _times_used_to_exits = times_used_to_exits();
  auto it = _times_used_to_exits.find(0);
  if (it != _times_used_to_exits.end()) {
    return it->second;
  }
  return boost::none;
}

}  // namespace room
