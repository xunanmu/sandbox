/**
 * @author: 徐南木
 * @date: 2022/1/22 23:28
 * @description: 
 */
#define _GNU_SOURCE
#include <unity.h>
#include <unistd.h>
#include <sched.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/utsname.h>
#include "namespace/uts.h"

void setUp(void) {
    printf("-------------------------------------------------------------------------\n");
}

void tearDown(void) {
    printf("\n========================================================================\n");

}
extern int set_ust(struct uts *uts);

void test_create_uts_1(){
    struct uts uts ={
            .path="/root/ns/uts",
            .hostname="test_uts",
            .domainname="test_domainname"
    };
    if(create_uts(&uts) == false) printf("create_uts(&uts)失败\n");
    int fd = open(uts.path,O_RDONLY);
    if (setns(fd,CLONE_NEWUTS)==-1) perror("setns()\n");
    struct utsname get;
    if (uname(&get)==-1) perror("uname()\n");
    printf("[%s,%s],[%s,%s]\n",uts.hostname,get.nodename,uts.domainname,get.domainname);
    TEST_ASSERT_EQUAL_CHAR_ARRAY_MESSAGE(uts.hostname, get.nodename, strlen(uts.hostname),"hostname:test_uts");
    TEST_ASSERT_EQUAL_CHAR_ARRAY_MESSAGE(uts.domainname, get.domainname, strlen(uts.domainname),"domainname:test_domainname");
}

void test_create_uts_2(){
    struct uts uts ={
            .path="/root/ns/uts",
            .hostname="test_uts",
            .domainname=NULL
    };
    struct utsname host,get;
    if (uname(&host)==-1) perror("uname()\n");
    if(create_uts(&uts) == false) printf("create_uts(&uts)失败\n");
    sleep(1);
    int fd = open(uts.path,O_RDONLY);
    if (setns(fd,CLONE_NEWUTS)==-1) perror("setns()\n");
    if (uname(&get)==-1) perror("uname()\n");
    printf("[%s,%s],[%s,%s]\n",uts.hostname,get.nodename,host.domainname,get.domainname);
    TEST_ASSERT_EQUAL_CHAR_ARRAY_MESSAGE(uts.hostname, get.nodename, strlen(uts.hostname),"hostname:test_uts");
    TEST_ASSERT_EQUAL_CHAR_ARRAY_MESSAGE(host.domainname, get.domainname, strlen(get.domainname),"domainname:NULL");
}

void test_create_uts_3(){
    struct uts uts ={
            .path="/root/ns/uts",
            .hostname=NULL,
            .domainname="test_domainname"
    };
    struct utsname host,get;
    if (uname(&host)==-1) perror("uname()\n");
    if(create_uts(&uts) == false) printf("create_uts(&uts)失败\n");
    int fd = open(uts.path,O_RDONLY);
    if (setns(fd,CLONE_NEWUTS)==-1) perror("setns()\n");
    if (uname(&get)==-1) perror("uname()\n");
    printf("[%s,%s],[%s,%s]\n",host.nodename,get.nodename,uts.domainname,get.domainname);
    TEST_ASSERT_EQUAL_CHAR_ARRAY_MESSAGE(host.nodename, get.nodename, strlen(get.nodename),"hostname:NULL");
    TEST_ASSERT_EQUAL_CHAR_ARRAY_MESSAGE(uts.domainname, get.domainname, strlen(get.domainname),"domainname:test_domainname");
}

void test_create_uts_4(){
    struct uts uts ={
            .path="/root/ns/uts",
            .hostname=NULL,
            .domainname=NULL
    };
    struct utsname host,get;
    if (uname(&host)==-1) perror("uname()\n");
    if(create_uts(&uts) == false) printf("create_uts(&uts)失败\n");
    int fd = open(uts.path,O_RDONLY);
    if (setns(fd,CLONE_NEWUTS)==-1) perror("setns()\n");
    if (uname(&get)==-1) perror("uname()\n");
    printf("[%s,%s],[%s,%s]\n",uts.hostname,get.nodename,uts.domainname,get.domainname);
    TEST_ASSERT_EQUAL_CHAR_ARRAY_MESSAGE(host.nodename, get.nodename, strlen(get.nodename),"hostname:NULL");
    TEST_ASSERT_EQUAL_CHAR_ARRAY_MESSAGE(host.domainname, get.domainname, strlen(get.domainname),"domainname:NULL");
}

void test_create_uts_5(){
    struct uts uts ={
            .path="/root/ns/uts",
            .hostname="",
            .domainname=""
    };
    struct utsname host,get;
    if (uname(&host)==-1) perror("uname()\n");
    if(create_uts(&uts) == false) printf("create_uts(&uts)失败\n");
    int fd = open(uts.path,O_RDONLY);
    if (setns(fd,CLONE_NEWUTS)==-1) perror("setns()\n");
    if (uname(&get)==-1) perror("uname()\n");
    printf("[%s,%s],[%s,%s]\n",uts.hostname,get.nodename,uts.domainname,get.domainname);
    TEST_ASSERT_EQUAL_CHAR(uts.hostname[0], get.nodename[0]);
    TEST_ASSERT_EQUAL_CHAR(uts.domainname[0], get.domainname[0]);
}
int main(int argc, char *argv[]) {
    UNITY_BEGIN();
    RUN_TEST(test_create_uts_1);
    RUN_TEST(test_create_uts_2);
    RUN_TEST(test_create_uts_3);
    RUN_TEST(test_create_uts_4);
    RUN_TEST(test_create_uts_5);
    return UNITY_END();

}