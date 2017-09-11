/*
The MIT License (MIT)

Copyright (c) 2017 Ronny Majani

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
 */

/**
 * @ingroup testfiles
 * @{
 * @file Singly Linked List Unit Tests
 * @brief Unit Tests for the Singly Linked List library
 */
#include "catch/catch.hpp"

extern "C" {
    #include "../src/SinglyLinkedList.h"
    #include <stdio.h>
}

extern "C" {
/* Test Cases */
/*-------------------------------------------*/
TEST_CASE("Create and Destroy empty Linked List", "[create_destroy_list]") {
    ds_sll_t *list = ds_sll_newSinglyLinkedList();
    REQUIRE(list != NULL);
    REQUIRE(list->head == NULL);
    REQUIRE(list->tail == NULL);

    ds_sll_destroySinglyLinkedList(&list);
    REQUIRE(list == NULL);
}


TEST_CASE("Create and Delete new Node", "[create_delete_node]") {
    // create new Linked List
    ds_sll_node_t *new_node = ds_sll_createNode(NULL);
    REQUIRE(new_node != NULL);
    REQUIRE(new_node->next == NULL);
    REQUIRE(new_node->element == NULL);

    // delete new Linked List
    ds_sll_deleteNode(&new_node);
    REQUIRE(new_node == NULL);
}


TEST_CASE("Store, Copy, and Delete Elements from Node", "[store_delete_elements]") {
    // create a new node
    ds_sll_node_t *new_node = ds_sll_createNode(NULL);

    // create an element to insert
    int *inserted_element = (int *) malloc(sizeof(int));
    REQUIRE(inserted_element != NULL);

    // insert element in a node
    ds_sll_storeElementInNode(new_node, inserted_element);
    int *extracted_element = (int *) ds_sll_extractElementFromNode(new_node);
    REQUIRE(extracted_element == inserted_element);

    // copy an element
    int* element_copy = (int*) ds_sll_copyElement(inserted_element, sizeof(int));
    REQUIRE(*element_copy == *inserted_element);  // same value
    REQUIRE(element_copy != inserted_element);  // but not the same variable

    // delete the inserted element from the node
    void **node_element_pointer = &(new_node->element);
    ds_sll_deleteElement(node_element_pointer);
    REQUIRE(*node_element_pointer == NULL);

    // delete the copy element
    ds_sll_deleteElement((void**)&element_copy);
    REQUIRE(element_copy == NULL);

    // delete node
    ds_sll_deleteNode(&new_node);
}


} /* extern "C" */

/**
 * @}
 */

