/**
 * @author: 徐南木
 * @date: 2022/2/8 23:23
 * @description: 
 */
#include <unity.h>
#include <stdlib.h>
#include "utils/utils.h"
void setUp(void) {
    system("pwd");
    printf("-------------------------------------------------------------------------\n");
}

void tearDown(void) {
    printf("\n========================================================================\n");

}

void test_is_same_inode(){
    system("mount --bind /proc/self/ns/uts /root/ns/uts");
    TEST_ASSERT_EQUAL_UINT8(is_same_inode("/root/ns/uts","/proc/self/ns/uts"), true);
    TEST_ASSERT_EQUAL_UINT8(is_same_inode("/root/ns/uts","/proc/self/ns/pid"), false);
    system("umount /root/ns/uts");
}

int main(int argc, char *argv[]) {
    UNITY_BEGIN();
    RUN_TEST(test_is_same_inode);
    return UNITY_END();

}