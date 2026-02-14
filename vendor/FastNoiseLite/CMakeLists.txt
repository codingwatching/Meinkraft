cmake_minimum_required(VERSION 3.28)

project(FastNoiseLite)

add_library(FastNoiseLite INTERFACE)

target_include_directories(FastNoiseLite INTERFACE "${CMAKE_CURRENT_LIST_DIR}/include")