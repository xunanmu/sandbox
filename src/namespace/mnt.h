/**
 * @author: 徐南木
 * @date: 2022/1/20 16:44
 * @description: 
 */

#ifndef SANDBOX_MNT_H
#define SANDBOX_MNT_H
#include <stdlib.h>

struct volume{
    int mode;
    char *out_path;
    char *in_path;
};
struct volumes{
    size_t size;
    struct volume volume[];
};
struct mnt {
    char *path;
    struct volumes *volumes;
};
#endif //SANDBOX_MNT_H
