# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/ronnymajani/Apps/clion-2016.3.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/ronnymajani/Apps/clion-2016.3.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/ronnymajani/Workspace/AnD Pack"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/ronnymajani/Workspace/AnD Pack/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/AnDpack.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AnDpack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AnDpack.dir/flags.make

CMakeFiles/AnDpack.dir/Data_Structures/Linked_Lists/SinglyLinkedList.c.o: CMakeFiles/AnDpack.dir/flags.make
CMakeFiles/AnDpack.dir/Data_Structures/Linked_Lists/SinglyLinkedList.c.o: ../Data\ Structures/Linked\ Lists/SinglyLinkedList.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ronnymajani/Workspace/AnD Pack/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/AnDpack.dir/Data_Structures/Linked_Lists/SinglyLinkedList.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/AnDpack.dir/Data_Structures/Linked_Lists/SinglyLinkedList.c.o   -c "/home/ronnymajani/Workspace/AnD Pack/Data Structures/Linked Lists/SinglyLinkedList.c"

CMakeFiles/AnDpack.dir/Data_Structures/Linked_Lists/SinglyLinkedList.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AnDpack.dir/Data_Structures/Linked_Lists/SinglyLinkedList.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/ronnymajani/Workspace/AnD Pack/Data Structures/Linked Lists/SinglyLinkedList.c" > CMakeFiles/AnDpack.dir/Data_Structures/Linked_Lists/SinglyLinkedList.c.i

CMakeFiles/AnDpack.dir/Data_Structures/Linked_Lists/SinglyLinkedList.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AnDpack.dir/Data_Structures/Linked_Lists/SinglyLinkedList.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/ronnymajani/Workspace/AnD Pack/Data Structures/Linked Lists/SinglyLinkedList.c" -o CMakeFiles/AnDpack.dir/Data_Structures/Linked_Lists/SinglyLinkedList.c.s

CMakeFiles/AnDpack.dir/Data_Structures/Linked_Lists/SinglyLinkedList.c.o.requires:

.PHONY : CMakeFiles/AnDpack.dir/Data_Structures/Linked_Lists/SinglyLinkedList.c.o.requires

CMakeFiles/AnDpack.dir/Data_Structures/Linked_Lists/SinglyLinkedList.c.o.provides: CMakeFiles/AnDpack.dir/Data_Structures/Linked_Lists/SinglyLinkedList.c.o.requires
	$(MAKE) -f CMakeFiles/AnDpack.dir/build.make CMakeFiles/AnDpack.dir/Data_Structures/Linked_Lists/SinglyLinkedList.c.o.provides.build
.PHONY : CMakeFiles/AnDpack.dir/Data_Structures/Linked_Lists/SinglyLinkedList.c.o.provides

CMakeFiles/AnDpack.dir/Data_Structures/Linked_Lists/SinglyLinkedList.c.o.provides.build: CMakeFiles/AnDpack.dir/Data_Structures/Linked_Lists/SinglyLinkedList.c.o


# Object files for target AnDpack
AnDpack_OBJECTS = \
"CMakeFiles/AnDpack.dir/Data_Structures/Linked_Lists/SinglyLinkedList.c.o"

# External object files for target AnDpack
AnDpack_EXTERNAL_OBJECTS =

../lib/libAnDpack.a: CMakeFiles/AnDpack.dir/Data_Structures/Linked_Lists/SinglyLinkedList.c.o
../lib/libAnDpack.a: CMakeFiles/AnDpack.dir/build.make
../lib/libAnDpack.a: CMakeFiles/AnDpack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/ronnymajani/Workspace/AnD Pack/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library ../lib/libAnDpack.a"
	$(CMAKE_COMMAND) -P CMakeFiles/AnDpack.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AnDpack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AnDpack.dir/build: ../lib/libAnDpack.a

.PHONY : CMakeFiles/AnDpack.dir/build

CMakeFiles/AnDpack.dir/requires: CMakeFiles/AnDpack.dir/Data_Structures/Linked_Lists/SinglyLinkedList.c.o.requires

.PHONY : CMakeFiles/AnDpack.dir/requires

CMakeFiles/AnDpack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AnDpack.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AnDpack.dir/clean

CMakeFiles/AnDpack.dir/depend:
	cd "/home/ronnymajani/Workspace/AnD Pack/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/ronnymajani/Workspace/AnD Pack" "/home/ronnymajani/Workspace/AnD Pack" "/home/ronnymajani/Workspace/AnD Pack/cmake-build-debug" "/home/ronnymajani/Workspace/AnD Pack/cmake-build-debug" "/home/ronnymajani/Workspace/AnD Pack/cmake-build-debug/CMakeFiles/AnDpack.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/AnDpack.dir/depend

