/* AnD: Algorithms and Data Structures Pack */

#ifndef AND_PACK_SINGLYLINKEDLIST_H
#define AND_PACK_SINGLYLINKEDLIST_H

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
    DS_SLL_BROKEN_LIST_ERROR /**< Error traversing a singly linked list till the end (the list is broken) */
} ds_sll_error_t;
/* ------------------------------------------------------------------ */


/* Functions */
ds_sll_t* ds_sll_new();
ds_sll_node_t* ds_sll_createNode(void* element);
ds_sll_node_t* ds_sll_getNodeAtIndex(const ds_sll_t* linkedList, int index);
void* ds_sll_getElementAtIndex(const ds_sll_t* linkedList, int index);
ds_sll_error_t ds_sll_destroy(ds_sll_t* linkedList);
void ds_sll_appendNode(ds_sll_t* linkedList, ds_sll_node_t* node);
ds_sll_error_t ds_sll_appendElement(ds_sll_t* linkedList, void* element);
ds_sll_error_t ds_sll_appendElementCopy(ds_sll_t* linkedList, void* element, size_t element_size);
ds_sll_error_t ds_sll_insertNodeAtIndex(ds_sll_t* linkedList, ds_sll_node_t* node, int index);
int ds_sll_executeFunctionOnElements(ds_sll_t* linkedList, int (*func)(void*, int));
int ds_sll_calculateLength(ds_sll_t* linkedList);
/* ------------------------------------------------------------------ */


/**
 * @}
 */

#endif //AND_PACK_SINGLYLINKEDLIST_H