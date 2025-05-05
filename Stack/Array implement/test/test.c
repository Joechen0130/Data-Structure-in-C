#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void test_sample() {
    CU_ASSERT(2 + 2 == 4);
}

int main() {
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Sample Suite", 0, 0);
    CU_add_test(suite, "Basic test", test_sample);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
