project(Loginer)

set(SRCS Loginer.cpp Connection.cpp)

add_executable(Loginer ${SRCS})
link_directories(Loginer ${Boost_LIBRARY_DIRS})
target_link_libraries(Loginer ${Boost_LIBRARIES} pthread)