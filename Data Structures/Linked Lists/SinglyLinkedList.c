/**
 * @ingroup singlylinkedlist
 * @file SinglyLinkedList.c
 * @brief AnD >> Singly Linked List library (ds_sll)
 *
 * Category: Data Structures >> Linked Lists
 * Codename: ds_sll
 *
 * Please familiarize yourself with the fundamental datatypes used throughout:
 * @ref ds_sll_t
 * @ref ds_sll_node_t
 *
 * ### Usage:
 * This version of singly linked list does not support multiple linked lists being combined manually.
 * eg: appending a node that already exists in the middle of list A to the tail of list B
 * Doing such an operation by logic should automatically mean that list A now contains the same nodes as list B after
 * the common node is traversed, but this version of the data structure can't know where the new tail resides if you do
 * the aforementioned operation as it keeps track of both the head and the tail, and hence you will need to manually update
 * the tail to point to the correct node, which in this case is the tail of list A. An alternative is to use the combine function
 * which deals with the nuisance of correcting the tail pointers appropriately. Also there are plans to implement a headless
 * linked list (a linked list that does not keep track of the head and tail but simply uses any given node to traverse)
 * in the future which allows much more flexibility but at the expense of not knowing whether or not the list is broken or corrupt.
 *
 * ###Note:
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
 * ### Operations:
 * + New: create a new Singly Linked List
 * + Destroy: delete all elements from the Singly Linked List and free all
 * resources
 * + Append Element: Create a new node with the given element and append it to the linked list
 * + Create Node: Create a new node with the given element
 * + Insert Node: Insert a given node at the specified index
 * + Append Node: Append a given node to the end of the linked list
 * + Delete Node: Delete the node at the given index
 * + Get Node: Get the node at the given index
 * + Extract Element From Node: Extract the element from a given node
 * + Find: Find an element in the linked list using the given equality function
 * + Split: Split the linked list at the given index
 * + Execute Function on Elements: Executes the given function on the element of every node
 * + Length Of: Get the length of the linked list
 *
 * ### Abstractions:
 * This library was designed with some abstractions in mind to allow for easy customization according to your
 * project's needs. These abstractions are mainly implemented as inline functions where possible.
 * The main abstractions are:
 * + createNode: allows you to specify how nodes are created
 * + extractElementFromNode: allows you to specify how node elements are read (return node->element)
 * + storeElementInNode: allows you to specify how to insert an element in a node (node->element = new_element)
 * + deleteElement: allows you to specify how to deallocate the resources of a given Element
 * + deleteNode: allows you to specify how a node is 'deleted' and its resources are de-allocated
 * + copyElement: allows you to specify how an Element is copied
 * You can alter these functions along with the node data type to suite the needs of your application
 **/

#include "SinglyLinkedList.h"
#include <assert.h>
#include <memory.h>

/**
 * @brief Macro definition for ASSERT
 * Used to enforce Design by Contract coding
 * Typically disabled on release
 */
#define ASSERT assert

/**
 * @brief Create a new singly linked list
 * @return Returns a pointer to a new Singly Linked List struct (linked list header)
 */
ds_sll_t* ds_sll_newSinglyLinkedList()
{
    ds_sll_t* new_list = (ds_sll_t*) malloc(sizeof(ds_sll_t));

    if(new_list == NULL) {
        return NULL;
    }

    new_list->head = NULL;
    new_list->tail = NULL;

    return new_list;
}


/**
 * @brief Create a Node to be used with a singly linked list
 * @param element The element to store in the new node
 * @return A singly linked list compatible node containing the given element, or NULL if error occurred
 */
ds_sll_node_t* ds_sll_createNode(void* element)
{
    ds_sll_node_t* new_node = (ds_sll_node_t*) malloc(sizeof(ds_sll_node_t));

    if(new_node == NULL) {
        return NULL;
    }

    ds_sll_storeElementInNode(new_node, element);
    return new_node;
}


/**
 * @brief Extract the element contained in the given node
 * @param node The node that contains the element you wish to extract
 * @return The element contained within the given node (void *)
 */
 inline void* ds_sll_extractElementFromNode(ds_sll_node_t* node)
{
    return node->element;
}


