
// #include "maze/base.h"
#include "maze/maze.h"
#include <gmock/gmock.h>
#include <algorithm>
#include "maze/builder.h"
#include "maze/room.h"
#include "maze/solver.h"

using namespace maze;
class MazeTest : public ::testing::Test {
 protected:
  MazeTest() : _maze{15, 10} {}

  virtual ~MazeTest() {
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
  Maze _maze;
};

TEST_F(MazeTest, number_of_rooms) {
  printf("A maze with 15 columns and 10 rows has 150 rooms.\n");
  EXPECT_EQ(_maze.rooms().size(), 150);
}

TEST_F(MazeTest, columns) {
  printf("Columns getter.\n");
  EXPECT_EQ(_maze.columns(), 15);
}

TEST_F(MazeTest, rows) {
  printf("Rows getter.\n");
  EXPECT_EQ(_maze.rows(), 10);
}

TEST_F(MazeTest, all_rooms_visited) {
  printf("all_rooms_visited() , no rooms visited for pristine maze.\n");
  ASSERT_FALSE(_maze.all_rooms_visited());
}

TEST_F(MazeTest, find_room) {
  printf("Finds room given it's position.\n");
  const Position& p68{6, 8};
  auto room = _maze.find_room(p68);
  ASSERT_TRUE((**room).position() == p68);


}
