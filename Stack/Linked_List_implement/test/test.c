#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "Stack_linkedlist.h"

// 測試 push 和 pop 的基本功能
void test_push_and_pop() {
    Stack s;
    initStack(&s);
    push(&s, 10);
    push(&s, 20);

    CU_ASSERT_FALSE(isEmpty(&s));
    CU_ASSERT_EQUAL(pop(&s), 20);
    CU_ASSERT_EQUAL(pop(&s), 10);
    CU_ASSERT_TRUE(isEmpty(&s));
}

// 測試 underflow 狀況
void test_underflow() {
    Stack s;
    initStack(&s);
    int value = pop(&s);  // 預期為 -1
    CU_ASSERT_EQUAL(value, -1);
    CU_ASSERT_TRUE(isEmpty(&s));
}

int main() {
    // 初始化測試註冊
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_pSuite suite = CU_add_suite("LinkedList Stack Test", 0, 0);
    if (NULL == suite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // 加入測試
    CU_add_test(suite, "Test push and pop", test_push_and_pop);
    CU_add_test(suite, "Test underflow", test_underflow);

    // 執行測試
    CU_basic_set_mode(CU_BRM_VERBOSE);
    int ret = CU_basic_run_tests();
    CU_cleanup_registry();
    return ret;
}
