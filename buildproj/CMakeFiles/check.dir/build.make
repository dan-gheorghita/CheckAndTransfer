# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /home/ban/Downloads/cmake/buildproj

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ban/Downloads/cmake/buildproj

# Include any dependencies generated for this target.
include CMakeFiles/check.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/check.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/check.dir/flags.make

CMakeFiles/check.dir/home/ban/Downloads/cmake/checkandtransfer.o: CMakeFiles/check.dir/flags.make
CMakeFiles/check.dir/home/ban/Downloads/cmake/checkandtransfer.o: /home/ban/Downloads/cmake/checkandtransfer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ban/Downloads/cmake/buildproj/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/check.dir/home/ban/Downloads/cmake/checkandtransfer.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/check.dir/home/ban/Downloads/cmake/checkandtransfer.o -c /home/ban/Downloads/cmake/checkandtransfer.cpp

CMakeFiles/check.dir/home/ban/Downloads/cmake/checkandtransfer.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/check.dir/home/ban/Downloads/cmake/checkandtransfer.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ban/Downloads/cmake/checkandtransfer.cpp > CMakeFiles/check.dir/home/ban/Downloads/cmake/checkandtransfer.i

CMakeFiles/check.dir/home/ban/Downloads/cmake/checkandtransfer.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/check.dir/home/ban/Downloads/cmake/checkandtransfer.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ban/Downloads/cmake/checkandtransfer.cpp -o CMakeFiles/check.dir/home/ban/Downloads/cmake/checkandtransfer.s

CMakeFiles/check.dir/home/ban/Downloads/cmake/checkandtransfer.o.requires:

.PHONY : CMakeFiles/check.dir/home/ban/Downloads/cmake/checkandtransfer.o.requires

CMakeFiles/check.dir/home/ban/Downloads/cmake/checkandtransfer.o.provides: CMakeFiles/check.dir/home/ban/Downloads/cmake/checkandtransfer.o.requires
	$(MAKE) -f CMakeFiles/check.dir/build.make CMakeFiles/check.dir/home/ban/Downloads/cmake/checkandtransfer.o.provides.build
.PHONY : CMakeFiles/check.dir/home/ban/Downloads/cmake/checkandtransfer.o.provides

CMakeFiles/check.dir/home/ban/Downloads/cmake/checkandtransfer.o.provides.build: CMakeFiles/check.dir/home/ban/Downloads/cmake/checkandtransfer.o


# Object files for target check
check_OBJECTS = \
"CMakeFiles/check.dir/home/ban/Downloads/cmake/checkandtransfer.o"

# External object files for target check
check_EXTERNAL_OBJECTS =

check: CMakeFiles/check.dir/home/ban/Downloads/cmake/checkandtransfer.o
check: CMakeFiles/check.dir/build.make
check: CMakeFiles/check.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ban/Downloads/cmake/buildproj/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable check"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/check.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/check.dir/build: check

.PHONY : CMakeFiles/check.dir/build

CMakeFiles/check.dir/requires: CMakeFiles/check.dir/home/ban/Downloads/cmake/checkandtransfer.o.requires

.PHONY : CMakeFiles/check.dir/requires

CMakeFiles/check.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/check.dir/cmake_clean.cmake
.PHONY : CMakeFiles/check.dir/clean

CMakeFiles/check.dir/depend:
	cd /home/ban/Downloads/cmake/buildproj && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ban/Downloads/cmake/buildproj /home/ban/Downloads/cmake/buildproj /home/ban/Downloads/cmake/buildproj /home/ban/Downloads/cmake/buildproj /home/ban/Downloads/cmake/buildproj/CMakeFiles/check.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/check.dir/depend

