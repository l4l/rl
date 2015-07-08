cmake_minimum_required(VERSION 3.2)
project(Client)

set(WindowInclude win/)
set(NetworkInclude net/)

find_package(Boost REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(client)
add_subdirectory(net)
add_subdirectory(win)
add_subdirectory(world)
add_subdirectory(srv)