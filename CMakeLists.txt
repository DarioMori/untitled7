cmake_minimum_required(VERSION 3.23)
project(untitled7)

set(CMAKE_CXX_STANDARD 14)

add_executable(untitled7 main.cpp)
find_package(SQLite3 REQUIRED)

target_link_libraries(untitled7 ${SQLite3_LIBRARIES})
