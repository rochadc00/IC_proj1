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
CMAKE_COMMAND = /home/hugo/.local/lib/python3.8/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/hugo/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/hugo/IC/sndfile-example-src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hugo/IC/sndfile-example-src/build

# Include any dependencies generated for this target.
include CMakeFiles/wav_cmp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/wav_cmp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/wav_cmp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wav_cmp.dir/flags.make

CMakeFiles/wav_cmp.dir/wav_cmp.cpp.o: CMakeFiles/wav_cmp.dir/flags.make
CMakeFiles/wav_cmp.dir/wav_cmp.cpp.o: ../wav_cmp.cpp
CMakeFiles/wav_cmp.dir/wav_cmp.cpp.o: CMakeFiles/wav_cmp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hugo/IC/sndfile-example-src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/wav_cmp.dir/wav_cmp.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/wav_cmp.dir/wav_cmp.cpp.o -MF CMakeFiles/wav_cmp.dir/wav_cmp.cpp.o.d -o CMakeFiles/wav_cmp.dir/wav_cmp.cpp.o -c /home/hugo/IC/sndfile-example-src/wav_cmp.cpp

CMakeFiles/wav_cmp.dir/wav_cmp.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/wav_cmp.dir/wav_cmp.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hugo/IC/sndfile-example-src/wav_cmp.cpp > CMakeFiles/wav_cmp.dir/wav_cmp.cpp.i

CMakeFiles/wav_cmp.dir/wav_cmp.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/wav_cmp.dir/wav_cmp.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hugo/IC/sndfile-example-src/wav_cmp.cpp -o CMakeFiles/wav_cmp.dir/wav_cmp.cpp.s

# Object files for target wav_cmp
wav_cmp_OBJECTS = \
"CMakeFiles/wav_cmp.dir/wav_cmp.cpp.o"

# External object files for target wav_cmp
wav_cmp_EXTERNAL_OBJECTS =

/home/hugo/IC/sndfile-example-bin/wav_cmp: CMakeFiles/wav_cmp.dir/wav_cmp.cpp.o
/home/hugo/IC/sndfile-example-bin/wav_cmp: CMakeFiles/wav_cmp.dir/build.make
/home/hugo/IC/sndfile-example-bin/wav_cmp: CMakeFiles/wav_cmp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hugo/IC/sndfile-example-src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/hugo/IC/sndfile-example-bin/wav_cmp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wav_cmp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wav_cmp.dir/build: /home/hugo/IC/sndfile-example-bin/wav_cmp
.PHONY : CMakeFiles/wav_cmp.dir/build

CMakeFiles/wav_cmp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wav_cmp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wav_cmp.dir/clean

CMakeFiles/wav_cmp.dir/depend:
	cd /home/hugo/IC/sndfile-example-src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hugo/IC/sndfile-example-src /home/hugo/IC/sndfile-example-src /home/hugo/IC/sndfile-example-src/build /home/hugo/IC/sndfile-example-src/build /home/hugo/IC/sndfile-example-src/build/CMakeFiles/wav_cmp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/wav_cmp.dir/depend

