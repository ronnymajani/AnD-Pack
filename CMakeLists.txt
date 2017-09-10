cmake_minimum_required(VERSION 3.6)
project(AnDpack)

set(CMAKE_C_STANDARD 11)

set(TEST_FILES SinglyLinkedList.test.c)
set(SOURCE_FILES "src/SinglyLinkedList.c" "src/SinglyLinkedList.h")


add_executable(AnDpack ${SOURCE_FILES} ${TEST_FILES})