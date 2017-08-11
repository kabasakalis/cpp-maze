
#
# Platform and architecture setup
#

# Get upper case system name
string(TOUPPER ${CMAKE_SYSTEM_NAME} SYSTEM_NAME_UPPER)

# Determine architecture (32/64 bit)
set(X64 OFF)
if(CMAKE_SIZEOF_VOID_P EQUAL 8)
    set(X64 ON)
endif()


#
# Project options
#

set(DEFAULT_PROJECT_OPTIONS
    DEBUG_POSTFIX             "d"
    CXX_STANDARD              14 # Not available before CMake 3.1; see below for manual command line argument addition
    LINKER_LANGUAGE           "CXX"
    POSITION_INDEPENDENT_CODE ON
    CXX_VISIBILITY_PRESET     "hidden"
)


#
# Include directories
#

set(DEFAULT_INCLUDE_DIRECTORIES)


#
# Libraries
#

set(DEFAULT_LIBRARIES)


#
# Compile definitions
#

set(DEFAULT_COMPILE_DEFINITIONS
    SYSTEM_${SYSTEM_NAME_UPPER}
)

# MSVC compiler options
if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "MSVC")
    set(DEFAULT_COMPILE_DEFINITIONS ${DEFAULT_COMPILE_DEFINITIONS}
        _SCL_SECURE_NO_WARNINGS  # Calling any one of the potentially unsafe methods in the Standard C++ Library
        _CRT_SECURE_NO_WARNINGS  # Calling any one of the potentially unsafe methods in the CRT Library
    )
endif ()


#
# Compile options
#

set(DEFAULT_COMPILE_OPTIONS)

# MSVC compiler options
if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "MSVC")
    set(DEFAULT_COMPILE_OPTIONS ${DEFAULT_COMPILE_OPTIONS}
        /MP           # -> build with multiple processes
        /W4           # -> warning level 4
        # /WX         # -> treat warnings as errors

        /wd4251       # -> disable warning: 'identifier': class 'type' needs to have dll-interface to be used by clients of class 'type2'
        /wd4592       # -> disable warning: 'identifier': symbol will be dynamically initialized (implementation limitation)
        # /wd4201     # -> disable warning: nonstandard extension used: nameless struct/union (caused by GLM)
        # /wd4127     # -> disable warning: conditional expression is constant (caused by Qt)

                      #  Jason Turner's best practices flags. https://lefticus.gitbooks.io/cpp-best-practices/content/02-Use_the_Tools_Available.html
        /w14242       # -> 'identfier': conversion from 'type1' to 'type1', possible loss of data
        /w14254       # -> 'operator': conversion from 'type1:field_bits' to 'type2:field_bits', possible loss of data
        /w14263       # -> 'function': member function does not override any base class virtual member function
        /w14265       # -> 'classname': class has virtual functions, but destructor is not virtual instances of this class may not be destructed correctly
        /w14287       # -> 'operator': unsigned/negative constant mismatch
        /we4289       # -> nonstandard extension used: 'variable': loop control variable declared in the for-loop is used outside the for-loop scope
        /w14296       # -> 'operator': expression is always 'boolean_value'
        /w14311       # -> 'variable': pointer truncation from 'type1' to 'type2'
        /w14545       # -> expression before comma evaluates to a function which is missing an argument list
        /w14546       # -> function call before comma missing argument list
        /w14547       # -> 'operator': operator before comma has no effect; expected operator with sideeffect
        /w14549       # -> 'operator': operator before comma has no effect; did you intend 'operator'?
        /w14555       # -> expression has no effect; expected expression with side-effect
        /w14619       # -> pragma warning: there is no warning number 'number'
        /w14640       # -> Enable warning on thread un-safe static member initialization
        /w14826       # -> Conversion from 'type1' to 'type_2' is sign-extended. This may cause unexpected runtime behavior.
        /w14905       # -> wide string literal cast to 'LPSTR'
        /w14906       # -> string literal cast to 'LPWSTR'
        /w14928       # -> illegal copy-initialization; more than one user-defined conversion has been implicitly applied

        #$<$<CONFIG:Debug>:
        #/RTCc         # -> value is assigned to a smaller data type and results in a data loss
        #>

        $<$<CONFIG:Release>:
        /Gw           # -> whole program global optimization
        /GS-          # -> buffer security check: no
        /GL           # -> whole program optimization: enable link-time code generation (disables Zi)
        /GF           # -> enable string pooling
        >

        # No manual c++11 enable for MSVC as all supported MSVC versions for cmake-init have C++11 implicitly enabled (MSVC >=2013)
    )
endif ()

# GCC and Clang compiler options
if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU" OR "${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    set(DEFAULT_COMPILE_OPTIONS ${DEFAULT_COMPILE_OPTIONS}
        -Wall
        -Wextra
        -Wunused

        -Wreorder
        -Wignored-qualifiers
        -Wmissing-braces
        -Wreturn-type
        -Wswitch
        -Wswitch-default
        -Wuninitialized
        -Wmissing-field-initializers

        #  Jason Turner's best practices flags. https://lefticus.gitbooks.io/cpp-best-practices/content/02-Use_the_Tools_Available.html
        -Wshadow
        -Wnon-virtual-dtor
        # -Wold-style-cast
        -Wcast-align
        -Woverloaded-virtual
        -Wconversion
        -Wsign-conversion
        # -Wmisleading-indentation

        # clang
        # -stdliblibc++
        # -stdlib=libstdc++
        $<$<CXX_COMPILER_ID:GNU>:
            -Wmaybe-uninitialized

            $<$<VERSION_GREATER:$<CXX_COMPILER_VERSION>,4.8>:
                -Wpedantic

                -Wreturn-local-addr
            >
        >

        $<$<CXX_COMPILER_ID:Clang>:
            -Wpedantic

            # -Wreturn-stack-address # gives false positives
        >

        $<$<PLATFORM_ID:Darwin>:
            -pthread
        >

        # Required for CMake < 3.1; should be removed if minimum required CMake version is raised.
        $<$<VERSION_LESS:${CMAKE_VERSION},3.1>:
            -std=c++11
        >
        # For debugging with lldb
        $<$<CONFIG:Debug>:
            -g
            # -v
        >

    )
endif ()


#
# Linker options
#

set(DEFAULT_LINKER_OPTIONS)

# Use pthreads on mingw and linux
if("${CMAKE_CXX_COMPILER_ID}" MATCHES "GNU" OR "${CMAKE_SYSTEM_NAME}" MATCHES "Linux")
    set(DEFAULT_LINKER_OPTIONS
        -pthread
    )
endif()
