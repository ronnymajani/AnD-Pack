Singly Linked Lists: [![Build Status](https://travis-ci.org/ronnymajani/RM-Linked-List.svg?branch=master)](https://travis-ci.org/ronnymajani/RM-Linked-List)
============================================================================================================================================================
A versatile library containing many functions that allow you to use and manipulate
singly linked lists. The code was written with certain abstractions in mind,
that allow easy modification of the to adapt the library's functionality 

> *Note: The Singly Linked Lists library used to be part of a collection of Algorithms
> and Data Structures (AnD Pack) that I was working on, until I decided to split
> it off into a separate repository*

Documentation:
--------------
To generate the Documentation, just run the `doxygen` command in the
root directory of this project

Implementation:
---------------
- C Language following the C-11 Standard
- CMake v3.2.2 for compiling and organizing the build process
- For Documentation Generation: Doxygen v1.8.11

Naming Conventions:
-------------------
All labels are suffixed with **ds_sll_**

example function: **ds_sll_createNode(*...*)**

example typedef: **ds_sll_node_t**

Data Types:
-----------
- Linked List Header: **ds_sll_t**
- Node: **ds_sll_node_t**
- Error Codes: **ds_sll_error_t**
- Executable Function Return Type: **ds_sll_func_return_t**

Overview:
---------
The linked list is represented by a header, that keeps track of the **head** and the
 **tail**. The linked list consists of **nodes**. Each node has a reference to the **next node**.
 Each node also stores one **void pointer** that we call an **element**.
 This pointer is generic and can be used anyway you see fit. The simplest example is it could
 be a pointer to a primitive data type allocated in memory, and when you access this data you simply
 typecast the pointer to the appropriate type and then dereference it as you would any normal pointer.
 For the more advanced applications out there this pointer could reference more complicated objects
 or be used for more complex representations. To accommodate for the wide possiblities
 I aimed to abstract the library to manageable and easily customizable chunks.

Available Functions:
--------------------
###### Create/Delete
- **ds_sll_newSinglyLinkedList**: Create a new header
- **ds_sll_createNode**: Create a new node
- **ds_sll_destroySinglyLinkedList**: Destroy a list and all its nodes
- **ds_sll_deleteNode**: Delete and free resources associated with a given Node
- **ds_sll_deleteNodeAtIndex**: Delete the node located at the given index, and free allocated resources.

###### Operations on Node:
- **ds_sll_nextNode**: Specifies how to get the next node following a given node
- **ds_sll_extractElementFromNode**: Extract an element stored in a node
- **ds_sll_storeElementInNode**: Store an element in a node
- **ds_sll_deleteElement**: Delete an element in a node and free its resources
- **ds_sll_copyElement**: Create a copy of a given element

###### Operations on List:
- **ds_sll_executeFunctionOnElements**: Execute a given function on all the nodes in the list
- **ds_sll_calculateLength**: Calculates the length of the linked list
- **ds_sll_splitSinglyLinkedListAtIndex**: Splits a linked list into two at the given index

###### Retrieval and Search:
- **ds_sll_getNodeAtIndex**: Retrieve the node at the given index
- **ds_sll_getElementAtIndex**: Retrieve the element in the node at the given index
- **ds_sll_findNodeContainingElement**: Searches the linked list for the node containing the given element

###### Append:
- **ds_sll_appendNode**: Append a node to the end of the list
- **ds_sll_appendElement**: Create a new node and store the given element in it and append the node to
the end of the list
- **ds_sll_appendElementCopy**: Create a new node and store a copy of the given element in it and appen
the node to the end of the list

###### Insert:
- **ds_sll_insertNodeAtIndex**: Insert a node at the given index
- **ds_sll_insertElementAtIndex**: Create a new node and store the given element and insert the new node
at the given index in the list.
- **ds_sll_insertElementCopyAtIndex**: Create a new node and store a copy of the given element and insert
the new node at the given index in the list.

###### Helper Functions:
- **ds_sll_traverseNodeToIndex**: A helper function that traverses a linked list and sets the given pointer
to point to the node at the given index. It also returns an error code detailing what kind of error occurred.


#### executeFunctionOnElements:
This function allows you to execute a given function on the entire linked list
in sequential order.
This function takes an *executable function*, traverses the given linked list,
and calls the given *executable function* on each node.
This traversal is sequential and can be controlled via the return parameter
of the *executable function*'s.
The way to use is by defining a function in the form:
```c
ds_sll_func_return_t myfunction(void* element, ds_sll_node_t* node, int index, void* shared) {
	ds_sll_func_return_t execution_status;
	
	...
	
	rerturn execution_status;
}
```
Where obviously you can name the function anything you like.
The first parameter `void* element` is a pointer to the element within the current node
that `ds_sll_executeFunctionOnElements(...)` is processing.
The second parameter `ds_sll_node_t* node` is a pointer to the node the function
was called on
The third parameter `int index` is the index of the node that this function was
called on.
The fourth parameter `void* shared` is used for three reasons:
- to allow your function to return some value back to you
- to share information between subsequent function calls
- to pass an initial input value to your functions
The drawback is that you can only have one value to use for input, data sharing, and output.
The return value of the function is used to control the execution flow,
meaning it tells the `ds_sll_executeFunctionOnElements(...)` function whether:
- the function call to `myfunction(...)` was successful:
continue to execute `myfunction(...)` on next node
- the function call to `myfunction(...)` ran into an error:
do not continue executing the function on the next node,
and return an appropriate error value back to the caller of `ds_sll_executeFunctionOnElements(...)`
- the function ran successfully and would like to terminate:
Used when your function is looking for a specific element and once it is found,
there is no point in continuing to traverse the linked list therefore your function
should request to terminate execution.

An example usage of `ds_sll_executeFunctionOnElements(...)` is a function
that finds the maximum element in the linked list. The functions definitions is:
```c
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
```
```c
int *max_element = (int*)malloc(sizeof(int));
ds_sll_executeFunctionOnElements(mylist, getMaxElement, (void*)max_element);
printf("Max Element in list: %d\n", *max_element);
free(max_element);
```


Another example is a function that returns a pointer to the node containing the max element:
```c
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
```
```c
ds_sll_node_t* max_node = NULL;
ds_sll_executeFunctionOnElements(mylist, maxNode, (void*)&max_node);
int* max_node_element = (int*)ds_sll_extractElementFromNode(max_node);
printf("Max Element in Max Node is: %d\n", *max_node_element);
```

A final example shows how you can define your own data structure to allow you to pass in multiple
parameters to your function. This function will stop traversing the node
when the element you were looking for is found by returning `DS_SLL_STOP_EXECUTION`:
```c
typedef struct findNodeFuncParams {
    int input;
    int output_index;
    ds_sll_node_t* output_node;
} findNodeFuncParams;
```
```c
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
```
```c
findNodeFuncParams* params = (findNodeFuncParams*) malloc(sizeof(findNodeFuncParams));
params->input = 77;
ds_sll_executeFunctionOnElements(mylist, findNode, (void*)params);
printf("Node containing element (%d) is located at index %d\n", params->input, params->output_index);
free(params);
```

*Please note that if you alter the element entry in the `ds_sll_node_t` data
structure to be anything other than a `void*` you might have to edit one or more other functions,
mainly you will need to alter the `ds_sll_executeFunctionOnElements(...)` function
as it passes a `void*` as an argument to the given executable function.
This does not mean that you can not have a complex data type for the **element**
of your node, this library was designed so that no matter what the data type is of your element
the node only stores a generic void pointer to refer to it, and the library functions depend
on the usage of `ds_sll_extractElementFromNode`, `ds_sll_storeElementInNode`,
`ds_sll_deleteElement`, `ds_sll_copyElement`, and other abstractions to appropriately
access and manipulate the element objects.*

*So as a general guideline, to easily customize the library,
stick to modifying the library functions, mainly those mentioned below in the **Abstractions**
section.*

#### Abstractions:
 This library was designed with some abstractions in mind to allow for easy customization according to your
 project's needs. These abstractions are mainly implemented as inline functions where possible.
 The main abstractions are:
 + **ds_sll_createNode**: allows you to specify how nodes are created
 + **ds_sll_extractElementFromNode**: allows you to specify how node elements are read (return node->element)
 + **ds_sll_storeElementInNode**: allows you to specify how to insert an element in a node (node->element = new_element)
 + **ds_sll_deleteElement**: allows you to specify how to deallocate the resources of a given Element
 + **ds_sll_deleteNode**: allows you to specify how a node is 'deleted' and its resources are de-allocated
 + **ds_sll_copyElement**: allows you to specify how an Element is copied

You can alter these functions and define your own custom functions using `ds_sll_executeFunctionOnElements`
to suite the needs of your application and you can easily change the way data is being stored in the node. Maybe the void pointers being
stored in the nodes are references to more complicated objects, and therefore you can modify these
functions to perform initializations and data manipulations according to your design without
affecting the overall linked list functionality.
