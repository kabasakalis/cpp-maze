
#include <iostream>

#include <baselib/baselib.h>
#include "maze/base.h"
#include "maze/room.h"

#include <boost/optional/optional_io.hpp>
// #include "maze/utils.h"
using namespace maze;
using namespace utils;

int main(int /*argc*/, char * /*argv*/ []) {
  baselib::printInfo();
   // Main
  std::cout << "========================================" << std::endl;
  std::cout << "Main" << std::endl;
  std::cout << std::endl;
  // printMaze();
  // testfunction();
  std::vector<int> v{1,4,5,68,9899,898};
  std::map<std::string, int> m{{"Spiros", 444}, {"Apostolia", 555}};

  Position p{10, 20};
  Position p2{23, 45};
  Room r{p};
  Room r2{p2};
  r._visits_from = {Direction::LEFT, Direction::LEFT, Direction::RIGHT,
    Direction::UP, Direction::UP, Direction::UP, Direction::UP};
  r._available_exits = {Direction::LEFT, Direction::RIGHT, Direction::UP, Direction::DOWN};
  r._used_exits = { Direction::RIGHT, Direction::RIGHT,
    Direction::LEFT, Direction::UP,    Direction::UP};
    // Direction::DOWN, Direction::DOWN, Direction::DOWN, Direction::DOWN};

  auto times_used_to_exits = r.times_used_to_exits();
  std::vector<Room> vr{r, r2};
  // log(vr,"Vector of Rooms");
  std::cout << r2 << std::endl;

  logVar(p, "Point Test");
  logVar(r, "Room Test");
  logVar(Direction::UP,"Dire");
  logDirVector(DIRECTIONS, "DIRECTION");

  // log(times_used_to_exits, "times used");

  logDirVector(r._used_exits, "USED EXITS");
  logDirVector(r._visits_from,  "VISITS FROM");
  auto luae  = r.less_used_available_exits();

  logDirVector(luae, "LES USED DIRECTIONS");

  std::cout << r.times_used_to_exits().at(0)[0]<< std::endl;
  // logDirVector(r.unused_available_exits(), "UNUSED AVAILA");
if( r.unused_available_exits() != boost::none){

boost::optional<std::vector<Direction>> a = r.unused_available_exits();
  std::vector<Direction> v = *a;
  logDirVector( v,  "UNUSED AVAILAVLE");
  logVar(v.at(0),  "FIRST UNUSED");
  // std::cout << v[2];
  logVar(r.unused_available_exits()->size(),  "SIZE UNUSED AVAILAVLE");

   std::cout << r.unused_available_exits()->at(0)<< std::endl;
   std::cout << r.unused_available_exits()->front()<< std::endl;
   // auto it = r.times_used_to_exits().find(0);
   // std::cout << (it != r.times_used_to_exits().end())<< std::endl;
   // std::cout << boost::none;
   // std::cout << r.unused_available_exits()->kl1<< std::endl;
}else {

  logVar( "asdf", "");
};

// logDirVector(r.times_used_to_exits().at(0), "");

  // std::cout << r.unused_available_exits()<< std::endl;


  return 0;
}
