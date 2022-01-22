/**
 * @author: 徐南木
 * @date: 2022/1/20 16:45
 * @description: 
 */

#include "uts.h"



/**
 * @brief
 * @param ust
 * @return 成功返回0，失败返回-1；
 */
int set_ust(struct uts *ust) {
    int flag = sethostname(ust->hostname, strlen(ust->hostname));
    if (flag == -1) {
        log_e("set hostname fail.");
        return flag;
    }
    flag = setdomainname(ust->domainname, strlen(ust->domainname));
    if (flag == -1) {
        log_e("set hostname fail.");
        return flag;
    }
    char source[256];
    sprintf(source, "/proc/%d/ns/ust", getpid());
    flag = mount(source, ust->path, "nsfs", MS_BIND, "ro");/*https://www.cnblogs.com/SchrodingerDoggy/p/13597572.html*/
    if (flag == -1) {
        log_e("mount ust fail.[%s,%s]", source, ust->path);
        return flag;
    }
    log_i("set ust success,[path:%s,hostname:%s,domainname:%s]", ust->path, ust->hostname, ust->domainname);
    return flag;
}

int enter_ust(void *uts) {
    int flag = set_ust(uts);
    exit(flag);
}

int clone_ust(struct uts *uts) {
    int status = 0;
    void *child_stack = malloc(MiB(1));
    if (child_stack == NULL) {
        log_e("malloc(MiB(1)) fail.");
        return -1;
    }
    pid_t pid = clone(enter_ust, child_stack + MiB(1), CLONE_NEWUTS | SIGCHLD, uts);
    if (pid == -1) {
        log_e("clone ust fail.");
        return -1;
    }
    if (waitpid(pid, &status, 0) == -1) {
        log_e("[waitpid:%d] fail.", pid);
        return -1;
    }
    log_i("[status:%d]",status);
    return status;
}

bool creat_ust(struct uts *uts) {
    return clone_ust(uts) == 0;
}
