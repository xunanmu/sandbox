cmake_minimum_required(VERSION 3.16)
project(sandbox)
set(CMAKE_C_STANDARD 99)

include_directories(unity)
include_directories(../src)
include_directories(../src/namespace)
aux_source_directory(unity UNITY)
add_library(unity SHARED ${UNITY})
add_executable(test_op test.c test.c test_ust.c)
#add_executable(test-op main.c)
#target_link_libraries(test-op unity base_sandbox)
#
#add_test(test-op test-op)
#add_test(test-o test-op)



