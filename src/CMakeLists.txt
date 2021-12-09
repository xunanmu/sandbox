cmake_minimum_required(VERSION 3.16)
set(CMAKE_C_STANDARD 99)
project(sandbox)

aux_source_directory(. SANDBOX)
add_library(base_sandbox STATIC ${SANDBOX})
