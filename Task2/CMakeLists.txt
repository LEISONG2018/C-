### CMake Version #############################################################

cmake_minimum_required(VERSION 3.5)
include(CMakeToolsHelpers OPTIONAL)

### Project Configuration #####################################################

get_filename_component(PROJECT_DIR_NAME ${CMAKE_CURRENT_LIST_DIR} NAME)
string(REPLACE " " "_" PROJECT_DIR_NAME ${PROJECT_DIR_NAME})

project(${PROJECT_DIR_NAME}
        VERSION 1.0.0.0 # <major>.<minor>.<patch>.<tweak>
        LANGUAGES CXX)

include_directories(${PROJECT_SOURCE_DIR}/include)

### List of .cpp Files ########################################################

set(SOURCES
    ${PROJECT_SOURCE_DIR}/src/FEString.cpp
    ${PROJECT_SOURCE_DIR}/src/main.cpp
)

### Compiler Flags ############################################################

# UNIX only
if(NOT WIN32)

# Default Flags
#message("CMAKE_CXX_FLAGS_DEBUG is ${CMAKE_CXX_FLAGS_DEBUG}")
# CMAKE_CXX_FLAGS_DEBUG is -g
#message("CMAKE_CXX_FLAGS_RELEASE is ${CMAKE_CXX_FLAGS_RELEASE}")
# CMAKE_CXX_FLAGS_RELEASE is -O3 -DNDEBUG

# Common Flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -fexceptions -pedantic-errors")

# Debug Flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DDEBUG")

# Release Flags
# -O2 instead of -O3
# -ftlo stands for Link Time Optimization (LTO)
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG -flto")

# GCC (Ubuntu 16.04 LTS Xenial Xerus)
if(UNIX AND NOT APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif(UNIX AND NOT APPLE)

# Clang (macOS Sierra 10.12)
# -Wno-tautological-compare is required when using std_lib_facilities on macOS
if(APPLE)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wno-tautological-compare")
endif(APPLE)

endif(NOT WIN32)

### Build Types ###############################################################

# UNIX only
if(NOT WIN32)

# if no build type is set, the default is Debug
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif(NOT CMAKE_BUILD_TYPE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${CMAKE_BUILD_TYPE})

endif(NOT WIN32)

### Build Configuration #######################################################

add_executable(${PROJECT_NAME} ${SOURCES})

###############################################################################
