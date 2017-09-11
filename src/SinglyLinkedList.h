/*
The MIT License (MIT)

Copyright (c) 2017 Ronny Majani

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */

#ifndef RM_DS_SLL_SINGLYLINKEDLIST_H
#define RM_DS_SLL_SINGLYLINKEDLIST_H

#include <stdlib.h>

/**
 * @ingroup datastructures
 * @defgroup singlylinkedlist Singly Linked List
 * @{
 */

/**
 * @file SinglyLinkedList.h
 * @brief Singly Linked List library (Header) (ds_sll)
 *
 * Category: Data Structures >> Linked Lists >> Singly Linked List
 * Codename: ds_sll
 *
 * The main two data types that the user should be aware off:
 * @ref ds_sll_t
 * @ref ds_sll_node_t
 *
 **/

/* Datatype definitions */
/**
 * Singly Linked List Node datatype
 */
typedef struct ds_sll_node_t {
    /** Pointer to the data being stored in the node.
     * User is responsible for typecasting this pointer appropriately */
    void* element;
    struct ds_sll_node_t* next;  /**< pointer to the next node in the list */
} ds_sll_node_t;

/**
 * Singly Linked List datatype.
 * This struct holds the information that identifies a Singly Linked List
 */
typedef struct ds_sll_t {
    ds_sll_node_t* head;  /**< pointer to the first node in the linked list */
    ds_sll_node_t* tail;  /**< pointer to the last node in the linked list */
} ds_sll_t;


/**
 * Enum representation of return error codes
 */
typedef enum ds_sll_error_t {
    DS_SLL_NO_ERROR = 0, /**< No Error */
    DS_SLL_NODE_CREATION_ERROR, /**< Error creating a new node */
    DS_SLL_ELEMENT_CREATION_ERROR, /**< Error allocating memory for an element */
    DS_SLL_LIST_CREATION_ERROR, /**< Error creating a new singly linked list */
    DS_SLL_INDEX_OUT_OF_BOUNDS_ERROR, /**< The index is out of bounds */
    DS_SLL_BROKEN_LIST_ERROR, /**< Error traversing a singly linked list till the end (the list is broken) */
    DS_SLL_LIST_TOO_SMALL_ERROR, /**< The length of given singly linked list is too small */
    DS_SLL_FUNCTION_EXECUTION_ERROR /**< A function that was being executed on a Singly Linked List returned an Error */
} ds_sll_error_t;

/**
 * Singly Linked List Function return values.
 * These are the return values that a function mapped to a singly linked list should return
 */
typedef enum ds_sll_func_return_t {
    DS_SLL_CONTINUE_EXECUTION, /**< Function ran successfully. Continue to next node */
    DS_SLL_STOP_EXECUTION, /**< Function has completed it's goal. Stop execution */
    DS_SLL_EXECUTION_ERROR /**< Function encountered an Error */
} ds_sll_func_return_t;
/* ------------------------------------------------------------------ */


/* Functions */
// Create/Delete
ds_sll_t* ds_sll_newSinglyLinkedList();
ds_sll_node_t* ds_sll_createNode(void* element);
ds_sll_error_t ds_sll_destroySinglyLinkedList(ds_sll_t **linkedList_toDelete);
void ds_sll_deleteNode(ds_sll_node_t** node);
ds_sll_error_t ds_sll_deleteNodeAtIndex(ds_sll_t* linkedList, int index);
// Operations on Node
ds_sll_node_t* ds_sll_nextNode(ds_sll_node_t* node);
void* ds_sll_extractElementFromNode(ds_sll_node_t* node);
void ds_sll_storeElementInNode(ds_sll_node_t* node, void* element);
void ds_sll_deleteElement(void** element);
void* ds_sll_copyElement(void* element, const size_t element_size);
// Operations on List
int ds_sll_executeFunctionOnElements(ds_sll_t* linkedList, ds_sll_func_return_t (*func)(void*, ds_sll_node_t*, int, void*), void *sharedData);
int ds_sll_calculateLength(const ds_sll_t* linkedList);
ds_sll_error_t ds_sll_splitSinglyLinkedListAtIndex(ds_sll_t *firstLinkedList, ds_sll_t* secondLinkedList, int index);
// Retrieval and Search
ds_sll_node_t* ds_sll_getNodeAtIndex(const ds_sll_t* linkedList, int index);
void* ds_sll_getElementAtIndex(const ds_sll_t* linkedList, int index);
ds_sll_node_t* ds_sll_findNodeContainingElement(ds_sll_t* linkedList, void* element, int (*equalityFunc)(void*, void*), int *resultIndex);
// Append
void ds_sll_appendNode(ds_sll_t* linkedList, ds_sll_node_t* node);
ds_sll_error_t ds_sll_appendElement(ds_sll_t* linkedList, void* element);
ds_sll_error_t ds_sll_appendElementCopy(ds_sll_t* linkedList, void* element, const size_t element_size);
// Insert
ds_sll_error_t ds_sll_insertNodeAtIndex(ds_sll_t* linkedList, ds_sll_node_t* node, int index);
ds_sll_error_t ds_sll_insertElementAtIndex(ds_sll_t* linkedList, void* element, int index);
ds_sll_error_t ds_sll_insertElementCopyAtIndex(ds_sll_t* linkedList, void* element, const size_t element_size, int index);
// Helper Functions
ds_sll_error_t ds_sll_traverseNodeToIndex(const ds_sll_t* linkedList, ds_sll_node_t** node, int index);
/* ------------------------------------------------------------------ */


/**
 * @}
 */

#endif //RM_DS_SLL_SINGLYLINKEDLIST_H
