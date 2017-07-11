
#include <gmock/gmock.h>
#include <mylib/mylib.h>

class mylib_test: public testing::Test
{
public:
};

TEST_F(mylib_test, ReturnOne)
{
    mylib::MyLib ml;

    EXPECT_EQ((unsigned int)1, ml.returnOne());
    // ...
}
