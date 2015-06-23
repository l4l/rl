project(Network)

set(NET_SRCS Loginer.cpp Connection.cpp)

add_library(Network ${NET_SRCS})
link_directories(Network ${Boost_LIBRARY_DIRS})
target_link_libraries(Network ${Boost_LIBRARIES} pthread)