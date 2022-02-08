/**
 * @author: 徐南木
 * @date: 2021/12/9 16:52
 * @description: 
 */

#ifndef SANDBOX_BASE_SANDBOX_H
#define SANDBOX_BASE_SANDBOX_H



/*沙盒配置结构体*/
typedef struct sandboxConfig sandboxConfig;
struct sandboxConfig {
    union {
        struct { int flag;int suite; };
        unsigned long id;
    };
    struct cgroup *cgroup;
    struct ipc    *ipc;
    struct mnt    *mnt;
    struct net    *net;
    struct pid    *pid;
    struct user   *user;
    struct uts    *uts;
    struct time   *time;
};


#endif //SANDBOX_BASE_SANDBOX_H
