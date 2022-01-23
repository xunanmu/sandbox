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

void log_output(enum LogLevel level, int line, const char *file, const char *func, const char *fmt, ...){
    if(!LOG_LEVEL_SCOPE(level)) return;
    /*时间格式设置*/
    struct timeval timeval;
    gettimeofday(&timeval,NULL);
    struct tm *tm = localtime(&timeval.tv_sec);
    char now_time[64];
    now_time[strftime(now_time, sizeof(now_time), "%Y-%m-%d %H:%M:%S", tm)] = 0;
    long microseconds = timeval.tv_usec;
    /*log输出格式*/
    fprintf(LOG_OUT, "%s[%s:%ld][%-5s]{pid:%-5d,tid:%-5d}<%s>(%s:%d)",
            log_colors[level],
            now_time,
            microseconds,
            log_tags[level],
            getpid(),
            gettid(),
            func,
            file,
            line);
    va_list args;
    va_start(args,fmt);
    vfprintf(LOG_OUT,fmt,args);
    va_end(args);
    printf("\x1b[0m\n");
}
