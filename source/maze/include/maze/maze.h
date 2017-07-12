
#pragma once

#include <maze/maze_api.h>

namespace maze {

/**
*  @brief
*    Maze
*/
class MAZE_API Maze {
   public:
    /**
    *  @brief
    *    Constructor
    */
    Maze();

    /**
    *  @brief
    *    Destructor
    */
    virtual ~Maze();

    /**
    *  @brief
    *    Print Maze
    *
    */
    MAZE_API int returnOne();
};

/**
*  @brief
*    Print Maze
*
*/
MAZE_API void printMaze();

}  // namespace cppmaze
