project(Game)

set(GAME_SRCS main.cpp Character.cpp)
include_directories(${WindowInclude} ${NetworkInclude})

add_executable(Game ${GAME_SRCS})
target_link_libraries(Game Window Network)