
#include <gmock/gmock.h>
#include <maze/maze.h>

class maze_test: public testing::Test
{
public:
};

TEST_F(maze_test, ReturnOne)
{
    maze::Maze m;

    EXPECT_EQ((unsigned int)1, m.returnOne());
    // ...
}
