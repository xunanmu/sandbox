/**
 * @author: 徐南木
 * @date: 2022/1/22 23:01
 * @description: 
 */

/* demo_uts_namespaces.c

   Copyright 2013, Michael Kerrisk
   Licensed under GNU General Public License v2 or later

   Demonstrate the operation of UTS namespaces.
*/
#define _GNU_SOURCE
#include <sys/wait.h>
#include <sys/utsname.h>
#include <sched.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* A simple error-handling function: print an error message based
   on the value in 'errno' and terminate the calling process */

#define errExit(msg)    do { perror(msg); exit(EXIT_FAILURE); \
                        } while (0)

static int              /* Start function for cloned child */
childFunc(void *arg)
{
    struct utsname uts;

    /* 在新的 UTS namespace 中修改主机名 */

    if (sethostname(arg, strlen(arg)) == -1)
        errExit("sethostname");

    /* 获取并显示主机名 */

    if (uname(&uts) == -1)
        errExit("uname");
    printf("uts.nodename in child:  %s\n", uts.nodename);

    /* Keep the namespace open for a while, by sleeping.
       This allows some experimentation--for example, another
       process might join the namespace. */

    sleep(100);

    return 0;           /* Terminates child */
}

/* 定义一个给 clone 用的栈，栈大小1M */
#define STACK_SIZE (1024 * 1024)

static char child_stack[STACK_SIZE];

int
main(int argc, char *argv[])
{
    pid_t child_pid;
    struct utsname uts;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <child-hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* 调用 clone 函数创建一个新的 UTS namespace，其中传出一个函数，还有一个栈空间（为什么传尾指针，因为栈是反着的）;
       新的进程将在用户定义的函数 childFunc() 中执行 */

    child_pid = clone(childFunc,
                      child_stack + STACK_SIZE,   /* 因为栈是反着的，
                                                   所以传尾指针 */
                      CLONE_NEWUTS | SIGCHLD, argv[1]);
    if (child_pid == -1)
        errExit("clone");
    printf("PID of child created by clone() is %ld\n", (long) child_pid);

    /* Parent falls through to here */

    sleep(1);           /* 给子进程预留一定的时间来改变主机名 */

    /* 显示当前 UTS namespace 中的主机名，和
       子进程所在的 UTS namespace 中的主机名不同 */

    if (uname(&uts) == -1)
        errExit("uname");
    printf("uts.nodename in parent: %s\n", uts.nodename);

    if (waitpid(child_pid, NULL, 0) == -1)      /* 等待子进程结束 */
        errExit("waitpid");
    printf("child has terminated\n");

    exit(EXIT_SUCCESS);
}