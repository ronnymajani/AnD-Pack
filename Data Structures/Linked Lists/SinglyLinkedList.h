/* AnD: Algorithms and Data Structures Pack */

#ifndef AND_PACK_SINGLYLINKEDLIST_H
#define AND_PACK_SINGLYLINKEDLIST_H

#include <stdlib.h>

/**
 * @ingroup datastructures
 * @defgroup singlylinkedlist Singly Linked List
 * @{
 */

/**
 * @file singlylinkedlist.h
 * @brief Singly Linked List header file
 *
 * Category: Data Structures >> Linked Lists >> Singly Linked List
 * Codename: ds_sll
 *
 * The main two data types that the user should be aware off:
 * @ref ds_sll_t
 * @ref ds_sll_node_t
 *
 **/

/* Datatype definitons */
/**
 * Singly Linked List Node datatype
 */
typedef struct ds_sll_node_t {
    /** Pointer to the data being stored in the node.
     * User is responsible for typecasting this pointer appropriately */
    void* element;
    struct ds_sll_node_t* next;  // pointer to the next node in the list
} ds_sll_node_t;

/**
 * Singly Linked List datatype.
 * This struct holds the information that identifies a Singly Linked List
 */
typedef struct ds_sll_t {
    ds_sll_node_t* head;  // pointer to the first node in the linked list
    ds_sll_node_t* tail;  // pointer to the last node in the linked list
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
    DS_SLL_BROKEN_LIST_ERROR /**< Error traversing a singly linked list till the end (the list is broken) */
} ds_sll_error_t;
/* ------------------------------------------------------------------ */


/* Functions */
// Create/Delete
ds_sll_t* ds_sll_newSinglyLinkedList();
ds_sll_node_t* ds_sll_createNode(void* element);
ds_sll_error_t ds_sll_destroySinglyLinkedList(ds_sll_t *linkedList);
// Operations on Node
void* ds_sll_extractElementFromNode(ds_sll_node_t* node);
void ds_sll_storeElementInNode(ds_sll_node_t* node, void* element);
void ds_sll_deleteElement(void* node);
void* ds_sll_copyElement(void* element, const size_t element_size);
// Operations on List
int ds_sll_executeFunctionOnElements(ds_sll_t* linkedList, int (*func)(void*, int));
int ds_sll_calculateLength(ds_sll_t* linkedList);
// Retrieval
ds_sll_node_t* ds_sll_getNodeAtIndex(const ds_sll_t* linkedList, int index);
void* ds_sll_getElementAtIndex(const ds_sll_t* linkedList, int index);
// Append
void ds_sll_appendNode(ds_sll_t* linkedList, ds_sll_node_t* node);
ds_sll_error_t ds_sll_appendElement(ds_sll_t* linkedList, void* element);
ds_sll_error_t ds_sll_appendElementCopy(ds_sll_t* linkedList, void* element, const size_t element_size);
// Insert
ds_sll_error_t ds_sll_insertNodeAtIndex(ds_sll_t* linkedList, ds_sll_node_t* node, int index);
ds_sll_error_t ds_sll_insertElementAtIndex(ds_sll_t* linkedList, void* element, int index);
ds_sll_error_t ds_sll_insertElementCopyAtIndex(ds_sll_t* linkedList, void* element, const size_t element_size, int index);
// Deletion
ds_sll_error_t ds_sll_deleteNodeAtIndex(ds_sll_t* linkedList, int index);
/* ------------------------------------------------------------------ */


/**
 * @}
 */

#endif //AND_PACK_SINGLYLINKEDLIST_H