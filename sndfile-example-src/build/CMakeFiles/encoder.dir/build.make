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
CMAKE_SOURCE_DIR = /home/diana/Desktop/IC/sndfile-example-src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/diana/Desktop/IC/sndfile-example-src/build

# Include any dependencies generated for this target.
include CMakeFiles/encoder.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/encoder.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/encoder.dir/flags.make

CMakeFiles/encoder.dir/encoder.cpp.o: CMakeFiles/encoder.dir/flags.make
CMakeFiles/encoder.dir/encoder.cpp.o: ../encoder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diana/Desktop/IC/sndfile-example-src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/encoder.dir/encoder.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/encoder.dir/encoder.cpp.o -c /home/diana/Desktop/IC/sndfile-example-src/encoder.cpp

CMakeFiles/encoder.dir/encoder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/encoder.dir/encoder.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diana/Desktop/IC/sndfile-example-src/encoder.cpp > CMakeFiles/encoder.dir/encoder.cpp.i

CMakeFiles/encoder.dir/encoder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/encoder.dir/encoder.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diana/Desktop/IC/sndfile-example-src/encoder.cpp -o CMakeFiles/encoder.dir/encoder.cpp.s

# Object files for target encoder
encoder_OBJECTS = \
"CMakeFiles/encoder.dir/encoder.cpp.o"

# External object files for target encoder
encoder_EXTERNAL_OBJECTS =

/home/diana/Desktop/IC/sndfile-example-bin/encoder: CMakeFiles/encoder.dir/encoder.cpp.o
/home/diana/Desktop/IC/sndfile-example-bin/encoder: CMakeFiles/encoder.dir/build.make
/home/diana/Desktop/IC/sndfile-example-bin/encoder: CMakeFiles/encoder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/diana/Desktop/IC/sndfile-example-src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/diana/Desktop/IC/sndfile-example-bin/encoder"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/encoder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/encoder.dir/build: /home/diana/Desktop/IC/sndfile-example-bin/encoder

.PHONY : CMakeFiles/encoder.dir/build

CMakeFiles/encoder.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/encoder.dir/cmake_clean.cmake
.PHONY : CMakeFiles/encoder.dir/clean

CMakeFiles/encoder.dir/depend:
	cd /home/diana/Desktop/IC/sndfile-example-src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/diana/Desktop/IC/sndfile-example-src /home/diana/Desktop/IC/sndfile-example-src /home/diana/Desktop/IC/sndfile-example-src/build /home/diana/Desktop/IC/sndfile-example-src/build /home/diana/Desktop/IC/sndfile-example-src/build/CMakeFiles/encoder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/encoder.dir/depend

