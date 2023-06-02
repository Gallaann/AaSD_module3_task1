cmake_minimum_required(VERSION 3.13)

project(algorithms_first_task CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME} main.cpp src/ArcGraph.cpp src/ListGraph.cpp src/MatrixGraph.cpp src/SetGraph.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC include)
