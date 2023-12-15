cmake_minimum_required(VERSION 3.21)
project(cpp_subd)

add_subdirectory(testlib)

include_directories(testlib/googletest/include)

add_executable(cpp_subd Task2/Common/HashMap.cpp Task2/Common/HashMap.h Test/HashMapTest.cpp)

target_link_libraries(cpp_subd gtest gtest_main)