cmake_minimum_required(VERSION 3.28)

project(glad)

add_library(glad INTERFACE)

target_include_directories(glad INTERFACE "${CMAKE_CURRENT_LIST_DIR}/include")