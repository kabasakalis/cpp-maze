
#include <iostream>

#include <baselib/baselib.h>
#include "maze/base.h"
#include "maze/room.h"
using namespace maze;

int main(int /*argc*/, char * /*argv*/ []) {
  baselib::printInfo();
  std::cout << "========================================" << std::endl;
  printMaze();
  testfunction();
  Position p{10, 20};
  Room r{p};

  std::cout << "p x: " << p.x << std::endl;
  std::cout << "p y: " << p.y << std::endl;
  std::cout << "room p x: " << r.position().x << std::endl;
  std::cout << "room p y: " << r.position().y << std::endl;
  std::cout << "room x: " << r.x() << std::endl;
  std::cout << "room y: " << r.y() << std::endl;
  std::cout << p << std::endl;
  std::cout << r << std::endl;

  r._visits_from = {Direction::LEFT, Direction::LEFT, Direction::RIGHT,
                    Direction::UP};
  r._available_exits = {Direction::LEFT, Direction::RIGHT, Direction::UP, Direction::DOWN};
  r._used_exits = { Direction::RIGHT, Direction::RIGHT,
                   Direction::LEFT, Direction::UP,    Direction::UP,
                   Direction::DOWN, Direction::DOWN, Direction::DOWN, Direction::DOWN};

  auto times_used_to_exits = r.times_used_to_exits();
  //
  for (const auto &te : times_used_to_exits) {
    std::cout << "times_used_to_exits[" << te.first << "]" <<'\n';
    for (const auto &k : te.second) {
      std::cout << k << std::endl;
    }
  }

  auto luae  = r.less_used_available_exits();

   std::cout << "LESS USED AVAIL ECITS" <<  std::endl;
 for (const auto &k : luae ) {
   std::cout << k <<  std::endl;
    }


  // std::cout << "ocuurrences of left "<< m[Direction::LEFT] << std::endl;
  // std::cout << "ocuurrences of right "<< m[Direction::RIGHT] << std::endl;
  // std::cout << "ocuurrences of up "<< m[Direction::UP] << std::endl;
  //  std::cout << r <<  std::endl;
  // std::cout << ROWS_MAX << std::endl;
  // std::cout <<  Directions::LEFT<< std::endl;
  // std::cout <<  int(Direction::UP)<< std::endl;
  // std::cout <<  opposite_direction[Direction::LEFT]<< std::endl;
  // std::cout <<  opposite_direction[Direction::RIGHT]<< std::endl;
  std::cout << std::endl;
  // Main
  std::cout << "========================================" << std::endl;
  std::cout << "Main" << std::endl;
  std::cout << std::endl;

  return 0;
}
