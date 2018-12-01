cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

set(EXECUTABLE_NAME date)

include_directories(include)

add_executable(${EXECUTABLE_NAME} src/main.cpp src/Date.cpp src/test.cpp)