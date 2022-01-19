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

/*空间资源结构体*/
typedef struct cgroup cgroup;
typedef struct ipc ipc;
typedef struct mnt mnt;
typedef struct net net;
typedef struct pid pid;
typedef struct user user;
typedef struct uts uts;
typedef struct time time;

struct cgroup {
    char *path;                      /*路径*/
    char cpus[8];                    /*绑定cpu编号*/
    unsigned long pidsLimit;         /*最大pid数*/
    unsigned long memoryLimit;       /*最大内存，单位字节*/
};

struct ipc{
    char *path;
};

struct mnt {
    char *path;
};

struct net{
    char *path;
};

struct pid{
    char *path;
};

struct user {
    char *path;
};

struct uts{
    char *path;
};

struct time{
    char *path;
};

/*沙盒配置结构体*/
typedef struct sandboxConfig sandboxConfig;
struct sandboxConfig {
    union {
        struct { int flag;int suite; };
        unsigned long id;
    };
    cgroup cgroup;
    ipc ipc;
    mnt mnt;
    net net;
    pid pid;
    user user;
    uts uts;
    time time;
};


#endif //SANDBOX_BASE_SANDBOX_H
