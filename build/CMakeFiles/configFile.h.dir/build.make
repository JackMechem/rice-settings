# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_SOURCE_DIR = /home/jack/Projects/rice-settings-gui

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jack/Projects/rice-settings-gui/build

# Include any dependencies generated for this target.
include CMakeFiles/configFile.h.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/configFile.h.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/configFile.h.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/configFile.h.dir/flags.make

CMakeFiles/configFile.h.dir/configFile.cpp.o: CMakeFiles/configFile.h.dir/flags.make
CMakeFiles/configFile.h.dir/configFile.cpp.o: /home/jack/Projects/rice-settings-gui/configFile.cpp
CMakeFiles/configFile.h.dir/configFile.cpp.o: CMakeFiles/configFile.h.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/jack/Projects/rice-settings-gui/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/configFile.h.dir/configFile.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/configFile.h.dir/configFile.cpp.o -MF CMakeFiles/configFile.h.dir/configFile.cpp.o.d -o CMakeFiles/configFile.h.dir/configFile.cpp.o -c /home/jack/Projects/rice-settings-gui/configFile.cpp

CMakeFiles/configFile.h.dir/configFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/configFile.h.dir/configFile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jack/Projects/rice-settings-gui/configFile.cpp > CMakeFiles/configFile.h.dir/configFile.cpp.i

CMakeFiles/configFile.h.dir/configFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/configFile.h.dir/configFile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jack/Projects/rice-settings-gui/configFile.cpp -o CMakeFiles/configFile.h.dir/configFile.cpp.s

# Object files for target configFile.h
configFile_h_OBJECTS = \
"CMakeFiles/configFile.h.dir/configFile.cpp.o"

# External object files for target configFile.h
configFile_h_EXTERNAL_OBJECTS =

libconfigFile.h.a: CMakeFiles/configFile.h.dir/configFile.cpp.o
libconfigFile.h.a: CMakeFiles/configFile.h.dir/build.make
libconfigFile.h.a: CMakeFiles/configFile.h.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/jack/Projects/rice-settings-gui/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libconfigFile.h.a"
	$(CMAKE_COMMAND) -P CMakeFiles/configFile.h.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/configFile.h.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/configFile.h.dir/build: libconfigFile.h.a
.PHONY : CMakeFiles/configFile.h.dir/build

CMakeFiles/configFile.h.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/configFile.h.dir/cmake_clean.cmake
.PHONY : CMakeFiles/configFile.h.dir/clean

CMakeFiles/configFile.h.dir/depend:
	cd /home/jack/Projects/rice-settings-gui/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jack/Projects/rice-settings-gui /home/jack/Projects/rice-settings-gui /home/jack/Projects/rice-settings-gui/build /home/jack/Projects/rice-settings-gui/build /home/jack/Projects/rice-settings-gui/build/CMakeFiles/configFile.h.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/configFile.h.dir/depend

