# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /home/u_kolacs1/host/Downloads/calculator_task

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/u_kolacs1/host/Downloads/calculator_task/build

# Include any dependencies generated for this target.
include CMakeFiles/calculator_task.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/calculator_task.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/calculator_task.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/calculator_task.dir/flags.make

CMakeFiles/calculator_task.dir/src/main.cpp.o: CMakeFiles/calculator_task.dir/flags.make
CMakeFiles/calculator_task.dir/src/main.cpp.o: /home/u_kolacs1/host/Downloads/calculator_task/src/main.cpp
CMakeFiles/calculator_task.dir/src/main.cpp.o: CMakeFiles/calculator_task.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/u_kolacs1/host/Downloads/calculator_task/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/calculator_task.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/calculator_task.dir/src/main.cpp.o -MF CMakeFiles/calculator_task.dir/src/main.cpp.o.d -o CMakeFiles/calculator_task.dir/src/main.cpp.o -c /home/u_kolacs1/host/Downloads/calculator_task/src/main.cpp

CMakeFiles/calculator_task.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/calculator_task.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/u_kolacs1/host/Downloads/calculator_task/src/main.cpp > CMakeFiles/calculator_task.dir/src/main.cpp.i

CMakeFiles/calculator_task.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/calculator_task.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/u_kolacs1/host/Downloads/calculator_task/src/main.cpp -o CMakeFiles/calculator_task.dir/src/main.cpp.s

# Object files for target calculator_task
calculator_task_OBJECTS = \
"CMakeFiles/calculator_task.dir/src/main.cpp.o"

# External object files for target calculator_task
calculator_task_EXTERNAL_OBJECTS =

calculator_task: CMakeFiles/calculator_task.dir/src/main.cpp.o
calculator_task: CMakeFiles/calculator_task.dir/build.make
calculator_task: libcalculator.a
calculator_task: CMakeFiles/calculator_task.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/u_kolacs1/host/Downloads/calculator_task/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable calculator_task"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/calculator_task.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/calculator_task.dir/build: calculator_task
.PHONY : CMakeFiles/calculator_task.dir/build

CMakeFiles/calculator_task.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/calculator_task.dir/cmake_clean.cmake
.PHONY : CMakeFiles/calculator_task.dir/clean

CMakeFiles/calculator_task.dir/depend:
	cd /home/u_kolacs1/host/Downloads/calculator_task/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/u_kolacs1/host/Downloads/calculator_task /home/u_kolacs1/host/Downloads/calculator_task /home/u_kolacs1/host/Downloads/calculator_task/build /home/u_kolacs1/host/Downloads/calculator_task/build /home/u_kolacs1/host/Downloads/calculator_task/build/CMakeFiles/calculator_task.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/calculator_task.dir/depend
