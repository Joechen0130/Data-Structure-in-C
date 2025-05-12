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

    int a = deQueue
