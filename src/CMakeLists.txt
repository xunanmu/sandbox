cmake_minimum_required(VERSION 3.16)
set(CMAKE_C_STANDARD 99)
project(sandbox)

aux_source_directory(. SANDBOX)
add_library(base_sandbox STATIC ${SANDBOX} namespace/cgroup.c namespace/cgroup.h namespace/ipc.c namespace/ipc.h namespace/mnt.c namespace/mnt.h namespace/net.c namespace/net.h namespace/pid.c namespace/pid.h namespace/user.c namespace/user.h namespace/uts.c namespace/uts.h namespace/time.c namespace/time.h log/log.c log/log.h utils/utils.c utils/utils.h)

target_link_libraries(base_sandbox pthread)