# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/chiao/documents/objectR

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chiao/documents/objectR/build

# Include any dependencies generated for this target.
include CMakeFiles/libobjectR.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libobjectR.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libobjectR.dir/flags.make

CMakeFiles/libobjectR.dir/src/DetectBlueCircle.cpp.o: CMakeFiles/libobjectR.dir/flags.make
CMakeFiles/libobjectR.dir/src/DetectBlueCircle.cpp.o: ../src/DetectBlueCircle.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/chiao/documents/objectR/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/libobjectR.dir/src/DetectBlueCircle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libobjectR.dir/src/DetectBlueCircle.cpp.o -c /home/chiao/documents/objectR/src/DetectBlueCircle.cpp

CMakeFiles/libobjectR.dir/src/DetectBlueCircle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libobjectR.dir/src/DetectBlueCircle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/chiao/documents/objectR/src/DetectBlueCircle.cpp > CMakeFiles/libobjectR.dir/src/DetectBlueCircle.cpp.i

CMakeFiles/libobjectR.dir/src/DetectBlueCircle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libobjectR.dir/src/DetectBlueCircle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/chiao/documents/objectR/src/DetectBlueCircle.cpp -o CMakeFiles/libobjectR.dir/src/DetectBlueCircle.cpp.s

CMakeFiles/libobjectR.dir/src/DetectBlueCircle.cpp.o.requires:
.PHONY : CMakeFiles/libobjectR.dir/src/DetectBlueCircle.cpp.o.requires

CMakeFiles/libobjectR.dir/src/DetectBlueCircle.cpp.o.provides: CMakeFiles/libobjectR.dir/src/DetectBlueCircle.cpp.o.requires
	$(MAKE) -f CMakeFiles/libobjectR.dir/build.make CMakeFiles/libobjectR.dir/src/DetectBlueCircle.cpp.o.provides.build
.PHONY : CMakeFiles/libobjectR.dir/src/DetectBlueCircle.cpp.o.provides

CMakeFiles/libobjectR.dir/src/DetectBlueCircle.cpp.o.provides.build: CMakeFiles/libobjectR.dir/src/DetectBlueCircle.cpp.o

CMakeFiles/libobjectR.dir/src/DetectMarker.cpp.o: CMakeFiles/libobjectR.dir/flags.make
CMakeFiles/libobjectR.dir/src/DetectMarker.cpp.o: ../src/DetectMarker.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/chiao/documents/objectR/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/libobjectR.dir/src/DetectMarker.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libobjectR.dir/src/DetectMarker.cpp.o -c /home/chiao/documents/objectR/src/DetectMarker.cpp

CMakeFiles/libobjectR.dir/src/DetectMarker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libobjectR.dir/src/DetectMarker.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/chiao/documents/objectR/src/DetectMarker.cpp > CMakeFiles/libobjectR.dir/src/DetectMarker.cpp.i

CMakeFiles/libobjectR.dir/src/DetectMarker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libobjectR.dir/src/DetectMarker.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/chiao/documents/objectR/src/DetectMarker.cpp -o CMakeFiles/libobjectR.dir/src/DetectMarker.cpp.s

CMakeFiles/libobjectR.dir/src/DetectMarker.cpp.o.requires:
.PHONY : CMakeFiles/libobjectR.dir/src/DetectMarker.cpp.o.requires

CMakeFiles/libobjectR.dir/src/DetectMarker.cpp.o.provides: CMakeFiles/libobjectR.dir/src/DetectMarker.cpp.o.requires
	$(MAKE) -f CMakeFiles/libobjectR.dir/build.make CMakeFiles/libobjectR.dir/src/DetectMarker.cpp.o.provides.build
.PHONY : CMakeFiles/libobjectR.dir/src/DetectMarker.cpp.o.provides

CMakeFiles/libobjectR.dir/src/DetectMarker.cpp.o.provides.build: CMakeFiles/libobjectR.dir/src/DetectMarker.cpp.o

CMakeFiles/libobjectR.dir/src/setting.cpp.o: CMakeFiles/libobjectR.dir/flags.make
CMakeFiles/libobjectR.dir/src/setting.cpp.o: ../src/setting.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/chiao/documents/objectR/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/libobjectR.dir/src/setting.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libobjectR.dir/src/setting.cpp.o -c /home/chiao/documents/objectR/src/setting.cpp

CMakeFiles/libobjectR.dir/src/setting.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libobjectR.dir/src/setting.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/chiao/documents/objectR/src/setting.cpp > CMakeFiles/libobjectR.dir/src/setting.cpp.i

CMakeFiles/libobjectR.dir/src/setting.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libobjectR.dir/src/setting.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/chiao/documents/objectR/src/setting.cpp -o CMakeFiles/libobjectR.dir/src/setting.cpp.s

CMakeFiles/libobjectR.dir/src/setting.cpp.o.requires:
.PHONY : CMakeFiles/libobjectR.dir/src/setting.cpp.o.requires

CMakeFiles/libobjectR.dir/src/setting.cpp.o.provides: CMakeFiles/libobjectR.dir/src/setting.cpp.o.requires
	$(MAKE) -f CMakeFiles/libobjectR.dir/build.make CMakeFiles/libobjectR.dir/src/setting.cpp.o.provides.build
.PHONY : CMakeFiles/libobjectR.dir/src/setting.cpp.o.provides

CMakeFiles/libobjectR.dir/src/setting.cpp.o.provides.build: CMakeFiles/libobjectR.dir/src/setting.cpp.o

# Object files for target libobjectR
libobjectR_OBJECTS = \
"CMakeFiles/libobjectR.dir/src/DetectBlueCircle.cpp.o" \
"CMakeFiles/libobjectR.dir/src/DetectMarker.cpp.o" \
"CMakeFiles/libobjectR.dir/src/setting.cpp.o"

# External object files for target libobjectR
libobjectR_EXTERNAL_OBJECTS =

liblibobjectR.a: CMakeFiles/libobjectR.dir/src/DetectBlueCircle.cpp.o
liblibobjectR.a: CMakeFiles/libobjectR.dir/src/DetectMarker.cpp.o
liblibobjectR.a: CMakeFiles/libobjectR.dir/src/setting.cpp.o
liblibobjectR.a: CMakeFiles/libobjectR.dir/build.make
liblibobjectR.a: CMakeFiles/libobjectR.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library liblibobjectR.a"
	$(CMAKE_COMMAND) -P CMakeFiles/libobjectR.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libobjectR.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libobjectR.dir/build: liblibobjectR.a
.PHONY : CMakeFiles/libobjectR.dir/build

CMakeFiles/libobjectR.dir/requires: CMakeFiles/libobjectR.dir/src/DetectBlueCircle.cpp.o.requires
CMakeFiles/libobjectR.dir/requires: CMakeFiles/libobjectR.dir/src/DetectMarker.cpp.o.requires
CMakeFiles/libobjectR.dir/requires: CMakeFiles/libobjectR.dir/src/setting.cpp.o.requires
.PHONY : CMakeFiles/libobjectR.dir/requires

CMakeFiles/libobjectR.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libobjectR.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libobjectR.dir/clean

CMakeFiles/libobjectR.dir/depend:
	cd /home/chiao/documents/objectR/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chiao/documents/objectR /home/chiao/documents/objectR /home/chiao/documents/objectR/build /home/chiao/documents/objectR/build /home/chiao/documents/objectR/build/CMakeFiles/libobjectR.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libobjectR.dir/depend

