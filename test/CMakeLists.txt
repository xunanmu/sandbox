cmake_minimum_required(VERSION 3.16)
project(sandbox)
set(CMAKE_C_STANDARD 99)

include_directories(unity)
include_directories(../src)
aux_source_directory(unity UNITY)
add_library(unity SHARED ${UNITY})



add_executable(test_create_ust test_create_ust.c)
target_link_libraries(test_create_ust unity base_sandbox )

add_executable(test_create_file test_create_file.c)
target_link_libraries(test_create_file unity base_sandbox )

add_executable(clear_mount_uts clear_mount_uts)
add_executable(test_is_same_inode test_is_same_inode)
target_link_libraries(test_is_same_inode unity base_sandbox )

add_test(test_is_same_inode test_is_same_inode)
add_test(test_create_ust test_create_ust)
add_test(clear_mount_uts clear_mount_uts)
add_test(test_create_file test_create_file)



