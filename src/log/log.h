/**
 * @author: 徐南木
 * @date: 2022/1/23 15:13
 * @description: 
 */

#ifndef SANDBOX_LOG_H
#define SANDBOX_LOG_H


void log_output(int level, int line, const char *file, const char *func, const char *fmt, ...);

#define LOG_TRACE 0
#define LOG_DEBUG 1
#define LOG_INFO  2
#define LOG_WARN  3
#define LOG_ERROR 4
#define LOG_OUTPUT(level, ...) log_output(level,__LINE__,__FILE__,__FUNCTION__,__VA_ARGS__)
#define log_e(...) LOG_OUTPUT(LOG_ERROR,__VA_ARGS__)
#define log_w(...) LOG_OUTPUT(LOG_WARN ,__VA_ARGS__)
#define log_i(...) LOG_OUTPUT(LOG_INFO ,__VA_ARGS__)
#define log_d(...) LOG_OUTPUT(LOG_DEBUG,__VA_ARGS__)
#define log_t(...) LOG_OUTPUT(LOG_TRACE,__VA_ARGS__)
#define LOG_OUT stdout
#define LOG_LEVEL_SCOPE(x) (LOG_TRACE<=(x)&&(x)<=LOG_ERROR)

#endif //SANDBOX_LOG_H
