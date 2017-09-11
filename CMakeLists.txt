cmake_minimum_required(VERSION 3.2)
project(RM-Linked-List)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES "src/SinglyLinkedList.c" "src/SinglyLinkedList.h")

add_executable(Demo ${SOURCE_FILES} demo.c)