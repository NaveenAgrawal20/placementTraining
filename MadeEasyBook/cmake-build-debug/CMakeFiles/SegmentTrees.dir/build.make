# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\software\cliongip\installedClion\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\software\cliongip\installedClion\CLion 2019.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\data_strc\usingjava\Competitive\DsaCompttv\WithCpp\MadeEasyBook

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\data_strc\usingjava\Competitive\DsaCompttv\WithCpp\MadeEasyBook\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SegmentTrees.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SegmentTrees.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SegmentTrees.dir/flags.make

CMakeFiles/SegmentTrees.dir/SegmentTrees.cpp.obj: CMakeFiles/SegmentTrees.dir/flags.make
CMakeFiles/SegmentTrees.dir/SegmentTrees.cpp.obj: ../SegmentTrees.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\data_strc\usingjava\Competitive\DsaCompttv\WithCpp\MadeEasyBook\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SegmentTrees.dir/SegmentTrees.cpp.obj"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SegmentTrees.dir\SegmentTrees.cpp.obj -c E:\data_strc\usingjava\Competitive\DsaCompttv\WithCpp\MadeEasyBook\SegmentTrees.cpp

CMakeFiles/SegmentTrees.dir/SegmentTrees.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SegmentTrees.dir/SegmentTrees.cpp.i"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\data_strc\usingjava\Competitive\DsaCompttv\WithCpp\MadeEasyBook\SegmentTrees.cpp > CMakeFiles\SegmentTrees.dir\SegmentTrees.cpp.i

CMakeFiles/SegmentTrees.dir/SegmentTrees.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SegmentTrees.dir/SegmentTrees.cpp.s"
	C:\PROGRA~2\MINGW-~1\I686-8~1.0-P\mingw32\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\data_strc\usingjava\Competitive\DsaCompttv\WithCpp\MadeEasyBook\SegmentTrees.cpp -o CMakeFiles\SegmentTrees.dir\SegmentTrees.cpp.s

# Object files for target SegmentTrees
SegmentTrees_OBJECTS = \
"CMakeFiles/SegmentTrees.dir/SegmentTrees.cpp.obj"

# External object files for target SegmentTrees
SegmentTrees_EXTERNAL_OBJECTS =

SegmentTrees.exe: CMakeFiles/SegmentTrees.dir/SegmentTrees.cpp.obj
SegmentTrees.exe: CMakeFiles/SegmentTrees.dir/build.make
SegmentTrees.exe: CMakeFiles/SegmentTrees.dir/linklibs.rsp
SegmentTrees.exe: CMakeFiles/SegmentTrees.dir/objects1.rsp
SegmentTrees.exe: CMakeFiles/SegmentTrees.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\data_strc\usingjava\Competitive\DsaCompttv\WithCpp\MadeEasyBook\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SegmentTrees.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SegmentTrees.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SegmentTrees.dir/build: SegmentTrees.exe

.PHONY : CMakeFiles/SegmentTrees.dir/build

CMakeFiles/SegmentTrees.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SegmentTrees.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SegmentTrees.dir/clean

CMakeFiles/SegmentTrees.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\data_strc\usingjava\Competitive\DsaCompttv\WithCpp\MadeEasyBook E:\data_strc\usingjava\Competitive\DsaCompttv\WithCpp\MadeEasyBook E:\data_strc\usingjava\Competitive\DsaCompttv\WithCpp\MadeEasyBook\cmake-build-debug E:\data_strc\usingjava\Competitive\DsaCompttv\WithCpp\MadeEasyBook\cmake-build-debug E:\data_strc\usingjava\Competitive\DsaCompttv\WithCpp\MadeEasyBook\cmake-build-debug\CMakeFiles\SegmentTrees.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SegmentTrees.dir/depend
