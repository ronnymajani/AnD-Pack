cmake_minimum_required(VERSION 3.6)
project(AnDpack)

set(CMAKE_C_STANDARD 11)

set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib)

set(SOURCE_FILES main.c)
set(LIBRARY_FILES "Data Structures/Linked Lists/SinglyLinkedList.c" "Data Structures/Linked Lists/SinglyLinkedList.h")

set(CMAKE_FIND_LIBRARY_SUFFIXES ".a")

add_library(AnDpack STATIC ${LIBRARY_FILES})
set_property(TARGET AnDpack PROPERTY
        IMPORTED_LOCATION ${LIBRARY_OUTPUT_PATH}/libAnDpack.a)

add_executable(AnDpack_test ${SOURCE_FILES})

target_link_libraries(AnDpack_test AnDpack)