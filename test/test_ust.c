/**
 * @author: 徐南木
 * @date: 2022/1/22 23:28
 * @description: 
 */
#define LOG_TAG "main"
#include <uts.h>
#include <unity.h>
#include <sys/utsname.h>
__attribute((constructor(1))) void start_log(){
    /* close printf buffer */
    setbuf(stdout, NULL);
    /* initialize EasyLogger */
    elog_init();
    /* set EasyLogger log format */
    elog_set_fmt(ELOG_LVL_ASSERT, ELOG_FMT_ALL);
    elog_set_fmt(ELOG_LVL_ERROR, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_WARN,  ELOG_FMT_TAG|ELOG_FMT_LVL  | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_INFO, ELOG_FMT_LVL | ELOG_FMT_TAG | ELOG_FMT_TIME);
    elog_set_fmt(ELOG_LVL_DEBUG, ELOG_FMT_ALL &~ELOG_FMT_FUNC);
    elog_set_fmt(ELOG_LVL_VERBOSE, ELOG_FMT_ALL  );
#ifdef ELOG_COLOR_ENABLE
    elog_set_text_color_enabled(true);
#endif
    /* start EasyLogger */
    elog_start();
}
void setUp(void) {
    printf("-------------------------\n");
}

void tearDown(void) {
    printf("\n================================");
}
void test_create_uts_1(){
    //start_log();
    system("umount ~/ns/ust");
    struct uts uts ={
            .path="~/ns/ust",
            .hostname="test_ust",
            .domainname="test_domainname"
    };
    if(create_uts(&uts) == false) printf("create_uts(&uts)失败\n");
    int fd = open(uts.path,O_RDONLY);
    if (setns(fd,CLONE_NEWUTS)==-1) perror("setns()\n");
    struct utsname get;
    if (uname(&get)==-1) perror("uname()\n");
    printf("[%s,%s],[%s,%s]\n",uts.hostname,get.nodename,uts.domainname,get.domainname);
    TEST_ASSERT_EQUAL_CHAR_ARRAY_MESSAGE(uts.hostname, get.nodename, strlen(uts.hostname),"hostname:test_ust");
    TEST_ASSERT_EQUAL_CHAR_ARRAY_MESSAGE(uts.domainname, get.domainname, strlen(uts.domainname),"domainname:test_domainname");
}

void test_create_uts_2(){
    system("umount ~/ns/ust");
    struct uts uts ={
            .path="~/ns/ust",
            .hostname="test_ust",
            .domainname=NULL
    };
    if(create_uts(&uts) == false) printf("create_uts(&uts)失败\n");
    int fd = open(uts.path,O_RDONLY);
    if (setns(fd,CLONE_NEWUTS)==-1) perror("setns()\n");
    struct utsname get;
    if (uname(&get)==-1) perror("uname()\n");
    printf("[%s,%s],[%s,%s]\n",uts.hostname,get.nodename,uts.domainname,get.domainname);
    TEST_ASSERT_EQUAL_CHAR_ARRAY_MESSAGE(uts.hostname, get.nodename, strlen(uts.hostname),"hostname:test_ust");
    TEST_ASSERT_EQUAL_CHAR_ARRAY_MESSAGE(uts.domainname, get.domainname, strlen(uts.domainname),"domainname:NULL");
}

void test_create_uts_3(){
    system("umount ~/ns/ust");
    struct uts uts ={
            .path="~/ns/ust",
            .hostname=NULL,
            .domainname="test_domainname"
    };
    if(create_uts(&uts) == false) printf("create_uts(&uts)失败\n");
    int fd = open(uts.path,O_RDONLY);
    if (setns(fd,CLONE_NEWUTS)==-1) perror("setns()\n");
    struct utsname get;
    if (uname(&get)==-1) perror("uname()\n");
    printf("[%s,%s],[%s,%s]\n",uts.hostname,get.nodename,uts.domainname,get.domainname);
    TEST_ASSERT_EQUAL_CHAR_ARRAY_MESSAGE(uts.hostname, get.nodename, strlen(uts.hostname),"hostname:NULL");
    TEST_ASSERT_EQUAL_CHAR_ARRAY_MESSAGE(uts.domainname, get.domainname, strlen(uts.domainname),"domainname:test_domainname");
}
void test_create_uts_4(){
    system("umount ~/ns/ust");
    struct uts uts ={
            .path="~/ns/ust",
            .hostname=NULL,
            .domainname=NULL
    };
    if(create_uts(&uts) == false) printf("create_uts(&uts)失败\n");
    int fd = open(uts.path,O_RDONLY);
    if (setns(fd,CLONE_NEWUTS)==-1) perror("setns()\n");
    struct utsname get;
    if (uname(&get)==-1) perror("uname()\n");
    printf("[%s,%s],[%s,%s]\n",uts.hostname,get.nodename,uts.domainname,get.domainname);
    TEST_ASSERT_EQUAL_CHAR_ARRAY_MESSAGE(uts.hostname, get.nodename, strlen(uts.hostname),"hostname:NULL");
    TEST_ASSERT_EQUAL_CHAR_ARRAY_MESSAGE(uts.domainname, get.domainname, strlen(uts.domainname),"domainname:NULL");
}
int main(int argc, char *argv[]) {
    UNITY_BEGIN();
    RUN_TEST(test_create_uts_1,1);
    RUN_TEST(test_create_uts_2);
    RUN_TEST(test_create_uts_3);
    RUN_TEST(test_create_uts_4);
    return UNITY_END();
}