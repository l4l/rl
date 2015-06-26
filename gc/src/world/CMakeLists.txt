project(World)

include_directories(${MYSQL_INCLUDE_DIRECTORY})


set(WORLD_SRCS DBConnector.cpp User.cpp Character.cpp World.cpp Map.cpp)
add_library(World ${WORLD_SRCS})
target_link_libraries(World mysqlclient)