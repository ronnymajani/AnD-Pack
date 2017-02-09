#include <stdio.h>
#include "Data Structures/Linked Lists/SinglyLinkedList.h"

int printElement(void* element, int index) {
    printf("%d >> %d\n", index, *((int*)element));
    return 0;
}

void debug() {
    static int i = 0;
    printf("#DEBUG %d\n", i++);
}

int main() {
    ds_sll_t* mylist = ds_sll_newSinglyLinkedList();
    int x;

    x = 75;
    ds_sll_appendElementCopy(mylist, &x, sizeof(int));
    x = 23;
    ds_sll_appendElementCopy(mylist, &x, sizeof(int));
    x = 63;
    ds_sll_appendElementCopy(mylist, &x, sizeof(int));

    ds_sll_executeFunctionOnElements(mylist, printElement);
    printf("---------------\n");

    ds_sll_deleteNodeAtIndex(mylist, 1);
    printf("node %d deleted from list\n", 1);

    ds_sll_executeFunctionOnElements(mylist, printElement);
    printf("---------------\n");

    x = 77;
    ds_sll_appendElementCopy(mylist, &x, sizeof(int));
    x = 91;
    ds_sll_appendElementCopy(mylist, &x, sizeof(int));

    ds_sll_executeFunctionOnElements(mylist, printElement);
    printf("---------------\n");

    x = 444;
    ds_sll_insertElementCopyAtIndex(mylist, &x, sizeof(int), 4);
    printf("element %d inserted at index %d\n", x, 4);
    x = 234155;
    ds_sll_appendElementCopy(mylist, &x, sizeof(int));

    ds_sll_executeFunctionOnElements(mylist, printElement);
    printf("---------------\n");

    void* res = ds_sll_getElementAtIndex(mylist, 2);
    if(res != NULL) {
        printf("Node 2 is: %d\n", *((int *) res));
    } else {
        printf("Index out of bounds!\n");
    }

    printf("List has %d nodes\n", ds_sll_calculateLength(mylist));

    ds_sll_destroySinglyLinkedList(mylist);

    printf("Hello, World!\n");
    return 0;
}