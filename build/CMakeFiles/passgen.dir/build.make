# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/divyansh/Projects/c++/passgen-cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/divyansh/Projects/c++/passgen-cpp/build

# Include any dependencies generated for this target.
include CMakeFiles/passgen.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/passgen.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/passgen.dir/flags.make

CMakeFiles/passgen.dir/src/main.cpp.o: CMakeFiles/passgen.dir/flags.make
CMakeFiles/passgen.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/divyansh/Projects/c++/passgen-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/passgen.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/passgen.dir/src/main.cpp.o -c /home/divyansh/Projects/c++/passgen-cpp/src/main.cpp

CMakeFiles/passgen.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/passgen.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/divyansh/Projects/c++/passgen-cpp/src/main.cpp > CMakeFiles/passgen.dir/src/main.cpp.i

CMakeFiles/passgen.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/passgen.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/divyansh/Projects/c++/passgen-cpp/src/main.cpp -o CMakeFiles/passgen.dir/src/main.cpp.s

# Object files for target passgen
passgen_OBJECTS = \
"CMakeFiles/passgen.dir/src/main.cpp.o"

# External object files for target passgen
passgen_EXTERNAL_OBJECTS =

passgen: CMakeFiles/passgen.dir/src/main.cpp.o
passgen: CMakeFiles/passgen.dir/build.make
passgen: CMakeFiles/passgen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/divyansh/Projects/c++/passgen-cpp/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable passgen"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/passgen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/passgen.dir/build: passgen

.PHONY : CMakeFiles/passgen.dir/build

CMakeFiles/passgen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/passgen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/passgen.dir/clean

CMakeFiles/passgen.dir/depend:
	cd /home/divyansh/Projects/c++/passgen-cpp/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/divyansh/Projects/c++/passgen-cpp /home/divyansh/Projects/c++/passgen-cpp /home/divyansh/Projects/c++/passgen-cpp/build /home/divyansh/Projects/c++/passgen-cpp/build /home/divyansh/Projects/c++/passgen-cpp/build/CMakeFiles/passgen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/passgen.dir/depend

