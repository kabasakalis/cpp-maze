# C++ Project Template
### Forked and adapted from   [ C++ CMake Project Template](https://github.com/cginternals/cmake-init)
----
I will add my own stuff to this repo and occasionally pull from the upstream.
### [Setup Guide](https://github.com/cginternals/cmake-init/wiki/Setup-Guide)
### Usage
Adapt for your project. For convenience, [ADAPT] markers have been included,
additionally you can consult the `ADAPT` file for more details.

### Overview
cmake-init is a copy and paste template, that provides the following features:
 * Cross Platform
 * Windows
 * Linux
 * Mac
 * Libraries, Applications, Testing template
 * Documentation template
 * Installation, Packaging template
 * CMake find script template for defined libraries

The files of cmake-init are an instantiation of the templates containing:
  * Example app
  * Example lib
  * Example test
  * Example documentation
  * Example package

| Service | System | Compiler | Status |
| ------- | ------ | -------- | -----: |
|  [Travis-CI](https://travis-ci.org/drumaddict/cpp-template) | Ubuntu 14.04 | GCC 4.8, Clang 3.5 | [![Build Status](https://travis-ci.org/drumaddict/cpp-template.svg?branch=master)](https://travis-ci.org/drumaddict/cpp-template) |
|  [Travis-CI](https://travis-ci.org/drumaddict/cpp-template) | macOS | AppleClang 7.3 | [![Build Status](https://travis-ci.org/drumaddict/cpp-template.svg?branch=master)](https://travis-ci.org/drumaddict/cpp-template) |
|  [Coverity](https://scan.coverity.com/projects/drumaddict-cpp-template) | Ubuntu 14.04 | GCC 4.8, Clang 3.5 | [![Coverity Build Status](https://scan.coverity.com/projects/13112/badge.svg)](https://scan.coverity.com/projects/drumaddict-cpp-template) |
|  [CodeCov](https://codecov.io/gh/drumaddict/cpp-template) |   |  | [![Test Coverage](https://codecov.io/gh/drumaddict/cpp-template/branch/master/graph/badge.svg)](https://codecov.io/gh/drumaddict/cpp-template) |
|  [Codedocs](https://codedocs.xyz/drumaddict/cpp-template/) |    |   | [![Documentation](https://codedocs.xyz/drumaddict/cpp-template.svg)](https://codedocs.xyz/drumaddict/cpp-template/) |

###  Scenarios covered in cmake-init:

##### 1.  Development
The project is contained in a source directory for active development.

```
binaries: ./build
rpath:    absolute paths to all dependencies
datapath: ..
```
##### 2.  Installation (default)
The project is contained in a source directory for active development.
```
binaries: ./bin
rpath:    $ORIGIN/../lib
datapath: ..
```

##### 3.  Installation (unix system install)
The project is contained in a source directory for active development.
```
binaries: /usr/[local/]bin
rpath:    empty
datapath: /usr/[local/]share/<projectname>
```

## References
* [C++ Best Practices by Jason Turner](https://lefticus.gitbooks.io/cpp-best-practices/content/)
* [CMake  Best Practices]( https://github.com/boostcon/cppnow_presentations_2017/blob/master/05-19-2017_friday/effective_cmake__daniel_pfeifer__cppnow_05-19-2017.pdf)
* [C++ Core Guidelines](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#Rf-inline)
* [C++ Reference](http://en.cppreference.com/w/)
* [OnLine Compliler](https://www.onlinegdb.com/online_c++_compiler)
* [C++ Resources](https://github.com/fffaraz/awesome-cpp)


## License
 [MIT License](http://opensource.org/licenses/MIT).

