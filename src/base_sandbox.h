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

/**
 * @brief 网络配置，你可以通过下面网址了解相关信息
 * https://learnku.com/docs/go-micro-build/1.0/explain-the-network-mode-of-vmware-and-docker/8879
 */
struct net{
    char *path;
    enum {
        host   = 0,         /*主机模式，即与宿主机IP一样*/
        bridge = 1,         /*桥接模式，与宿主机处于同一个网段下*/
        nat    = 2,         /*nat模式，即创建虚拟交换机，默认10.10.0.0*/
        none   = 4,         /*无网模式，就存在一个lo本地环回设备*/
    }net_mode;              /* nat|none,能实现类似VMware的主机模式*/
    unsigned char ipv4[4];  /*ipv4,ipv6默认可以不用设置，host，none设置无效，目前暂时不支持IPV6*/
    unsigned char ipv6[];   /*bridge设置IP必须在同一网段下，nat设置IP若无交换机网段则重新创建虚拟交换机*/
};

struct pid{
    char *path;
};

struct user {
    char *path;
};

struct uts{
    char *path;
    char *hostname;   /*主机名*/
    char *domainname; /*NIS域名https://blog.csdn.net/qq_41959899/article/details/105948440*/
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
    cgroup *cgroup;
    ipc    *ipc;
    mnt    *mnt;
    net    *net;
    pid    *pid;
    user   *user;
    uts    *uts;
    time   *time;
};


#endif //SANDBOX_BASE_SANDBOX_H
