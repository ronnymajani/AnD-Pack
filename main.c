#include <stdio.h>
#include "Data Structures/Linked Lists/SinglyLinkedList.h"

ds_sll_func_return_t printElement(void* element, int index, void* extra) {
    printf("%d >> %d\n", index, *((int*)element));
    return DS_SLL_CONTINUE_EXECUTION;
}

int equals(void* elem1, void* elem2) {
    return *((int*)elem1) == *((int*)elem2);
}

int main() {
    ds_sll_t* mylist = ds_sll_newSinglyLinkedList();
    ds_sll_t* newlist = ds_sll_newSinglyLinkedList();
    int x, index;
    ds_sll_error_t err;
    ds_sll_node_t *node;

    x = 111;
    err = ds_sll_insertElementCopyAtIndex(mylist, &x, sizeof(int), 0);
    printf("element %d inserted at index %d\n", x, 0);

    x = 75;
    ds_sll_appendElementCopy(mylist, &x, sizeof(int));
    x = 23;
    ds_sll_appendElementCopy(mylist, &x, sizeof(int));
    x = 63;
    ds_sll_appendElementCopy(mylist, &x, sizeof(int));

    ds_sll_executeFunctionOnElements(mylist, printElement, NULL);
    printf("---------------\n");

    ds_sll_deleteNodeAtIndex(mylist, 1);
    printf("node %d deleted from list\n", 1);

    ds_sll_executeFunctionOnElements(mylist, printElement, NULL);
    printf("---------------\n");

    x = 77;
    ds_sll_appendElementCopy(mylist, &x, sizeof(int));
    x = 91;
    ds_sll_appendElementCopy(mylist, &x, sizeof(int));
    x = 77;
    ds_sll_appendElementCopy(mylist, &x, sizeof(int));

    ds_sll_executeFunctionOnElements(mylist, printElement, NULL);
    printf("---------------\n");

    x = 444;
    err = ds_sll_insertElementCopyAtIndex(mylist, &x, sizeof(int), 4);
    printf("element %d inserted at index %d\n", x, 4);

    ds_sll_executeFunctionOnElements(mylist, printElement, NULL);
    printf("---------------\n");

    void* res = ds_sll_getElementAtIndex(mylist, 2);
    if(res != NULL) {
        printf("Node 2 is: %d\n", *((int *) res));
    } else {
        printf("Index out of bounds!\n");
    }

    printf("List has %d nodes\n", ds_sll_calculateLength(mylist));

    x = 77;
    node = ds_sll_findNodeContainingElement(mylist, &x, equals, &index);
    printf("\nelement %d found at index %d <%d>\n", x, index, *((int*)node->element));
    node = ds_sll_findNodeContainingElement(mylist, NULL, equals, &index);
    printf("element %d also found at index %d <%d>\n\n", x, index, *((int*)node->element));

    ds_sll_splitSinglyLinkedListAtIndex(mylist, newlist, 3);
    printf("split list at index %d\n", 3);

    ds_sll_executeFunctionOnElements(mylist, printElement, NULL);
    printf("+++++++++++++++\n");
    ds_sll_executeFunctionOnElements(newlist, printElement, NULL);
    printf("---------------\n");

    ds_sll_destroySinglyLinkedList(mylist);
    ds_sll_destroySinglyLinkedList(newlist);

    printf("Hello, World!\n");
    return 0;
}