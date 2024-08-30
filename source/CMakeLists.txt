cmake_minimum_required(VERSION 3.16)

project(ChessConsole
        VERSION 0.2.0
        DESCRIPTION "C++ chess game in console"
        LANGUAGES CXX)

file(GLOB_RECURSE SRC_FILES src/*.cpp)
add_executable(Chess main.cpp ${SRC_FILES})

target_compile_features(Chess PRIVATE)
target_include_directories(Chess PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
