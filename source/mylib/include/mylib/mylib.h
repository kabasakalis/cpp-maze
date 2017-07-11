
#pragma once


#include <mylib/mylib_api.h>


namespace mylib
{


/**
*  @brief
*    MyLib
*/
class MYLIB_API MyLib
{
public:
    /**
    *  @brief
    *    Constructor
    */
    MyLib();

    /**
    *  @brief
    *    Destructor
    */
    virtual ~MyLib();

    /**
    *  @brief
    *    Print Maze
    *
    */
    MYLIB_API int returnOne();
};

    /**
    *  @brief
    *    Print MyLib
    *
    */
    MYLIB_API void printMyLib();

} // namespace mylib
