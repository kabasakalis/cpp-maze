
#include <iostream>

#include <baselib/baselib.h>
#include <mylib/mylib.h>

int main(int /*argc*/, char* /*argv*/[])
{
    // Print library info
    baselib::printInfo();
    mylib::printMyLib();
    std::cout << std::endl;

    // Main
    std::cout << "========================================" << std::endl;
    std::cout << "Main" << std::endl;
    std::cout << std::endl;

    return 0;
}
