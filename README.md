#*A*n*D* Pack#
##*A*lgorithms and *D*ata Structures Pack##
######A set of libraries containing as many algorithms and data structures libraries, implemented in standard C-11######

In Progress:
============
Data Structures (code: ds):
----------------
- [**Singly Linked Lists (code: sll):**](./Data%20Structures/Linked%20Lists)
a versatile library containing many functions that allow you to use and manipulate
singly linked lists. The code was written with certain abstractions in mind,
that allow easy modification of the to adapt the library's functionality 
to your requirements and design.

Algorithms (code: al):
----------------------


------------------------------


Notes:
======
Implementation:
---------------
- C Language following the C-11 Standard
- CMake v3.6 for compiling and organizing the build process
- For Parallel Algorithms:
  - POSIX for multithreading implementations
  - OpenCL v1.1+ for GPU and cross platform implementations

Naming Conventions:
-------------------
All labels are suffixed according to their library's heirarchy:

**ds**/**al** + **_** + *library code* + **_**

example: suffix for singly linked lists **ds_sll_**

example function: **ds_sll_createNode(*...*)**

example typedef: **ds_sll_node_t**

Project Vision:
---------------
My goal is to provide a versatile, flexible, customizable set of libraries
to make everyone's job easier.
I want this set to be reliable that it can confidently be used with
embedded systems and maintains a well-rounded balance between being
an all-purpose customizable library, fast, and memory efficient where it's
performance is suitable for your real time needs.

Everyone is free to contribute as much as they want, but please, if you wish
to contribute, try to put your best work out there. This library aims to be
 an open source industry grade solution.
 Which means we need to keep the aforementioned characterstics in mind
 while developing this project.

____________________________
 
Plan:
=====
Data Structures (code: ds):
----------------
- **Headless Linked Lists**
- **Doubly Linked Lists**
- **Circular Singly Linked Lists**
- **Circular Doubly Linked Lists**
- **Headless Circular Linked Lists**
- **Trees**
- **Hash Tables**
- **Array Lists**

Algorithms (code: al):
----------------------
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

Parallel Algorithms (code: pa):
-------------------------------
I also plan on implementing some parallel search algorithms.
I plan on providing two implementations for each algorithm,
one using POSIX multithreading, and the other using OpenCL.