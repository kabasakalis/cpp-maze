//#include <memory>  // unique_ptr
#include "jj"

namespace test {

  // Default constructor
  Test::Test(): p{ new Resource() } {}

  // Special Member functions

  // dtor
  virtual Test()::~Test(){delete p;}

  // copy constructor
  Test::Test(const Test& rhs)
    : p{new Resource{*(rhs.p)}}{}

  // copy assignment
   Test& Test::operator=(const Test& rhs){
   if (&rhs != this) {
     delete p;
     p = nullptr;
     p = new Resource(*(rhs.p));
   }
     return *this;
  }

  // move constructor
  Test::Test(Test&& rhs)
    : p{rhs.p}{
    rhs.p = nullptr;
  }

  // move assignment
  Test& Test::operator=(Test&& rhs ){
    if (&rhs != this) {
      delete p;
      p = rhs.p;
      rhs.p = nullptr;
     }
     return *this;
  }

}
