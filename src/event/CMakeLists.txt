
add_library(event event.c)


target_include_directories(event PUBLIC ${CMAKE_SOURCE_DIR})
target_include_directories(event PUBLIC ${CMAKE_SOURCE_DIR}/board)