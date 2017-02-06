/**
 * @file singlylinkedlist.c
 * @brief AnD >> Singly Linked List library (ds_sll)
 *
 * Category: Data Structures >> Linked Lists
 * Codename: ds_sll
 *
 * Please familiarize yourself with the fundamental datatypes used throughout:
 * @ref ds_sll_t
 * @ref ds_sll_node_t
 *
 * I follow DbC (Design by Contract) with my code, meaning functions that
 * are called with illogical or invalid arguments will cause the program to abrupt
 * using the assert functionality. Feel free to redefine how assert works
 * to suite your projects needs, or even nullify all the asserts with a macro
 * definition to NDEBUG
 * #define NDEBUG
 *
 * @see ds_sll_t
 * @see ds_sll_node_t
 *
 * Operations:
 * -----------
 * + New: create a new Singly Linked List
 * + Destroy: delete all elements from the Singly Linked List and free all
 * resources
 * - Add: Create a new node with the given element and insert it into the linked list
 * + Append Element: Create a new node with the given element and append it to the linked list
 * + Create Node: Create a new node with the given element
 * - Insert Node: Insert a given node at the specified index
 * + Append Node: Append a given node to the end of the linked list
 * - Delete Node: Delete the node at the given index
 * + Get Node: Get the node at the given index
 * - Extract Element From Node: Extract the element from a given node
 * - Find: Find an element in the linked list using the given equality function
 * - Split: Split the linked list at the given index
 *
 **/

#include <assert.h>
#include <stdlib.h>
#include "SinglyLinkedList.h"

#define ASSERT assert

/**
 * @brief Create a new singly linked list
 * @return Returns a new Singly Linked List struct
 */
ds_sll_t* ds_sll_new()
{
    ds_sll_t* new_list = malloc(sizeof(ds_sll_t));

    new_list->head = NULL;
    new_list->tail = NULL;

    return new_list;
}


/**
 * @brief Create a Node to be used with a singly linked list
 * @param element The element to store in the new node
 * @return A singly linked list compatible node containing the given element
 */
ds_sll_node_t* ds_sll_createNode(void* element)
{
    ds_sll_node_t* newnode = malloc(sizeof(ds_sll_node_t));
    newnode->element = element;
    return newnode;
}


/**
 * @brief Get the node from a singly linked list at a given index
 * @param linkedList The singly linked list to get the node from
 * @param index The index of the node you want to get (starting with 0)
 * @return A pointer to the node at the given index,
 *         or NULL if not found or an error occurred.
 */
ds_sll_node_t* ds_sll_getNodeAtIndex(const ds_sll_t* linkedList, int index)
{
            ASSERT((linkedList != NULL) && (linkedList->head != NULL) && (linkedList->tail != NULL) && (index >= 0));

    ds_sll_node_t* curr = linkedList->head;

    // Traverse the linked list `index` times or until end of list or NULL is reached
    while((curr != NULL) && (curr != linkedList->tail) && (index-- != 0)){
        curr = curr->next;
    }

    // Check if an error occurred
    // If an error occurred, index would have been compared at the end to 0
    // and decremented to -1
    if(index == -1) { // No Error, Element Found
        return curr;
    } else {
        return NULL;
    }
}


/**
 * @brief Destroy a Singly Linked List
 * @param linkedList The singly linked list to destroy
 * @return 0 unless an error occurred (unable to free all nodes)
 * This function will delete all the nodes and deallocate all related memory.
 * Warning, do not use this function if you are sharing any nodes with another list
 * that is currently in use
 */
int ds_sll_destroy(ds_sll_t* linkedList)
{
            ASSERT((linkedList != NULL) && (linkedList->head != NULL) && (linkedList->tail != NULL));

    while((linkedList->head != NULL) && (linkedList->head != linkedList->tail))
    {
        if(linkedList->head->element != NULL) {
            free(linkedList->head->element);
        }
        linkedList->head = linkedList->head->next;
    }

    // free the list's tail
    if(linkedList->tail->element != NULL) {
        free(linkedList->tail->element);
    }

    // check if an error occurred and act accordingly
    if(linkedList-> head == linkedList->tail) {
        linkedList->head = NULL;
        linkedList->tail = NULL;
        return 0;
    } else {
        return -1;
    }
}



/**
 * @brief Append a given node to the end of the given singly linked list
 * @param linkedList The singly linked list to append the node to
 * @param node The node to append to the end of the singly linked list
 */
void ds_sll_appendNode(ds_sll_t* linkedList, ds_sll_node_t* node)
{
    linkedList->tail->next = node;
    linkedList->tail = node;
}


/**
 * @brief Create a new node encapsulating the given element,
 * and append this node to the end of the given singly linked list.
 * @param linkedList
 * @param element
 */
void ds_sll_appendElement(ds_sll_t* linkedList, void* element)
{
    ds_sll_appendNode(linkedList, ds_sll_createNode(element));
}



/**
 * @brief Inserts the given node at the chosen index
 * @param linkedList The singly linked list to insert the node into
 * @param node The node to insert
 * @param index The index where the node should be inserted
 * @return The offset from the given index where the node was inserted,
 * or 0 if inserted at the desired index or -1 if an error occurrs.
 * If the given index was out of bounds, the node will be inserted in
 * the last possible valid location (the tail),
 * unless an error occurrs while traversing the list/
 */
int ds_sll_insertNodeAtIndex(ds_sll_t* linkedList, ds_sll_node_t* node, int index)
{
    ASSERT((linkedList != NULL) && (linkedList->head != NULL) && (linkedList->tail != NULL) && (index >= 0));

    ds_sll_node_t* curr = linkedList->head;

    // Traverse the linked list `index` times or until end of list or NULL is reached
    while((curr != NULL) && (curr != linkedList->tail) && (index-- != 0)){
        curr = curr->next;
    }

    // Check if an error occurred
    // If an error occurred, index would have been compared at the end to 0
    // and decremented to -1
    if(curr == NULL) {
        return -1;
    }
    else if(index == -1) { // No Error, Element Found
        node->next = curr->next;
        curr->next = node;
        if(curr == linkedList->tail) {
            // adjust the linkedList struct's tail pointer if we inserted the
            // given node as the tail of the list
            linkedList->tail = node;
        }
        return 0;
    }
    else if(curr == linkedList->tail) { // Reached end of list
        curr->next = node;
        linkedList->tail = node;
        // return index + 1 because the traversal loop above
        // brought index down to -1 instead of 0
        return (index + 1);
    }
    else { // Another Error Occurred
        return -1;
    }
}
