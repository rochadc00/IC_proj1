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
include CMakeFiles/wav_dct.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/wav_dct.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wav_dct.dir/flags.make

CMakeFiles/wav_dct.dir/wav_dct.cpp.o: CMakeFiles/wav_dct.dir/flags.make
CMakeFiles/wav_dct.dir/wav_dct.cpp.o: ../wav_dct.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/diana/Desktop/IC/sndfile-example-src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/wav_dct.dir/wav_dct.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/wav_dct.dir/wav_dct.cpp.o -c /home/diana/Desktop/IC/sndfile-example-src/wav_dct.cpp

CMakeFiles/wav_dct.dir/wav_dct.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wav_dct.dir/wav_dct.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/diana/Desktop/IC/sndfile-example-src/wav_dct.cpp > CMakeFiles/wav_dct.dir/wav_dct.cpp.i

CMakeFiles/wav_dct.dir/wav_dct.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wav_dct.dir/wav_dct.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/diana/Desktop/IC/sndfile-example-src/wav_dct.cpp -o CMakeFiles/wav_dct.dir/wav_dct.cpp.s

# Object files for target wav_dct
wav_dct_OBJECTS = \
"CMakeFiles/wav_dct.dir/wav_dct.cpp.o"

# External object files for target wav_dct
wav_dct_EXTERNAL_OBJECTS =

/home/diana/Desktop/IC/sndfile-example-bin/wav_dct: CMakeFiles/wav_dct.dir/wav_dct.cpp.o
/home/diana/Desktop/IC/sndfile-example-bin/wav_dct: CMakeFiles/wav_dct.dir/build.make
/home/diana/Desktop/IC/sndfile-example-bin/wav_dct: CMakeFiles/wav_dct.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/diana/Desktop/IC/sndfile-example-src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/diana/Desktop/IC/sndfile-example-bin/wav_dct"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wav_dct.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wav_dct.dir/build: /home/diana/Desktop/IC/sndfile-example-bin/wav_dct

.PHONY : CMakeFiles/wav_dct.dir/build

CMakeFiles/wav_dct.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wav_dct.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wav_dct.dir/clean

CMakeFiles/wav_dct.dir/depend:
	cd /home/diana/Desktop/IC/sndfile-example-src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/diana/Desktop/IC/sndfile-example-src /home/diana/Desktop/IC/sndfile-example-src /home/diana/Desktop/IC/sndfile-example-src/build /home/diana/Desktop/IC/sndfile-example-src/build /home/diana/Desktop/IC/sndfile-example-src/build/CMakeFiles/wav_dct.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wav_dct.dir/depend

