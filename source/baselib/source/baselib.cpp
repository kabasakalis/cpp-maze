
#include <iostream>
#include <fstream>

#include <maze/maze-version.h>
#include <baselib/baselib.h>


namespace baselib
{


void printInfo()
{
    std::string dataPath = "data";

    std::cout << "baselib:printInfo" << std::endl;
    std::cout << "PROJECT METADATA" << std::endl;

    std::cout << "========================================" << std::endl;
    std::cout << "Project Name:             " << MAZE_PROJECT_NAME  << std::endl;
    std::cout << "Project Description:      " << MAZE_PROJECT_DESCRIPTION << std::endl;
    std::cout << "Author Organization:      " << MAZE_AUTHOR_ORGANIZATION << std::endl;
    std::cout << "Author Domain:            " << MAZE_AUTHOR_DOMAIN << std::endl;
    std::cout << "Author Maintainer:        " << MAZE_AUTHOR_MAINTAINER << std::endl;
    std::cout << "Project Version:          " << MAZE_VERSION << std::endl;
    std::cout << "Project Name Version:     " << MAZE_NAME_VERSION << std::endl;
    std::cout << "Project Version Revision: " << MAZE_VERSION_REVISION << std::endl;

    // Library type (static or dynamic)
    #ifdef BASELIB_STATIC_DEFINE
        std::cout << "Baselib lib type: STATIC" << std::endl;
    #else
        std::cout << "Baselib lib type: SHARED" << std::endl;
    #endif

    // Data directory
    std::cout << "Data path:    " << dataPath << std::endl;
    std::cout << std::endl;

    // Read file
    std::cout << "Data directory access" << std::endl;
    std::string fileName = dataPath + "/DATA_FOLDER.txt";
    std::cout << "Reading from '" << fileName << "': " << std::endl;
    std::cout << std::endl;

    std::ifstream f(fileName);
    if (f.is_open()) {
        std::string line;
        while (getline(f, line)) {
            std::cout << line << '\n';
        }
        f.close();
    } else {
        std::cout << "Unable to open file." << std::endl;
    }

}

} // namespace baselib
