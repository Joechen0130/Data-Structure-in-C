#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include "Single_Linked_list.h"
#include "Single_Linked_List_dump.h"
#include <stdio.h>

/* ----------- 測試普通 Linked List ----------- */
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

void test_delete_basic() {
    node* head = NULL;
    insertEnd(&head, 10);
    insertEnd(&head, 20);
    deleteBeginning(&head);
    CU_ASSERT(head->data == 20);
    deleteEnd(&head);
    CU_ASSERT(head == NULL);
}

/* ----------- 測試 dummy head Linked List ----------- */
void test_add_and_get_dump() {
    node* list = myLinkedListCreate();
    myLinkedListAddAtHead(list, 10);
    myLinkedListAddAtTail(list, 20);
    myLinkedListAddAtIndex(list, 1, 15); // 10->15->20
    CU_ASSERT_EQUAL(myLinkedListGet(list, 0), 10);
    CU_ASSERT_EQUAL(myLinkedListGet(list, 1), 15);
    CU_ASSERT_EQUAL(myLinkedListGet(list, 2), 20);
    CU_ASSERT_EQUAL(myLinkedListGet(list, 3), -1);
    myLinkedListFree(list);
}

void test_delete_dump() {
    node* list = myLinkedListCreate();
    myLinkedListAddAtHead(list, 1);
    myLinkedListAddAtHead(list, 2); // 2->1
    myLinkedListDeleteAtIndex(list, 0); // 1
    CU_ASSERT_EQUAL(myLinkedListGet(list, 0), 1);
    myLinkedListDeleteAtIndex(list, 0); // empty
    CU_ASSERT_EQUAL(myLinkedListGet(list, 0), -1);
    myLinkedListDeleteAtIndex(list, 0); // still safe
    CU_ASSERT_EQUAL(myLinkedListGet(list, 0), -1);
    myLinkedListFree(list);
}

/* ---------------- Main ---------------- */
int main() {
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    CU_pSuite suite1 = CU_add_suite("Normal LinkedList Suite", 0, 0);
    CU_pSuite suite2 = CU_add_suite("Dummy Head LinkedList Suite", 0, 0);

    if (!suite1 || !suite2) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add tests to suite1
    CU_add_test(suite1, "Insert and Print", test_insert_and_print);
    CU_add_test(suite1, "Reverse List", test_reverse);
    CU_add_test(suite1, "Delete Operations", test_delete_basic);

    // Add tests to suite2
    CU_add_test(suite2, "Add and Get", test_add_and_get_dump);
    CU_add_test(suite2, "Delete Nodes", test_delete_dump);

    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return 0;
}
