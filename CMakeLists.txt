cmake_minimum_required(VERSION 3.5)

project(3ds_sdk CXX ASM)

file(GLOB_RECURSE 3ds_sdk_csourcefiles ${CMAKE_CURRENT_LIST_DIR}/src/*.c)
file(GLOB_RECURSE 3ds_sdk_cxxsourcefiles ${CMAKE_CURRENT_LIST_DIR}/src/*.cpp)

add_library(3ds_sdk ${3ds_sdk_csourcefiles} ${3ds_sdk_cxxsourcefiles})

target_include_directories(3ds_sdk PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)
