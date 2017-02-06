Singly Linked Lists:
====================
**Library Code:** sll

**Label Suffix:** ds_sll_

**Data Types:**
- Linked List Header: **ds_sll_t**
- Node: **ds_sll_node_t**
- Error Codes: **ds_sll_error_t**

Available Functions:
--------------------
- **newSinglyLinkedList**: Create a new header
- **createNode**: Create a new node
- **destroySinglyLinkedList**: Destroy a list and all its nodes
- **extractElementFromNode**: Extract an element stored in a node
- **storeElementInNode**: Store an element in a node
- **deleteElement**: Delete an element in a node and free its resources
- **copyElement**: Create a copy of a given element
- **executeFunctionOnElements**: Execute a given function on all the nodes in the list
- **calculateLength**: Calculates the length of the linked list
- **getNodeAtIndex**: Retrieve the node at the given index
- **getElementAtIndex**: Retrieve the element in the node at the given index
- **appendNode**: Append a node to the end of the list
- **appendElement**: Create a new node and store the given element in it and append the node to
the end of the list
- **appendElementCopy**: Create a new node and store a copy of the given element in it and appen
the node to the end of the list
- **insertNodeAtIndex**: Insert a node at the given index
- **insertElementAtIndex**: Create a new node and store the given element and insert the new node
at the given index in the list.
- **insertElementCopyAtIndex**: Create a new node and store a copy of the given element and insert
the new node at the given index in the list.


I have abstracted the functions *storeElementInNode*, *deleteElement*, and *copyElement*
so you can easily change the way data is being stored in the node. Maybe the void pointers being
stored in the nodes are references to more complicated objects, and therefore you can modify these
functions to perform initializations and data manipulations according to your design without
affecting the overall linked list functionality.