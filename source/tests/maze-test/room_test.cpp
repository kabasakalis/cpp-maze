

// #include "maze/utils.h"
#include "maze/room.h"
#include <gmock/gmock.h>
#include "maze/base.h"

using namespace maze;
namespace maze {
class RoomTest : public ::testing::Test {
 protected:
  RoomTest() : _room{Position{15, 10}} {
    _room.visits_from() = {Direction::UP, Direction::RIGHT};
    _room.used_exits() = {Direction::UP, Direction::UP, Direction::RIGHT,
                          Direction::RIGHT, Direction::RIGHT};
    _room.available_exits() = {Direction::UP, Direction::RIGHT,
                               Direction::DOWN};
  }

  virtual ~RoomTest() {
    // You can do clean-up work that doesn't throw exceptions here.
  }

  // If the constructor and destructor are not enough for setting up
  // and cleaning up each test, you can define the following methods:

  virtual void SetUp() {
    // Code here will be called immediately after the constructor (right
    // before each test).
  }

  virtual void TearDown() {
    // Code here will be called immediately after each test (right
    // before the destructor).
  }
  Room _room;
};

TEST_F(RoomTest, is_exit_free) {
  printf("Left is not free exit\n");
  ASSERT_TRUE(!_room.is_exit_free(Direction::LEFT));

  printf("Down is a free exit\n");
  ASSERT_TRUE(_room.is_exit_free(Direction::DOWN));
}

TEST_F(RoomTest, is_visited) {
  printf("The room has been visited\n");
  ASSERT_TRUE(_room.visited());
}

TEST_F(RoomTest, times_used_to_exits) {
  auto times_used_to_exits = _room.times_used_to_exits();
  printf("Down used zero times. \n");
  ASSERT_EQ(times_used_to_exits[0], std::vector<Direction>({Direction::DOWN}));
  printf("Up used two times. \n");
  ASSERT_EQ(times_used_to_exits[2], std::vector<Direction>({Direction::UP}));
  printf("Right  used three times. \n");
  ASSERT_EQ(times_used_to_exits[3], std::vector<Direction>({Direction::RIGHT}));
}

TEST_F(RoomTest, less_used_available_exits) {
  printf("Less used available exit is Down, (zero times). \n");
  ASSERT_EQ(_room.less_used_available_exits(),
            std::vector<Direction>({Direction::DOWN}));
}

TEST_F(RoomTest, unused_available_exits) {
  printf("Unused available exit is Down. \n");
  ASSERT_EQ(_room.unused_available_exits(),
            std::vector<Direction>({Direction::DOWN}));
}
}
