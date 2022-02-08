/**
 * @author: 徐南木
 * @date: 2022/1/20 16:43
 * @description: 
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <sys/mount.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <sched.h>
#include "ipc.h"
#include "utils/utils.h"
#include "log/log.h"

bool set_ipc(struct ipc *ipc) {
    int flag = 0;
    if (create_file(ipc->path) == false) {
        return -1;
    }
    char source[256];
    sprintf(source, "/proc/%d/ns/ipc", getpid());
    flag = mount(source, ipc->path, "nsfs", MS_BIND, "ro");
    if (flag == -1) {
        perror("");
        log_e("mount ipc fail.[%s,%s]", source, ipc->path);
        return flag;
    }
    log_i("set ipc success,{path:%s}", ipc->path);
    return flag;
}

int enter_ipc(struct ipc *ipc) {
    log_d("start set ipc");
    exit(set_ipc(ipc));
}

bool create_ipc(struct ipc *ipc) {
    int status = -1;
    void *child_stack = malloc(MiB(1));
    if (child_stack == NULL) {
        log_e("malloc(MiB(1)) fail.");
        return -1;
    }
    log_t("clone 前");
    pid_t pid = clone(enter_ipc, child_stack + MiB(1), CLONE_NEWUTS | SIGCHLD, ipc);
    log_t("clone 后");
    if (pid == -1) {
        log_e("clone ipc fail.");
        goto free;
    }
    /*等待子进程*/
    if (waitpid(pid, &status, 0) == -1) {
        log_e("[waitpid:%d] fail.", pid);
        goto free;
    }
    log_i("[status:%d]", WEXITSTATUS(status));
    return WEXITSTATUS(status);
    free:
    free(child_stack);
    return -1;
}
