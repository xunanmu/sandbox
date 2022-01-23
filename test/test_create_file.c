/**
 * @author: 徐南木
 * @date: 2022/1/23 21:13
 * @description: 
 */

#include <unity.h>
#include <base_sandbox.h>
void setUp(void) {
    system("pwd");
    printf("-------------------------------------------------------------------------\n");
}

void tearDown(void) {
    printf("\n========================================================================\n");

}
void test_create_file(){
    TEST_ASSERT_EQUAL_UINT8(create_file("./hello"),true);
    TEST_ASSERT_EQUAL_UINT8(create_file("../hello"),true);
    TEST_ASSERT_EQUAL_UINT8(create_file("~/hello"),true);
    TEST_ASSERT_EQUAL_UINT8(create_file("/hello"),true);
    TEST_ASSERT_EQUAL_UINT8(create_file("./a/b/c/hello"),true);
    TEST_ASSERT_EQUAL_UINT8(create_file("./hello"),true);
    TEST_ASSERT_EQUAL_UINT8(create_file("+/hello"),true);
    TEST_ASSERT_EQUAL_UINT8(create_file("./_hello"),true);
    TEST_ASSERT_EQUAL_UINT8(create_file("./he_llo"),true);
    TEST_ASSERT_EQUAL_UINT8(create_file("./?hello"),true);
    TEST_ASSERT_EQUAL_UINT8(create_file("./hello/a"),false);
}

int main(int argc, char *argv[]) {
    UNITY_BEGIN();
    RUN_TEST(test_create_file);
    return UNITY_END();
}