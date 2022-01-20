/**
 * @author: 徐南木
 * @date: 2021/12/9 16:52
 * @description: 
 */

#ifndef SANDBOX_BASE_SANDBOX_H
#define SANDBOX_BASE_SANDBOX_H

#define KiB(x) (1024*(x))
#define MiB(x) (1024*KiB(x))
#define GiB(x) (1024*MiB(x))
#define TiB(x) (1024*GiB(x))

#define us(x) (1000*(x))
#define ms(x) (1000*us(x))
#define s(x)  (1000*ms(x))
#define m(x)  (60*s(x))
#define h(x)  (60*m(x))

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
