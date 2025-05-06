#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "Single_Linked_list.h"
#include <stdio.h>

void test_insert_and_print() {
    node* head = NULL;
    insertBeginning(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    CU_ASSERT(head->data == 1);
    CU_ASSERT(head->next->data == 2);
    CU_ASSERT(head->next->next->data == 3);
}

void test_reverse() {
    node* head = NULL;
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);
    reverseLinkedList(&head);
    CU_ASSERT(head->data == 3);
    CU_ASSERT(head->next->data == 2);
    CU_ASSERT(head->next->next->data == 1);
}

void test_delete() {
    node* head = NULL;
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    deleteBeginning(&head);
    CU_ASSERT(head->data == 20);
    deleteEnd(&head);
    CU_ASSERT(head == NULL);
}

int main() {
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_pSuite suite = CU_add_suite("LinkedList Test Suite", 0, 0);

    CU_add_test(suite, "Insert and Print", test_insert_and_print);
    CU_add_test(suite, "Reverse List", test_reverse);
    CU_add_test(suite, "Delete Operations", test_delete);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
