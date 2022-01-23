/**
 * @author: 徐南木
 * @date: 2022/1/20 16:45
 * @description: 
 */

#include "uts.h"
#define LOG_TAG "main"

/**
 * @brief
 * @param uts
 * @return 成功返回0，失败返回-1；
 */
int set_ust(struct uts *uts) {
    int flag = sethostname(uts->hostname, strlen(uts->hostname));
    if (flag == -1) {
        log_e("set hostname fail.");
        return flag;
    }
    flag = setdomainname(uts->domainname, strlen(uts->domainname));
    if (flag == -1) {
        log_e("set hostname fail.");
        return flag;
    }
    /*验证路径,没有就创建*/
    if(create_file(uts->path) == false){
        return -1;
    }
    char source[256];
    sprintf(source, "/proc/%d/ns/uts", getpid());
    flag = mount(source, uts->path, "nsfs", MS_BIND, "ro");/*https://www.cnblogs.com/SchrodingerDoggy/p/13597572.html*/
    if (flag == -1) {
        perror("");
        log_e("mount uts fail.[%s,%s]", source, uts->path);
        return flag;
    }
    log_i("set uts success,{path:%s,hostname:%s,domainname:%s}", uts->path, uts->hostname, uts->domainname);
    return flag;
}

int enter_ust(void *uts) {
    int flag = set_ust(uts);
    if (flag == -1){
        log_e("set uts fail.[flag:%d]",flag);
    }
    exit(flag);
}

int clone_ust(struct uts *uts) {
    int status = 0;
    void *child_stack = malloc(MiB(1));
    if (child_stack == NULL) {
        log_e("malloc(MiB(1)) fail.");
        return -1;
    }
    log_t("clone 前");
    pid_t pid = clone(enter_ust, child_stack + MiB(1), CLONE_NEWUTS | SIGCHLD, uts);
    log_t("clone 后");
    if (pid == -1) {
        log_e("clone ust fail.");
        return -1;
    }

    if (waitpid(pid, &status, 0) == -1) {
        log_e("[waitpid:%d] fail.", pid);
        return -1;
    }
    log_i("[status:%d]", WEXITSTATUS(status));
    return WEXITSTATUS(status);
}

bool create_uts(struct uts *uts) {
    log_i("start create uts={path:%s,hostname:%s,domainname:%s}",uts->path,uts->hostname,uts->domainname);
    return clone_ust(uts) == 0;
}
