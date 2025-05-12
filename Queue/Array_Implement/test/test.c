// test.c
#include <stdio.h>
#include "Queue_array.h"
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>


void test_queue_init(void) {
    Queue q;
    initQueue(&q);
    CU_ASSERT_TRUE(IsEmpty(&q));
    CU_ASSERT_FALSE(IsFull(&q));
}

void test_queue_enqueue_dequeue(void) {
    Queue q;
    initQueue(&q);
    
    enQueue(&q, 10);
    enQueue(&q, 20);
    CU_ASSERT_FALSE(IsEmpty(&q));
    
    int d1 = deQueue(&q);
    int d2 = deQueue(&q);
    
    CU_ASSERT_EQUAL(d1, 10);
    CU_ASSERT_EQUAL(d2, 20);
    CU_ASSERT_TRUE(IsEmpty(&q));
}

void test_queue_overflow_underflow(void) {
    Queue q;
    initQueue(&q);
    
    // 填滿佇列
    for (int i = 0; i < MAX; i++)
        enQueue(&q, i);
    CU_ASSERT_TRUE(IsFull(&q));

    // 嘗試超出範圍（觀察錯誤輸出）
    enQueue(&q, 99);  // 不應崩潰

    // 清空佇列
    for (int i = 0; i < MAX; i++)
        deQueue(&q);
    CU_ASSERT_TRUE(IsEmpty(&q));

    // 嘗試取空資料
    int val = deQueue(&q); // 應該返回 -1
    CU_ASSERT_EQUAL(val, -1);
}

int main() {
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_pSuite suite = CU_add_suite("Queue Test Suite", 0, 0);
    CU_add_test(suite, "Test Queue Initialization", test_queue_init);
    CU_add_test(suite, "Test Enqueue and Dequeue", test_queue_enqueue_dequeue);
    CU_add_test(suite, "Test Overflow and Underflow", test_queue_overflow_underflow);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}
