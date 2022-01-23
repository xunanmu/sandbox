/**
 * @author: 徐南木
 * @date: 2022/1/23 15:13
 * @description: 
 */

#ifndef SANDBOX_LOG_H
#define SANDBOX_LOG_H
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/time.h>
#include <time.h>

enum LogLevel { log_trace, log_debug, log_info, log_warn, log_error };
static const char *log_tags[] = {"Trace", "Debug", "Info", "Warn", "Error"};
static const char *log_colors[] = {"\x1b[94m", "\x1b[36m", "\x1b[32m", "\x1b[33m", "\x1b[31m"};

void log_output(enum LogLevel, int line, const char *file, const char *func, const char *fmt, ...);

#define LOG_OUTPUT(level, ...) log_output(level,__LINE__,__FILE__,__FUNCTION__,__VA_ARGS__)
#define log_e(...) LOG_OUTPUT(log_error,__VA_ARGS__)
#define log_w(...) LOG_OUTPUT(log_warn ,__VA_ARGS__)
#define log_i(...) LOG_OUTPUT(log_info ,__VA_ARGS__)
#define log_d(...) LOG_OUTPUT(log_debug,__VA_ARGS__)
#define log_t(...) LOG_OUTPUT(log_trace,__VA_ARGS__)
#define LOG_LEVEL_SCOPE(x) (log_trace<=(x)&&(x)<=log_error)
#define LOG_OUT stdout


#endif //SANDBOX_LOG_H
