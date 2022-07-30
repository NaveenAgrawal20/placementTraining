cmake_minimum_required(VERSION 3.15)
project(ClionProj)

set(CMAKE_CXX_STANDARD 14)

add_executable(ClionProj main.cpp)
add_executable(stackArr stackArr.cpp)
add_executable(stackLinked stackLinked.cpp)
add_executable(inFixToPost inFixToPost.cpp)
add_executable(searchingLiveSess cmake-build-debug/searchingLiveSess.cpp)
add_executable(evaluate evaluate.cpp)