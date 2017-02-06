cmake_minimum_required(VERSION 3.6)
project(AnD_pack)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES library.c library.h "Data Structures/Linked Lists/SinglyLinkedList.c" "Data Structures/Linked Lists/SinglyLinkedList.h")
add_library(AnD_pack ${SOURCE_FILES})