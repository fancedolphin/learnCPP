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
CMAKE_COMMAND = "D:\dev\CLion 2023.1.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "D:\dev\CLion 2023.1.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\learningc++\202118010428-coursework

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\learningc++\202118010428-coursework\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/textadv.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/textadv.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/textadv.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/textadv.dir/flags.make

CMakeFiles/textadv.dir/main.cpp.obj: CMakeFiles/textadv.dir/flags.make
CMakeFiles/textadv.dir/main.cpp.obj: D:/learningc++/202118010428-coursework/main.cpp
CMakeFiles/textadv.dir/main.cpp.obj: CMakeFiles/textadv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\learningc++\202118010428-coursework\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/textadv.dir/main.cpp.obj"
	"D:\dev\CLion 2023.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/textadv.dir/main.cpp.obj -MF CMakeFiles\textadv.dir\main.cpp.obj.d -o CMakeFiles\textadv.dir\main.cpp.obj -c D:\learningc++\202118010428-coursework\main.cpp

CMakeFiles/textadv.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/textadv.dir/main.cpp.i"
	"D:\dev\CLion 2023.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\learningc++\202118010428-coursework\main.cpp > CMakeFiles\textadv.dir\main.cpp.i

CMakeFiles/textadv.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/textadv.dir/main.cpp.s"
	"D:\dev\CLion 2023.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\learningc++\202118010428-coursework\main.cpp -o CMakeFiles\textadv.dir\main.cpp.s

CMakeFiles/textadv.dir/Room.cpp.obj: CMakeFiles/textadv.dir/flags.make
CMakeFiles/textadv.dir/Room.cpp.obj: D:/learningc++/202118010428-coursework/Room.cpp
CMakeFiles/textadv.dir/Room.cpp.obj: CMakeFiles/textadv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\learningc++\202118010428-coursework\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/textadv.dir/Room.cpp.obj"
	"D:\dev\CLion 2023.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/textadv.dir/Room.cpp.obj -MF CMakeFiles\textadv.dir\Room.cpp.obj.d -o CMakeFiles\textadv.dir\Room.cpp.obj -c D:\learningc++\202118010428-coursework\Room.cpp

CMakeFiles/textadv.dir/Room.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/textadv.dir/Room.cpp.i"
	"D:\dev\CLion 2023.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\learningc++\202118010428-coursework\Room.cpp > CMakeFiles\textadv.dir\Room.cpp.i

CMakeFiles/textadv.dir/Room.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/textadv.dir/Room.cpp.s"
	"D:\dev\CLion 2023.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\learningc++\202118010428-coursework\Room.cpp -o CMakeFiles\textadv.dir\Room.cpp.s

CMakeFiles/textadv.dir/wordwrap.cpp.obj: CMakeFiles/textadv.dir/flags.make
CMakeFiles/textadv.dir/wordwrap.cpp.obj: D:/learningc++/202118010428-coursework/wordwrap.cpp
CMakeFiles/textadv.dir/wordwrap.cpp.obj: CMakeFiles/textadv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\learningc++\202118010428-coursework\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/textadv.dir/wordwrap.cpp.obj"
	"D:\dev\CLion 2023.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/textadv.dir/wordwrap.cpp.obj -MF CMakeFiles\textadv.dir\wordwrap.cpp.obj.d -o CMakeFiles\textadv.dir\wordwrap.cpp.obj -c D:\learningc++\202118010428-coursework\wordwrap.cpp

CMakeFiles/textadv.dir/wordwrap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/textadv.dir/wordwrap.cpp.i"
	"D:\dev\CLion 2023.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\learningc++\202118010428-coursework\wordwrap.cpp > CMakeFiles\textadv.dir\wordwrap.cpp.i

CMakeFiles/textadv.dir/wordwrap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/textadv.dir/wordwrap.cpp.s"
	"D:\dev\CLion 2023.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\learningc++\202118010428-coursework\wordwrap.cpp -o CMakeFiles\textadv.dir\wordwrap.cpp.s

CMakeFiles/textadv.dir/State.cpp.obj: CMakeFiles/textadv.dir/flags.make
CMakeFiles/textadv.dir/State.cpp.obj: D:/learningc++/202118010428-coursework/State.cpp
CMakeFiles/textadv.dir/State.cpp.obj: CMakeFiles/textadv.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\learningc++\202118010428-coursework\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/textadv.dir/State.cpp.obj"
	"D:\dev\CLion 2023.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/textadv.dir/State.cpp.obj -MF CMakeFiles\textadv.dir\State.cpp.obj.d -o CMakeFiles\textadv.dir\State.cpp.obj -c D:\learningc++\202118010428-coursework\State.cpp

CMakeFiles/textadv.dir/State.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/textadv.dir/State.cpp.i"
	"D:\dev\CLion 2023.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\learningc++\202118010428-coursework\State.cpp > CMakeFiles\textadv.dir\State.cpp.i

CMakeFiles/textadv.dir/State.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/textadv.dir/State.cpp.s"
	"D:\dev\CLion 2023.1.1\bin\mingw\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\learningc++\202118010428-coursework\State.cpp -o CMakeFiles\textadv.dir\State.cpp.s

# Object files for target textadv
textadv_OBJECTS = \
"CMakeFiles/textadv.dir/main.cpp.obj" \
"CMakeFiles/textadv.dir/Room.cpp.obj" \
"CMakeFiles/textadv.dir/wordwrap.cpp.obj" \
"CMakeFiles/textadv.dir/State.cpp.obj"

# External object files for target textadv
textadv_EXTERNAL_OBJECTS =

textadv.exe: CMakeFiles/textadv.dir/main.cpp.obj
textadv.exe: CMakeFiles/textadv.dir/Room.cpp.obj
textadv.exe: CMakeFiles/textadv.dir/wordwrap.cpp.obj
textadv.exe: CMakeFiles/textadv.dir/State.cpp.obj
textadv.exe: CMakeFiles/textadv.dir/build.make
textadv.exe: CMakeFiles/textadv.dir/linkLibs.rsp
textadv.exe: CMakeFiles/textadv.dir/objects1
textadv.exe: CMakeFiles/textadv.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\learningc++\202118010428-coursework\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable textadv.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\textadv.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/textadv.dir/build: textadv.exe
.PHONY : CMakeFiles/textadv.dir/build

CMakeFiles/textadv.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\textadv.dir\cmake_clean.cmake
.PHONY : CMakeFiles/textadv.dir/clean

CMakeFiles/textadv.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\learningc++\202118010428-coursework D:\learningc++\202118010428-coursework D:\learningc++\202118010428-coursework\cmake-build-debug D:\learningc++\202118010428-coursework\cmake-build-debug D:\learningc++\202118010428-coursework\cmake-build-debug\CMakeFiles\textadv.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/textadv.dir/depend
