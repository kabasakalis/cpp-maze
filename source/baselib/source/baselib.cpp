
#include <iostream>
#include <fstream>

#include <template/template-version.h>
#include <baselib/baselib.h>


namespace baselib
{


void printInfo()
{
    std::string dataPath = "data";

    // Library name [ADAPT] replace TEMPLATE with project id in macros.
    std::cout << "baselib:printInfo" << std::endl;
    std::cout << "PROJECT METADATA" << std::endl;

    std::cout << "========================================" << std::endl;
    std::cout << "Project Name:             " << TEMPLATE_PROJECT_NAME  << std::endl;
    std::cout << "Project Description:      " << TEMPLATE_PROJECT_DESCRIPTION << std::endl;
    std::cout << "Author Organization:      " << TEMPLATE_AUTHOR_ORGANIZATION << std::endl;
    std::cout << "Author Domain:            " << TEMPLATE_AUTHOR_DOMAIN << std::endl;
    std::cout << "Author Maintainer:        " << TEMPLATE_AUTHOR_MAINTAINER << std::endl;
    std::cout << "Project Version:          " << TEMPLATE_VERSION << std::endl;
    std::cout << "Project Name Version:     " << TEMPLATE_NAME_VERSION << std::endl;
    std::cout << "Project Version Revision: " << TEMPLATE_VERSION_REVISION << std::endl;

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
