// test.c
#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "Queue_circular_array.h"

// 測試初始化
void test_initQueue(void) {
    Queue q;
    initQueue(&q);
    CU_ASSERT_TRUE(IsEmpty(&q));
    CU_ASSERT_FALSE(IsFull(&q));
}

// 測試 enqueue / dequeue 正常流程
void test_enqueue_dequeue(void) {
    Queue q;
    initQueue(&q);

    enQueue(&q, 10);
    enQueue(&q, 20);
    CU_ASSERT_FALSE(IsEmpty(&q));

    int a = deQueue(&q);
    int b = deQueue(&q);
    CU_ASSERT_EQUAL(a, 10);
    CU_ASSERT_EQUAL(b, 20);
    CU_ASSERT_TRUE(IsEmpty(&q));
}

// 測試 overflow 行為
void test_overflow(void) {
    Queue q;
    initQueue(&q);

    for (int i = 0; i < MAX; i++) {
        enQueue(&q, i);
    }
    CU_ASSERT_TRUE(IsFull(&q));

    enQueue(&q, 999); // 應該不會加入，queue仍然是滿的
    CU_ASSERT_TRUE(IsFull(&q));
}

// 測試 underflow 行為
void test_underflow(void) {
    Queue q;
    initQueue(&q);

    int result = deQueue(&q); // 嘗試從空佇列取資料
    CU_ASSERT_EQUAL(result, -1);
}

int main() {
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_pSuite suite = CU_add_suite("Queue Tests", NULL, NULL);
    CU_add_test(suite, "Initialize Queue", test_initQueue);
    CU_add_test(suite, "Enqueue and Dequeue", test_enqueue_dequeue);
    CU_add_test(suite, "Queue Overflow", test_overflow);
    CU_add_test(suite, "Queue Underflow", test_underflow);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
