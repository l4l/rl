cmake_minimum_required(VERSION 3.2)
project(Client)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(WindowInclude ${CMAKE_CURRENT_SOURCE_DIR}/win)
set(NetworkInclude ${CMAKE_CURRENT_SOURCE_DIR}/net)

find_package(Boost REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${PublicInclude})

add_subdirectory(client)
add_subdirectory(net)
add_subdirectory(win)
add_subdirectory(world)
add_subdirectory(srv)