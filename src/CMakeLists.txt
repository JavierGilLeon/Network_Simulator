cmake_minimum_required(VERSION 4.2.1)
project(Network_Emulator C)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(board)
add_subdirectory(event)

add_executable(${PROJECT_NAME} main.c)

target_link_libraries(${PROJECT_NAME} PRIVATE board event)