
#include <iostream>
#include <fstream>
//[ADAPT]
#include <template/template-version.h>


#include <mylib/mylib.h>

namespace mylib {


MyLib::MyLib(){

}

MyLib::~MyLib(){

}


int MyLib::returnOne(){ return 1; }

void printMyLib(){
    // Library name
    std::cout << "========================================" << std::endl;
    std::cout << "mylib::printMyLib" << std::endl;
}

} // namespace mylib
