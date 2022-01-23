/**
 * @author: 徐南木
 * @date: 2022/1/20 16:45
 * @description: 
 */

#ifndef SANDBOX_UTS_H
#define SANDBOX_UTS_H
#include "base_sandbox.h"

struct uts{
    char *path;
    char *hostname;   /*主机名*/
    char *domainname; /* https://docs.freebsd.org/en/books/handbook/network-servers/#network-nis
                       * NIS域名https://blog.csdn.net/qq_41959899/article/details/105948440*/
};

/**
 * @brief 创建一个ust空间
 * @param uts 是个指针
 * @param ust->path，必须要有否则无法挂载路径
 * @param uts->hostname,如果NULL则默认主机名
 * @param uts->domainname,如果NULL则默认域
 * @return bool
 */
bool create_uts(struct uts* uts);
#endif //SANDBOX_UTS_H
