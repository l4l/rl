project(Window)

set(WIN_SRCS InitWindow.cpp)

find_package(FLTK)
include_directories(${FLTK_INCLUDE_DIRS})

add_library(Window ${WIN_SRCS})
target_link_libraries(Window ${FLTK_LIBRARIES})