/**
 * @brief Encapsulate an element within a given node
 * @param node The node to store the element in
 * @param element The element to store in the node
 * The reason that I have abstracted this function is to allow the programmer to change the way data is being
 * stored and extracted within nodes. Note that at the moment of this writing, the nodes store void pointers. Though
 * you may use those pointers as a gate to more complex operations as you see fit.
 */
 inline void ds_sll_storeElementInNode(ds_sll_node_t* node, void* element)
{
    node->element = element;
}


/**
 * @brief Inline function that returns the next node in the given list
 * @param node The node to extract the 'next node' from
 * @return The next node located right after the given node
 *
 * The point of this function is to abstract the node->next operation
 * allowing the developer to easily customize the way linked lists are traversed
 */
inline ds_sll_node_t* ds_sll_nextNode(ds_sll_node_t* node)
{
    return node->next;
}


/**
 * @brief Delete an element contained within a node and free any allocated resources
 * @param element The element
 */
 inline void ds_sll_deleteElement(void* element)
{
    if(element != NULL) {
        free(element);
    }
}


/**
 * @brief Delete the given node; Free all allocated resources
 * @param node The node to delete
 */
 inline void ds_sll_deleteNode(ds_sll_node_t* node)
{
    ds_sll_deleteElement(node->element);
    free(node);
}


