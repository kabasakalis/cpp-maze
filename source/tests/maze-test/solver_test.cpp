
#include "maze/solver.h"
#include <gmock/gmock.h>
#include "maze/base.h"
#include "maze/builder.h"

using namespace maze;
namespace maze {
class SolverTest : public ::testing::Test {
 protected:
  SolverTest() : _maze{Maze{15, 10}} {
    _builder = Builder(_maze);
    _builder.build_maze();
    _solver = Solver(_builder.maze(), Position{1, 1}, Position{10, 10});
    _solver.solve_maze();
  }

  virtual ~SolverTest() {
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
  Builder _builder;
  Solver _solver;
};

TEST_F(SolverTest, solver_reached_goal) {
  printf("Last path postion is the goal, {10, 10}\n");
  auto goal_position{Position{10, 10}};
  ASSERT_EQ(_solver.path().back(), goal_position);
}
}
