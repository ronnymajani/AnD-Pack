cmake_minimum_required(VERSION 3.2)
project(RM-Linked-List)

set(CMAKE_C_STANDARD 11)


# Prepare "Catch" library for other executables
set(CATCH_INCLUDE_DIR tests/catch)
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

set(TEST_SOURCES_FILES tests/SingyLinkedList.test.cpp tests/TestMain.cpp)

set(SOURCE_FILES "src/SinglyLinkedList.c" "src/SinglyLinkedList.h")

add_executable(Tests ${TEST_SOURCES_FILES} ${SOURCE_FILES})
target_link_libraries(Tests Catch)

add_executable(Demo ${SOURCE_FILES} demo.c)