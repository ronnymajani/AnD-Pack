#include <stdio.h>
#include "src/SinglyLinkedList.h"

/* Example Executable Functions */
ds_sll_func_return_t printElement(void* element, ds_sll_node_t* node, int index, void* extra) {
    printf("%d >> %d\n", index, *((int*)element));
    return DS_SLL_CONTINUE_EXECUTION;
}

/* Stores the maximum int in `maxElement` */
ds_sll_func_return_t getMaxElement(void* element, ds_sll_node_t* node, int index, void* maxElement) {
    if(element == NULL) {
        return DS_SLL_CONTINUE_EXECUTION;
    }
    else if(maxElement == NULL) {
        *(int*)maxElement = *(int*)element;
    } else if(*(int*)element > *(int*)maxElement) {
        *(int*)maxElement = *(int*)element;
    }
    return DS_SLL_CONTINUE_EXECUTION;
}

/* Sets maxNode to point to the node containing the maximum element */
ds_sll_func_return_t maxNode(void* element, ds_sll_node_t* node, int index, void* maxNode) {
    // maxNode is a pointer to a pointer to a ds_sll_node_t
    ds_sll_node_t **maximum_node_p = (ds_sll_node_t**)maxNode;
    if(element == NULL) {
        return DS_SLL_CONTINUE_EXECUTION;
    }
    else if(*maximum_node_p == NULL) {
        *maximum_node_p = node;
    } else if(*(int*)element > *(int*)ds_sll_extractElementFromNode(*maximum_node_p)) {
        *(ds_sll_node_t**)maxNode = node;
    }
    return DS_SLL_CONTINUE_EXECUTION;
}

typedef struct findNodeFuncParams {
    int input;
    int output_index;
    ds_sll_node_t* output_node;
} findNodeFuncParams;

/* finds the node containing the given element (params->input) and stores a pointer to that node in params->output */
ds_sll_func_return_t findNode(void* element, ds_sll_node_t* node, int index, void* shared) {
    findNodeFuncParams* params = (findNodeFuncParams*)shared;

    if(params->input == *(int*)element) {
        params->output_index = index;
        params->output_node = node;
        return DS_SLL_STOP_EXECUTION;
    } else {
        return DS_SLL_CONTINUE_EXECUTION;
    }
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

    /* Test Executable Functions */
    printf("---------------\n\n");
    // example of getMaxElement
    int *max_element = (int*)malloc(sizeof(int));
    ds_sll_executeFunctionOnElements(mylist, getMaxElement, (void*)max_element);
    printf("Max Element in list: %d\n", *max_element);
    free(max_element);

    // example of maxNode
    ds_sll_node_t* max_node = NULL;
    ds_sll_executeFunctionOnElements(mylist, maxNode, (void*)&max_node);
    int* max_node_element = (int*)ds_sll_extractElementFromNode(max_node);
    printf("Max Element in Max Node is: %d\n", *max_node_element);

    // example of findNode
    findNodeFuncParams* params = (findNodeFuncParams*) malloc(sizeof(findNodeFuncParams));
    params->input = 77;
    ds_sll_executeFunctionOnElements(mylist, findNode, (void*)params);
    printf("Node containing element (%d) is located at index %d\n", params->input, params->output_index);
    free(params);
    printf("\n---------------\n\n");

    /* Split Linked List */
    ds_sll_splitSinglyLinkedListAtIndex(mylist, newlist, 3);
    printf("split list at index %d\n", 3);

    ds_sll_executeFunctionOnElements(mylist, printElement, NULL);
    printf("+++++++++++++++\n");
    ds_sll_executeFunctionOnElements(newlist, printElement, NULL);
    printf("---------------\n");

    ds_sll_destroySinglyLinkedList(&mylist);
    ds_sll_destroySinglyLinkedList(&newlist);

    printf("Hello, World!\n");
    return 0;
}