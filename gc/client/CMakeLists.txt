project(Client)

set(CLIENT_SRCS main.cpp)
include_directories(${WindowInclude})
include_directories(${NetworkInclude})

add_executable(Client ${CLIENT_SRCS})
target_link_libraries(Client Window Network)