/**
 * @author: 徐南木
 * @date: 2022/1/20 16:43
 * @description: 
 */

#ifndef SANDBOX_IPC_H
#define SANDBOX_IPC_H

#include <stdbool.h>

struct ipc{
    char *path;
};

bool create_ipc(struct ipc *ipc);
#endif //SANDBOX_IPC_H
