cmake_minimum_required(VERSION 3.27)
project(memory_hierarchy_simulator)

set(CMAKE_CXX_STANDARD 20)

add_executable(memory_hierarchy_simulator main.cpp
        CacheEntry.cpp
        CacheEntry.h
        CacheUnit.cpp
        CacheUnit.h
        utils.h
        utils.cpp)
