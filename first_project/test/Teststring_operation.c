//
// Created by Qui Tran on 10/4/23.
//

#include <stdlib.h>
#include "./unity/src/unity.h"
#include "../src/string_operation.h"

void setUp() {

}

void tearDown() {

}
void test_string_concat_valid() {
    char str1[20] = "Hello, ";
    char str2[] = "World!";
    char* result = string_concat(str1, str2);
    TEST_ASSERT_EQUAL_STRING("Hello, World!", result);
}

void test_string_concat_empty() {
    char str1[20] = "";
    char str2[] = "Testing";
    char* result = string_concat(str1, str2);
    TEST_ASSERT_EQUAL_STRING("Testing", result);
}

void test_string_concat_null_input() {
    char* str1 = NULL;
    char str2[] = "World!";
    char* result = string_concat(str1, str2);
    TEST_ASSERT_NULL(result);
}

void test_string_compare_equal(){
    char str1[] = "Hello";
    char str2[] = "Hello";
    int compare_result = string_compare(str1, str2);
    TEST_ASSERT_EQUAL_INT(0,compare_result);
}

void test_string_compare_greater(){
    char str1[] = "abcde";
    char str2[] = "abcd";
    int compare_result = string_compare(str1, str2);
    TEST_ASSERT_GREATER_THAN_INT(0,compare_result);
}

void test_string_compare_less(){
    char str1[] = "abc";
    char str2[] = "abcdef";
    int compare_result = string_compare(str1, str2);
    TEST_ASSERT_LESS_THAN_INT(0, compare_result);
}

int main() {
    UNITY_BEGIN();

    RUN_TEST(test_string_concat_valid);
    RUN_TEST(test_string_concat_empty);
    RUN_TEST(test_string_concat_null_input);
    RUN_TEST(test_string_compare_equal);
    RUN_TEST(test_string_compare_greater);
    RUN_TEST(test_string_compare_less);

    return UNITY_END();
}
