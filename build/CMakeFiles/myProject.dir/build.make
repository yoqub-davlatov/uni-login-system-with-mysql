# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.25

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\yoqub\OneDrive\Documents\C++ programming\cmakeWithMySQL"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\yoqub\OneDrive\Documents\C++ programming\cmakeWithMySQL\build"

# Include any dependencies generated for this target.
include CMakeFiles/myProject.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/myProject.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/myProject.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myProject.dir/flags.make

CMakeFiles/myProject.dir/src/main.cpp.obj: CMakeFiles/myProject.dir/flags.make
CMakeFiles/myProject.dir/src/main.cpp.obj: CMakeFiles/myProject.dir/includes_CXX.rsp
CMakeFiles/myProject.dir/src/main.cpp.obj: C:/Users/yoqub/OneDrive/Documents/C++\ programming/cmakeWithMySQL/src/main.cpp
CMakeFiles/myProject.dir/src/main.cpp.obj: CMakeFiles/myProject.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\yoqub\OneDrive\Documents\C++ programming\cmakeWithMySQL\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/myProject.dir/src/main.cpp.obj"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/myProject.dir/src/main.cpp.obj -MF CMakeFiles\myProject.dir\src\main.cpp.obj.d -o CMakeFiles\myProject.dir\src\main.cpp.obj -c "C:\Users\yoqub\OneDrive\Documents\C++ programming\cmakeWithMySQL\src\main.cpp"

CMakeFiles/myProject.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myProject.dir/src/main.cpp.i"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "C:\Users\yoqub\OneDrive\Documents\C++ programming\cmakeWithMySQL\src\main.cpp" > CMakeFiles\myProject.dir\src\main.cpp.i

CMakeFiles/myProject.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myProject.dir/src/main.cpp.s"
	C:\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "C:\Users\yoqub\OneDrive\Documents\C++ programming\cmakeWithMySQL\src\main.cpp" -o CMakeFiles\myProject.dir\src\main.cpp.s

# Object files for target myProject
myProject_OBJECTS = \
"CMakeFiles/myProject.dir/src/main.cpp.obj"

# External object files for target myProject
myProject_EXTERNAL_OBJECTS =

myProject.exe: CMakeFiles/myProject.dir/src/main.cpp.obj
myProject.exe: CMakeFiles/myProject.dir/build.make
myProject.exe: CMakeFiles/myProject.dir/linkLibs.rsp
myProject.exe: CMakeFiles/myProject.dir/objects1
myProject.exe: CMakeFiles/myProject.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\yoqub\OneDrive\Documents\C++ programming\cmakeWithMySQL\build\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable myProject.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\myProject.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myProject.dir/build: myProject.exe
.PHONY : CMakeFiles/myProject.dir/build

CMakeFiles/myProject.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\myProject.dir\cmake_clean.cmake
.PHONY : CMakeFiles/myProject.dir/clean

CMakeFiles/myProject.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\yoqub\OneDrive\Documents\C++ programming\cmakeWithMySQL" "C:\Users\yoqub\OneDrive\Documents\C++ programming\cmakeWithMySQL" "C:\Users\yoqub\OneDrive\Documents\C++ programming\cmakeWithMySQL\build" "C:\Users\yoqub\OneDrive\Documents\C++ programming\cmakeWithMySQL\build" "C:\Users\yoqub\OneDrive\Documents\C++ programming\cmakeWithMySQL\build\CMakeFiles\myProject.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/myProject.dir/depend

