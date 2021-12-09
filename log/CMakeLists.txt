cmake_minimum_required(VERSION 3.16)

include_directories(easylogger/inc)
include_directories(easylogger/plugins/file)
include_directories(easylogger/src)
aux_source_directory(easylogger/src LOG_SRC)
aux_source_directory(easylogger/plugins/file LOG_FILE)
aux_source_directory(easylogger/port LOG_PORT)
add_library(log STATIC ${LOG_SRC} ${LOG_FILE} ${LOG_PORT} )
