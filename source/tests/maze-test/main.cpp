
#include <gmock/gmock.h>

GTEST_API_ int main(int argc, char* argv[])
{
    ::testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}
