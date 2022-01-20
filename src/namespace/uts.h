/**
 * @author: 徐南木
 * @date: 2022/1/20 16:45
 * @description: 
 */

#ifndef SANDBOX_UTS_H
#define SANDBOX_UTS_H

struct uts{
    char *path;
    char *hostname;   /*主机名*/
    char *domainname; /*NIS域名https://blog.csdn.net/qq_41959899/article/details/105948440*/
};
#endif //SANDBOX_UTS_H
