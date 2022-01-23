/**
 * @author: 徐南木
 * @date: 2022/1/23 15:13
 * @description: 
 */

#ifndef SANDBOX_LOG_H
#define SANDBOX_LOG_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <sys/time.h>
#include <time.h>

enum LogLevel {log_trace , log_debug, log_info, log_warn, log_error };
static const char *log_tags[] = {"Trace", "Debug", "Info", "Warn", "Error"};
static const char *log_colors[] = {"\x1b[94m","\x1b[36m","\x1b[32m","\x1b[33m","\x1b[31m"};
void log_out(enum LogLevel,const char *fmt,...);
#define LOG_LEVEL_SCOPE(x) (log_trace<=(x)&&(x)<=log_error)
#define LOG_OUT stdout
#endif //SANDBOX_LOG_H
