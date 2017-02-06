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
    ds_sll_t* mylist = ds_sll_new();
    int x = 75;

    ds_sll_appendElementCopy(mylist, &x, sizeof(int));
    x = 23;
    ds_sll_appendElementCopy(mylist, &x, sizeof(int));
    x = 63;
    ds_sll_appendElementCopy(mylist, &x, sizeof(int));
    x = 77;
    ds_sll_appendElementCopy(mylist, &x, sizeof(int));
    x = 91;
    ds_sll_appendElementCopy(mylist, &x, sizeof(int));
    x = 234155;
    ds_sll_appendElementCopy(mylist, &x, sizeof(int));

    ds_sll_executeFunctionOnElements(mylist, printElement);

    void* res = ds_sll_getElementAtIndex(mylist, 6);
    if(res != NULL) {
        printf("Node 4 is: %d\n", *((int *) res));
    } else {
        printf("Index out of bounds!\n");
    }

    printf("List has %d nodes\n", ds_sll_calculateLength(mylist));

    ds_sll_destroy(mylist);

    printf("Hello, World!\n");
    return 0;
}