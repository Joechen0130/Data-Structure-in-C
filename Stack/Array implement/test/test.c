#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <Stack_array.h>

void test_push_and_pop() {
    stack s = { .top = 0 };
    push(&s, 10);
    push(&s, 20);
    CU_ASSERT_EQUAL(s.top, 2);
    CU_ASSERT_EQUAL(pop(&s), 20);
    CU_ASSERT_EQUAL(pop(&s), 10);
    CU_ASSERT_TRUE(isEmpty(&s));
}

void test_overflow() {
    stack s = { .top = 0 };
    for (int i = 0; i < MAX_SIZE + 2; i++) {
        push(&s, i);
    }
    CU_ASSERT_EQUAL(s.top, MAX_SIZE);
}

void test_underflow() {
    stack s = { .top = 0 };
    int value = pop(&s);
    CU_ASSERT_EQUAL(value, -1);
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Stack Test", 0, 0);

    CU_add_test(suite, "Push and Pop", test_push_and_pop);
    CU_add_test(suite, "Overflow Test", test_overflow);
    CU_add_test(suite, "Underflow Test", test_underflow);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
