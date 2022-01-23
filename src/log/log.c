/**
 * @author: 徐南木
 * @date: 2022/1/23 15:13
 * @description: 
 */

#include "log.h"

char* log_time(){
    struct timeval timeval;
    gettimeofday(&timeval,NULL);
    struct tm *tm = localtime(&timeval.tv_sec);
    char now[64];
    now[strftime(now,sizeof(now),"%Y-%m-%d %H:%M:%S.",tm)] = 0;
}

void log_out(enum LogLevel level, const char *fmt, ...) {
    if(!LOG_LEVEL_SCOPE(level)) return;
    /*时间格式设置*/
    struct timeval timeval;
    gettimeofday(&timeval,NULL);
    struct tm *tm = localtime(&timeval.tv_sec);
    char now[64];
    now[strftime(now,sizeof(now),"%Y-%m-%d %H:%M:%S",tm)] = 0;
    long usec = timeval.tv_usec;
    /*log输出格式*/
    fprintf(LOG_OUT,"%s%s.%ld [%-5s]\x1b[0m",log_colors[level],now,usec,log_tags[level]);
    va_list args;
    va_start(args,fmt);
    vfprintf(LOG_OUT,fmt,args);
    va_end(args);
}
