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
/* ------------------------------------------------------------------ */


/* Functions */
ds_sll_t* ds_sll_new();
ds_sll_node_t* ds_sll_createNode(void* element);
ds_sll_node_t* ds_sll_getNodeAtIndex(const ds_sll_t* linkedList, int index);
int ds_sll_destroy(ds_sll_t* linkedList);
void ds_sll_appendNode(ds_sll_t* linkedList, ds_sll_node_t* node);
void ds_sll_appendElement(ds_sll_t* linkedList, void* element);
int ds_sll_insertNodeAtIndex(ds_sll_t* linkedList, ds_sll_node_t* node, int index);
/* ------------------------------------------------------------------ */


/**
 * @}
 */

#endif //AND_PACK_SINGLYLINKEDLIST_H