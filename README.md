
# C++ Maze
---

### Overview
Build and solve a virtual maze with C++.


<!-- | Service | System | Compiler | Status | -->
<!-- | ------- | ------ | -------- | -----: | -->
<!-- |  [Travis-CI](https://travis-ci.org/drumaddict/cpp-maze) | Ubuntu 14.04 | GCC 4.8, Clang 3.5 | [![Build Status](https://travis-ci.org/drumaddict/cpp-maze.svg?branch=master)](https://travis-ci.org/drumaddict/cpp-maze) | -->
<!-- |  [Travis-CI](https://travis-ci.org/drumaddict/cpp-maze) | macOS | AppleClang 7.3 | [![Build Status](https://travis-ci.org/drumaddict/cpp-maze.svg?branch=master)](https://travis-ci.org/drumaddict/cpp-maze) | -->
<!-- |  [Coverity](https://scan.coverity.com/projects/drumaddict-cpp-maze) | Ubuntu 14.04 | GCC 4.8, Clang 3.5 | [![Coverity Build Status](https://scan.coverity.com/projects/13445/badge.svg)](https://scan.coverity.com/projects/drumaddict-cpp-maze) | -->
<!-- |  [CodeCov](https://codecov.io/gh/drumaddict/cpp-maze) |   |  | [![Test Coverage](https://codecov.io/gh/drumaddict/cpp-maze/branch/master/graph/badge.svg)](https://codecov.io/gh/drumaddict/cpp-maze) | -->
<!-- |  [Codedocs](https://codedocs.xyz/drumaddict/cpp-maze/) |    |   | [![Documentation](https://codedocs.xyz/drumaddict/cpp-maze.svg)](https://codedocs.xyz/drumaddict/cpp-maze/) | -->


###### A 73 x 38 Maze, solving process. Solver is yellow dot.
![screenshot](https://github.com/drumaddict/cpp-maze/blob/master/screenshots/cppmaze1.png)

###### A 73 x 38 Maze, building process. Builder is yellow dot.
![screenshot](https://github.com/drumaddict/cpp-maze/blob/master/screenshots/cppmaze2.png)


### Prerequisites
---
The codebase was developed and tested on Ubuntu 16.04.

* [CMake, at least v3.0](https://cmake.org/)
*  Compiler clang 3.8.0, using gcc 6.2.0  standard library
* [SFML]( https://www.sfml-dev.org/index.php)
* [Boost](http://www.boost.org/)

You don't have to install Boost manually, it will be installed with [Hunter](https://github.com/ruslo/hunter) package manager,
when you configure and build the project, (see below).
You have to install SFML library manually though, easy as running `sudo apt-get install libsfml-dev` in your terminal
(for Ubuntu). See other installation options in [SFML getting started page.](https://www.sfml-dev.org/tutorials/2.4/start-linux.php)

### Configuring and Building the project with CMake, (release).
---
* Run `./configure` two times for release configuration.
* Run `cmake --build build` to build the project in `build` folder.
### Configuring and Building the project with CMake, (debug).
---
* Run `./configure debug` two times for debug configuration.
* Run `cmake --build build-debug` to build the project in `build-debug` folder.

### Usage.
---
* Release: `build/cppmaze [columns] [rows] [mode]`
* Debug: `build-debug/cppmazed [columns] [rows] [mode]`

Columns ranges from 1 to 73, rows from 1 to 38.
You can change these ranges in the code, but the maze will probably exceed the
screen boundaries if you increase the maximum values.

Mode is 0 if you want to watch the built maze only and 1 if you want to watch the
maze solved.
Default start and goal positions are {1,1} and the bottom right corner of the maze respectively,
I did'nt make these configurable through the command line, but you can easily modify the code
and choose any start and goal positions.

You can control the speed of the animation with the framerate, see `source/main/main.cpp`.
Default setting is  `window.setFramerateLimit(30);`.

#### Usage Examples:
* `build/cppmaze  73 38 0`, will build  a maze of 2774 rooms, you will watch the building process.
* `build/cppmaze  40 20 1`, will build  a maze of 800 rooms, you will watch the solving process.

### Tests
Run tests with `cmake --build build-debug --target test`


## License
 [MIT License](http://opensource.org/licenses/MIT).

