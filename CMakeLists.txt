cmake_minimum_required(VERSION 3.27)
project(memory_hierarchy_simulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(memory_hierarchy_simulator main.cpp
        MemoryCacheEntry.cpp
        MemoryCacheEntry.h
        MemoryCacheUnit.cpp
        MemoryCacheUnit.h
        utils.h
        utils.cpp)
