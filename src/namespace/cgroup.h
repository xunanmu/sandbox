/**
 * @author: 徐南木
 * @date: 2022/1/20 16:41
 * @description: 
 */

#ifndef SANDBOX_CGROUP_H
#define SANDBOX_CGROUP_H


struct cgroup {
    char *path;                      /*路径*/
    char cpus[8];                    /*绑定cpu编号*/
    unsigned long pidsLimit;         /*最大pid数*/
    unsigned long memoryLimit;       /*最大内存，单位字节*/
};
#endif //SANDBOX_CGROUP_H
