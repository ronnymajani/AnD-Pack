#AnD Pack#
##*A*lgorithms a*n*d *D*ata Structures Pack##
######A set of libraries containing as many algorithms and data structures libraries, implemented in standard C-11######

In Progress:
============
Data Structures:
----------------
- **Singly Linked Lists (sll):**:
a versatile library containing many functions that allow you to use and manipulate
singly linked lists. The code was written with certain abstractions in mind,
that allow easy modification of the to adapt the library's functionality 
to your requirements and design.


------------------------------


Notes:
======
Naming Conventions:
-------------------
All labels are suffixed according to their library's heirarchy:

**ds**/**al** + **_** + *library code* + **_**

example: suffix for singly linked lists **ds_sll_**

example function: **ds_sll_createNode(*...*)**

example typedef: **ds_sll_node_t**
 
Plan:
=====
Data Structures:
----------------
- **Headless Linked Lists**
- **Doubly Linked Lists**
- **Circular Singly Linked Lists**
- **Circular Doubly Linked Lists**
- **Headless Circular Linked Lists**
- **Trees**
- **Hash Tables**
- **Array Lists**

Algorithms:
-----------
- **Search**
  - Binary Search
  - Iterative Search
- **Sort**
  - Binary Sort
  - Bubble Sort
  - Quick Sort
  - Merge Sort
  - Shell sort
- **Graph Search**
  - BFS
  - DFS
- **Shortest Path**
  - Djikstra's
  - Bellman Ford's

Parallel Algorithms:
--------------------
I also plan on implementing some parallel search algorithms.
I plan on providing two implementations for each algorithm,
one using POSIX multithreading, and the other using OpenCL.