/**
 * @brief Copy a given element to be stored in a node
 * @param element The element to copy
 * @param element_size The size of the given element (in bytes) to be copied
 * @return The new copy of the given element
 */
 void* ds_sll_copyElement(void* element, const size_t element_size)
{
    void* copy = malloc(element_size);

    if(copy == NULL) {
        return NULL;
    }

    memcpy(copy, element, element_size);
    return copy;
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
        curr = ds_sll_nextNode(curr);
    }

    // due to the short circuit nature of comparisons, if the tail was reached then index isn't decremented one last time
    if(curr == linkedList->tail){
        index--;
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
 * @brief Taverse a linked list to the node at a given index
 * @param linkedList The singly linked list to traverse
 * @param node A free node pointer to traverse with
 * @param index The index to traverse to
 * @return @ref ds_sll_error_t Error Code.
 *
 * This function will traverse the given list using the given node pointer until the given index.
 * The functions also returns an error code indicating the success status.
 * This functions intended purpose is to be used with other functions in this library that require
 * traversing a singly linked list.
 * Basically it has the side effect of setting the given node pointer to point to the desired node (if no error occurred)
 * and also returns an error code indicating the status of the traversal.
 */
 ds_sll_error_t ds_sll_traverseNodeToIndex(const ds_sll_t* linkedList, ds_sll_node_t** node, int index)
{
    ASSERT((linkedList != NULL) && (linkedList->head != NULL) && (linkedList->tail != NULL) && (index >= 0));

    *node = linkedList->head;
    // iterate to the node right before the node at the given index
    for (; (*node != NULL) && (*node != linkedList->tail) && (index != 0); index--, *node = ds_sll_nextNode(*node));

    // Error traversing to desired index
    if(*node == NULL) {
        return DS_SLL_BROKEN_LIST_ERROR;
    }
    else if(index != 0) {
        if(*node == linkedList->tail) {
            return DS_SLL_INDEX_OUT_OF_BOUNDS_ERROR;
        }
        else {
            return DS_SLL_BROKEN_LIST_ERROR;
        }
    }
    else {
        return DS_SLL_NO_ERROR;
    }
}


/**
 * @brief Get the element contained in the node at the given index in the specified singly linked list
 * @param linkedList The singly linked list to get the node from
 * @param index The index of the node you want to get (starting with 0)
 * @return A pointer to the element contained by the node at the given index,
 *         or NULL if not found or an error occurred.
 */
void* ds_sll_getElementAtIndex(const ds_sll_t* linkedList, int index)
{
    ASSERT((linkedList != NULL) && (linkedList->head != NULL) && (linkedList->tail != NULL) && (index >= 0));
    ds_sll_node_t* res = ds_sll_getNodeAtIndex(linkedList, index);
    if(res == NULL) {
        return NULL;
    } else {
        return ds_sll_extractElementFromNode(res);
    }
}


/**
 * @brief Delete the node at the given index from the singly linked list
 * @param linkedList The singly linked list to delete the node from
 * @param index The index of the node to delete
 * @return @ref ds_sll_error_t Error code representing the status of the function
 */
 ds_sll_error_t ds_sll_deleteNodeAtIndex(ds_sll_t* linkedList, int index)
{
    ASSERT((linkedList != NULL) && (linkedList->head != NULL) && (linkedList->tail != NULL) && (index >= 0));

    ds_sll_node_t *todel = linkedList->head;

    // If deleting the list's head
    if(index == 0) {
        if(linkedList->head == linkedList->tail) {
            ds_sll_deleteNode(linkedList->head);
            linkedList->head = NULL;
            linkedList->tail = NULL;
        }
        else {
            linkedList->head = ds_sll_nextNode(todel);
            ds_sll_deleteNode(todel);
        }
        return DS_SLL_NO_ERROR;
    }

    // Otherwise Traverse the list until the given node right before the given index
    //traverse `todel` to the node right before the node at the given index (node at index-1)
    ds_sll_error_t traverseStatus = ds_sll_traverseNodeToIndex(linkedList, &todel, index-1);

    // Error traversing to desired index
    if(traverseStatus != DS_SLL_NO_ERROR) {
        return traverseStatus;
    }
    // Broken list
    else if(ds_sll_nextNode(todel) == NULL) {
        return DS_SLL_BROKEN_LIST_ERROR;
    }
    // Delete tail
    else if(ds_sll_nextNode(todel) == linkedList->tail) {
        linkedList->tail = todel; // move the tail pointer one node back (todel)
        todel = ds_sll_nextNode(todel); // move the todel pointer one node forward (the old tail)
        linkedList->tail->next = NULL; // unlink the old tail from the linked list chain
        ds_sll_deleteNode(todel); // delete the old tail
        return DS_SLL_NO_ERROR;
    }
    else {
        ds_sll_node_t *prev = todel; // save a pointer to the current node (the node before the node to be deleted)
        todel = ds_sll_nextNode(todel); // set todel to point to the node to be deleted
        prev->next = ds_sll_nextNode(todel); // unlink the todel node and make prev point to the next node in the list
        ds_sll_deleteNode(todel); // delete the todel node
        return DS_SLL_NO_ERROR;
    }
}


/**
 * @brief Destroy a Singly Linked List
 * @param linkedList The singly linked list to destroy
 * @return @ref ds_sll_error_t Error code representing the status of the function
 * This function will delete all the nodes and deallocate all related memory.
 * Warning, do not use this function if you are sharing any nodes with another list
 * that is currently in use
 */
ds_sll_error_t ds_sll_destroySinglyLinkedList(ds_sll_t *linkedList)
{
    ASSERT((linkedList != NULL) && (linkedList->head != NULL) && (linkedList->tail != NULL));

    while((linkedList->head != NULL) && (linkedList->head != linkedList->tail))
    {
        ds_sll_node_t *todel = linkedList->head;
        linkedList->head = ds_sll_nextNode(todel);
        ds_sll_deleteNode(todel);
    }

    // free the list's tail
    ds_sll_deleteElement(linkedList->tail->element);
    linkedList->tail->element = NULL;

    // check if an error occurred and act accordingly
    if(linkedList-> head == linkedList->tail) {
        linkedList->head = NULL;
        linkedList->tail = NULL;
        return DS_SLL_NO_ERROR;
    } else {
        return DS_SLL_BROKEN_LIST_ERROR;
    }
}



/**
 * @brief Append a given node to the end of the given singly linked list
 * @param linkedList The singly linked list to append the node to
 * @param node The node to append to the end of the singly linked list
 */
void ds_sll_appendNode(ds_sll_t* linkedList, ds_sll_node_t* node)
{
    ASSERT(linkedList != NULL);
    if(linkedList->head == NULL) { // first element in the list
        linkedList->head = node;
        linkedList->tail = node;
    } else {
        linkedList->tail->next = node;
        linkedList->tail = node;
    }
}


/**
 * @brief Create a new node encapsulating the given element,
 * and append this node to the end of the given singly linked list.
 * @param linkedList The singly linked list to append to
 * @param element A pointer to the element to append to the linked list
 * @return 1 if an error occurred; 0 otherwise
 *
 * Possible Errors:
 * - Failure to create a new node
 */
ds_sll_error_t ds_sll_appendElement(ds_sll_t* linkedList, void* element)
{
    ASSERT(linkedList != NULL);
    ds_sll_node_t* new_node = ds_sll_createNode(element);

    if(new_node == NULL) {
        return DS_SLL_NODE_CREATION_ERROR;
    }

    ds_sll_appendNode(linkedList, new_node);
    return DS_SLL_NO_ERROR;
}


/**
 * @brief Create a new node encapsulating a copy of the given element,
 * and append this node to the end of the given singly linked list.
 * @param linkedList The singly linked list to append to
 * @param element The element to copy and append the new copy to the end of the given list
 * @param element_size The size in bytes of the given element
 * @return 1 if an error occurred; 0 otherwise
 */
ds_sll_error_t ds_sll_appendElementCopy(ds_sll_t* linkedList, void* element, const size_t element_size)
{
    ASSERT(linkedList != NULL);
    void* copy = ds_sll_copyElement(element, element_size);

    if(copy == NULL)
        return DS_SLL_ELEMENT_CREATION_ERROR;

    ds_sll_appendElement(linkedList, copy);

    return DS_SLL_NO_ERROR;
}



/**
 * @brief Inserts the given node at the chosen index
 * @param linkedList The singly linked list to insert the node into
 * @param node The node to insert
 * @param index The index where the node should be inserted
 * @return An error code indicating the completion status of the function
 * @see ds_sll_error_t
 */
ds_sll_error_t ds_sll_insertNodeAtIndex(ds_sll_t* linkedList, ds_sll_node_t* node, int index)
{
    ASSERT((linkedList != NULL) && (index >= 0));

    if(index == 0) {
        if (linkedList->head == NULL) {
            linkedList->head = node;
            linkedList->tail = node;
        } else if (linkedList->head == linkedList->tail) {
            linkedList->tail = node;
            linkedList->head->next = node;
        } else {
            node->next = linkedList->head;
            linkedList->head = node;
        }
        return DS_SLL_NO_ERROR;
    }
    else {
        ds_sll_node_t *prev = NULL;
        //traverse `prev` to the node right before the node at the given index (node at index-1)
        ds_sll_error_t traverseStatus = ds_sll_traverseNodeToIndex(linkedList, &prev, index-1);

        if(traverseStatus != DS_SLL_NO_ERROR) {
            return traverseStatus;
        }

        else if(prev == linkedList->tail) { // desired index is the tail
            prev->next = node;
            linkedList->tail = node;
            return DS_SLL_NO_ERROR;
        }
        else if (ds_sll_nextNode(prev) == NULL) { // desired index is NULL: list is broken
            return DS_SLL_BROKEN_LIST_ERROR;
        }
        else { // desired index reached, not tail
            node->next = ds_sll_nextNode(prev);
            prev->next = node;
            return DS_SLL_NO_ERROR;
        }
    }
}


/**
 * @brief Create a new node with the given element and inserts the new node at the chosen index
 * @param linkedList The singly linked list to insert the node into
 * @param element The element pointer you wish to store in the node
 * @param index The index where the node should be inserted
 * @return An error code indicating the completion status of the function
 * @see ds_sll_error_t
 */
ds_sll_error_t ds_sll_insertElementAtIndex(ds_sll_t* linkedList, void* element, int index)
{
    ASSERT((linkedList != NULL) && (index >= 0));
    ds_sll_node_t* new_node = ds_sll_createNode(element);

    if(new_node == NULL) {
        return DS_SLL_NODE_CREATION_ERROR;
    }

    return ds_sll_insertNodeAtIndex(linkedList, new_node, index);
}


/**
 * @brief Create a new node with a copy of the given element and inserts the new node at the chosen index
 * @param linkedList The singly linked list to insert the node into
 * @param element A pointer to the element that you wish to store a copy of in the new node
 * @param element_size The size (in bytes) of the given element
 * @param index The index where the node should be inserted
 * @return An error code indicating the completion status of the function
 * @see ds_sll_error_t
 */
ds_sll_error_t ds_sll_insertElementCopyAtIndex(ds_sll_t* linkedList, void* element, const size_t element_size, int index)
{
    ASSERT((linkedList != NULL) && (index >= 0));
    void* copy = ds_sll_copyElement(element, element_size);

    if(copy == NULL) {
        return DS_SLL_ELEMENT_CREATION_ERROR;
    }

    return ds_sll_insertElementAtIndex(linkedList, copy, index);
}


/**
 * @brief Executes a function on each element in the linked list in order
 * @param linkedList The singly linked list to map the function to
 * @param func A function to execute on each element. Should be in the form: int func(void* element)
 *        It should take one void pointer argument, and return a 1 if an error occurred or a 0 otherwise.
 * @param sharedData A pointer that is passed to your function that you can use to share data to and from your function,
 *        such as having one of the function calls return a value via this pointer, or passing an extra parameter to your function.
 * @return -1 if no error occurred; the index of the node where the error occurred at otherwise.
 *
 * This function traverses the linked list and for each node it traverses, executes the given function
 * passing the element contained in the current node as a parameter. If the function returns DS_SLL_FUNCTION_EXECUTION_ERROR, or a null node
 * is reached before the entire list has been traversed (reached the tail), then this function will halt and return
 * the index of the node where the error was generated.
 * Otherwise if the function successfully traversed the entire list, or one of the function calls returned DS_SLL_STOP_EXECUTION
 * then the function will halt and return -1 indicating successful execution.
 *
 * Your given function will be called on each node in sequence (starting from the head) until the tail or until one of the function calls
 * returns DS_SLL_STOP_EXECUTION or DS_SLL_FUNCTION_EXECUTION_ERROR
 */
int ds_sll_executeFunctionOnElements(ds_sll_t* linkedList, ds_sll_func_return_t (*func)(void*, ds_sll_node_t*, int, void*), void *sharedData)
{
    ASSERT((linkedList != NULL) && (linkedList->head != NULL) && (linkedList->tail != NULL));

    int index;
    ds_sll_node_t* curr = linkedList->head;

    // Traverse the linked list `index` times or until end of list or NULL is reached
    for(index = 0; curr != linkedList->tail; index++){
        ds_sll_func_return_t returncode = func(ds_sll_extractElementFromNode(curr), curr, index, sharedData);
        if((curr == NULL) || (returncode == DS_SLL_EXECUTION_ERROR)) { // an error occurred!
            return index;
        } else if(returncode == DS_SLL_STOP_EXECUTION) {
            return -1;
        }
        // iterate to next node
        curr = ds_sll_nextNode(curr);
    }

    if((curr != linkedList->tail) || (func(ds_sll_extractElementFromNode(curr), curr, index, sharedData) == 1)) {
        return index;
    }

    return -1;
}


/**
 * @brief Calculates the length of the singly linked list (by traversing it)
 * @param linkedList The singly linked list that's length you seek
 * @return An Integer representing the length of the linked list,
 *         or a negative integer who's absolute value represents the index where an error occurred.
 */
int ds_sll_calculateLength(const ds_sll_t* linkedList)
{
    ASSERT((linkedList != NULL) && (linkedList->head != NULL) && (linkedList->tail != NULL));

    int index;
    ds_sll_node_t* curr = linkedList->head;

    // Traverse the linked list `index` times or until end of list or NULL is reached
    for(index = 0; (curr != NULL) && (curr != linkedList->tail); index++, curr = ds_sll_nextNode(curr));

    if((curr == NULL) || (curr != linkedList->tail)) { // an error occurred
        return -(index + 1);
    }

    return index + 1;
}


/**
 * @brief Split Singly Linked List into two singly linked lists at the given index.
 * @param firstLinkedList The original Singly Linked List to be split, will be updated to point to the first sublist created (must have len > 1).
 * @param secondLinkedList A new (initialized) Singly Linked List header to be set to point to the second sublist created
 * @param index The index where the singly linked list will be split (the new tail of the current singly linked list).
 * @return @ref ds_sll_error_t Error Code.
 *
 * The function will shorten the given singly linked list so that it's tail now points to the node located
 * at the given index, and it will create a new singly linked list header where it's head will
 * point to the node at right after the given index (node at index + 1)
 * and it's tail will point to the tail of the original given linked list.
 * After the function completes successfully:
 * The firstLinkedList will point to the sublist starting with the original head up to the node specified by the given index.
 * The secondLinkedList will point to the sublist starting with the node right after the node at the given index up to the original tail.
 * It is expected that you pass a new singly linked list header as the secondLinkedList parameter
 */
ds_sll_error_t ds_sll_splitSinglyLinkedListAtIndex(ds_sll_t *firstLinkedList, ds_sll_t* secondLinkedList, int index)
{
    ASSERT((firstLinkedList != NULL) && (firstLinkedList->head != NULL) && (firstLinkedList->tail != NULL) && (index >= 0));

    // check that the linked list is splittable
    // cannot split a one element linked list
    if(firstLinkedList->head == firstLinkedList->tail) {
        return DS_SLL_LIST_TOO_SMALL_ERROR;
    }

    ds_sll_node_t *newtail;
    ds_sll_error_t traverseStatus = ds_sll_traverseNodeToIndex(firstLinkedList, &newtail, index);

    if(traverseStatus != DS_SLL_NO_ERROR) {
        return traverseStatus;
    }
    else if (ds_sll_nextNode(newtail) == NULL) {
        return DS_SLL_INDEX_OUT_OF_BOUNDS_ERROR;
    }

    secondLinkedList->tail = firstLinkedList->tail; // set secondLinkedList tail to equal original tail
    firstLinkedList->tail = newtail; // update the firstLinkedList tail to equal the new tail where the split occurred
    secondLinkedList->head = ds_sll_nextNode(newtail); // set secondLinkedList head to equal the node after newtail
    firstLinkedList->tail->next = NULL; // break the link between the two newly created linked lists
    return DS_SLL_NO_ERROR;
}


/**
 * @brief Find the node(s) containing the given element
 * @param linkedList The linkedList to search in.
 * @param element The element to search for,
 *        If set to NULL, the function will continue the search from the where the previous call left off,
 *        (used if the list contains multiple instances of the same element and you wish to iterate through them).
 * @param equalityFunc A function that compares two elements and returns 1 if equal and 0 if not equal.
 * @param resultIndex Optional parameter, if not NULL will be set to equal the index of the node that was found to contain the given element.
 * @return The node containing the given element. NULL if not found or error occurred.
 *
 * This function can be used either to retrieve one or more nodes containing the given element,
 * (by calling the function once by passing the element that you are searching for, and setting the element parameter
 * to NULL to continue searching for other nodes after the previously found node),
 * and it can also be used to get the index of the node containing the desired element via the resultIndex parameter.
 */
 ds_sll_node_t* ds_sll_findNodeContainingElement(ds_sll_t* linkedList, void* element, int (*equalityFunc)(void*, void*), int *resultIndex)
{
    ASSERT((linkedList != NULL) && (linkedList->head != NULL) && (linkedList->tail != NULL));

    static void* searchTerm = NULL;
    static ds_sll_node_t* node = NULL;
    static int index = 0;

    // if a new search is initiated, initializes the static variables
    if(element != NULL) {
        searchTerm = element;
        index = 0;
        node = linkedList->head;
    }
    // if we are continuing a previous search, iterate to the next node to continue our search.
    else {
        index++;
        node = ds_sll_nextNode(node);
    }

    // iterate to the node right before the node at the given index
    for (; (node != NULL); node = ds_sll_nextNode(node), index++) {
        if(equalityFunc(node->element, searchTerm) == 1) {
            if(resultIndex != NULL) { // set the resultIndex parameter if it is not NULL
                *resultIndex = index;
            }
            return node;
        }
    }

    return NULL;

}

