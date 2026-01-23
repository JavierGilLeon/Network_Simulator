add_library(board board.c)

target_include_directories(board PUBLIC ${CMAKE_SOURCE_DIR})
target_include_directories(board PUBLIC ${CMAKE_SOURCE_DIR}/event)