cmake_minimum_required(VERSION 3.10)
project(Containers VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

set(SOURCES
    src/main.cpp
    src/vector.cpp
    src/list.cpp
    src/deque.cpp
    src/map.cpp
    src/set.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/output)