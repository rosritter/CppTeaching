# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/илья/Desktop/c++_for_kfu/3hw/homeWork/05

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/илья/Desktop/c++_for_kfu/3hw/homeWork/05

# Include any dependencies generated for this target.
include CMakeFiles/template11.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/template11.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/template11.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/template11.dir/flags.make

CMakeFiles/template11.dir/template1/main.cpp.o: CMakeFiles/template11.dir/flags.make
CMakeFiles/template11.dir/template1/main.cpp.o: template1/main.cpp
CMakeFiles/template11.dir/template1/main.cpp.o: CMakeFiles/template11.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/илья/Desktop/c++_for_kfu/3hw/homeWork/05/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/template11.dir/template1/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/template11.dir/template1/main.cpp.o -MF CMakeFiles/template11.dir/template1/main.cpp.o.d -o CMakeFiles/template11.dir/template1/main.cpp.o -c /mnt/c/Users/илья/Desktop/c++_for_kfu/3hw/homeWork/05/template1/main.cpp

CMakeFiles/template11.dir/template1/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/template11.dir/template1/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/илья/Desktop/c++_for_kfu/3hw/homeWork/05/template1/main.cpp > CMakeFiles/template11.dir/template1/main.cpp.i

CMakeFiles/template11.dir/template1/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/template11.dir/template1/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/илья/Desktop/c++_for_kfu/3hw/homeWork/05/template1/main.cpp -o CMakeFiles/template11.dir/template1/main.cpp.s

# Object files for target template11
template11_OBJECTS = \
"CMakeFiles/template11.dir/template1/main.cpp.o"

# External object files for target template11
template11_EXTERNAL_OBJECTS =

template11: CMakeFiles/template11.dir/template1/main.cpp.o
template11: CMakeFiles/template11.dir/build.make
template11: CMakeFiles/template11.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/илья/Desktop/c++_for_kfu/3hw/homeWork/05/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable template11"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/template11.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/template11.dir/build: template11
.PHONY : CMakeFiles/template11.dir/build

CMakeFiles/template11.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/template11.dir/cmake_clean.cmake
.PHONY : CMakeFiles/template11.dir/clean

CMakeFiles/template11.dir/depend:
	cd /mnt/c/Users/илья/Desktop/c++_for_kfu/3hw/homeWork/05 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/илья/Desktop/c++_for_kfu/3hw/homeWork/05 /mnt/c/Users/илья/Desktop/c++_for_kfu/3hw/homeWork/05 /mnt/c/Users/илья/Desktop/c++_for_kfu/3hw/homeWork/05 /mnt/c/Users/илья/Desktop/c++_for_kfu/3hw/homeWork/05 /mnt/c/Users/илья/Desktop/c++_for_kfu/3hw/homeWork/05/CMakeFiles/template11.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/template11.dir/depend

