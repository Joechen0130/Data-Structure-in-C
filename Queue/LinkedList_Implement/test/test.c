// test.c
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "Queue_linkedlist.h"
// 測試初始化
void test_initQueue(void) {
    Queue q;
    initQueue(&q);
    CU_ASSERT_TRUE(isEmpty(&q));
    CU_ASSERT_PTR_NULL(q.front);
    CU_ASSERT_PTR_NULL(q.rear);
}

// 測試 enqueue 與 dequeue 的基本操作
void test_enqueue_dequeue(void) {
    Queue q;
    initQueue(&q);

    enQueue(&q, 100);
    enQueue(&q, 200);
    CU_ASSERT_FALSE(isEmpty(&q));

    int a = deQueue(&q);
    int b = deQueue(&q);
    CU_ASSERT_EQUAL(a, 100);
    CU_ASSERT_EQUAL(b, 200);
    CU_ASSERT_TRUE(isEmpty(&q));
}

// 測試多次 enqueue / dequeue 是否正確運作
void test_multiple_operations(void) {
    Queue q;
    initQueue(&q);
    for (int i = 0; i < 10; i++) {
        enQueue(&q, i);
    }
    for (int i = 0; i < 10; i++) {
        int val = deQueue(&q);
        CU_ASSERT_EQUAL(val, i);
    }
    CU_ASSERT_TRUE(isEmpty(&q));
}

// 測試 dequeue 空佇列
void test_dequeue_empty(void) {
    Queue q;
    initQueue(&q);
    int val = deQueue(&q);
    CU_ASSERT_EQUAL(val, -1);
    CU_ASSERT_TRUE(isEmpty(&q));
}

int main() {
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_pSuite suite = CU_add_suite("LinkedQueueTestSuite", NULL, NULL);
    CU_add_test(suite, "Test initQueue", test_initQueue);
    CU_add_test(suite, "Test enqueue and dequeue", test_enqueue_dequeue);
    CU_add_test(suite, "Test multiple operations", test_multiple_operations);
    CU_add_test(suite, "Test dequeue empty", test_dequeue_empty);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
