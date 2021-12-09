cmake_minimum_required(VERSION 3.16)
project(sandbox C)

set(CMAKE_C_STANDARD 99)


include_directories(log/easylogger/inc)
include_directories(src)
add_executable(sandbox main.c)
add_subdirectory(src)
add_subdirectory(log)

target_link_libraries(sandbox log)
target_link_libraries(sandbox pthread)
target_link_libraries(sandbox base_sandbox)

enable_testing()
add_subdirectory(test)