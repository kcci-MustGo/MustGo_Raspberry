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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/rojong/MustGo_raspi/curl-8.5.0

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/rojong/MustGo_raspi/curl-8.5.0

# Include any dependencies generated for this target.
include tests/libtest/CMakeFiles/lib506.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include tests/libtest/CMakeFiles/lib506.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/libtest/CMakeFiles/lib506.dir/progress.make

# Include the compile flags for this target's objects.
include tests/libtest/CMakeFiles/lib506.dir/flags.make

tests/libtest/CMakeFiles/lib506.dir/lib506.c.o: tests/libtest/CMakeFiles/lib506.dir/flags.make
tests/libtest/CMakeFiles/lib506.dir/lib506.c.o: tests/libtest/lib506.c
tests/libtest/CMakeFiles/lib506.dir/lib506.c.o: tests/libtest/CMakeFiles/lib506.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rojong/MustGo_raspi/curl-8.5.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object tests/libtest/CMakeFiles/lib506.dir/lib506.c.o"
	cd /home/rojong/MustGo_raspi/curl-8.5.0/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/libtest/CMakeFiles/lib506.dir/lib506.c.o -MF CMakeFiles/lib506.dir/lib506.c.o.d -o CMakeFiles/lib506.dir/lib506.c.o -c /home/rojong/MustGo_raspi/curl-8.5.0/tests/libtest/lib506.c

tests/libtest/CMakeFiles/lib506.dir/lib506.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib506.dir/lib506.c.i"
	cd /home/rojong/MustGo_raspi/curl-8.5.0/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rojong/MustGo_raspi/curl-8.5.0/tests/libtest/lib506.c > CMakeFiles/lib506.dir/lib506.c.i

tests/libtest/CMakeFiles/lib506.dir/lib506.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib506.dir/lib506.c.s"
	cd /home/rojong/MustGo_raspi/curl-8.5.0/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rojong/MustGo_raspi/curl-8.5.0/tests/libtest/lib506.c -o CMakeFiles/lib506.dir/lib506.c.s

tests/libtest/CMakeFiles/lib506.dir/__/__/lib/timediff.c.o: tests/libtest/CMakeFiles/lib506.dir/flags.make
tests/libtest/CMakeFiles/lib506.dir/__/__/lib/timediff.c.o: lib/timediff.c
tests/libtest/CMakeFiles/lib506.dir/__/__/lib/timediff.c.o: tests/libtest/CMakeFiles/lib506.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rojong/MustGo_raspi/curl-8.5.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object tests/libtest/CMakeFiles/lib506.dir/__/__/lib/timediff.c.o"
	cd /home/rojong/MustGo_raspi/curl-8.5.0/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/libtest/CMakeFiles/lib506.dir/__/__/lib/timediff.c.o -MF CMakeFiles/lib506.dir/__/__/lib/timediff.c.o.d -o CMakeFiles/lib506.dir/__/__/lib/timediff.c.o -c /home/rojong/MustGo_raspi/curl-8.5.0/lib/timediff.c

tests/libtest/CMakeFiles/lib506.dir/__/__/lib/timediff.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib506.dir/__/__/lib/timediff.c.i"
	cd /home/rojong/MustGo_raspi/curl-8.5.0/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rojong/MustGo_raspi/curl-8.5.0/lib/timediff.c > CMakeFiles/lib506.dir/__/__/lib/timediff.c.i

tests/libtest/CMakeFiles/lib506.dir/__/__/lib/timediff.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib506.dir/__/__/lib/timediff.c.s"
	cd /home/rojong/MustGo_raspi/curl-8.5.0/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rojong/MustGo_raspi/curl-8.5.0/lib/timediff.c -o CMakeFiles/lib506.dir/__/__/lib/timediff.c.s

tests/libtest/CMakeFiles/lib506.dir/first.c.o: tests/libtest/CMakeFiles/lib506.dir/flags.make
tests/libtest/CMakeFiles/lib506.dir/first.c.o: tests/libtest/first.c
tests/libtest/CMakeFiles/lib506.dir/first.c.o: tests/libtest/CMakeFiles/lib506.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rojong/MustGo_raspi/curl-8.5.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object tests/libtest/CMakeFiles/lib506.dir/first.c.o"
	cd /home/rojong/MustGo_raspi/curl-8.5.0/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT tests/libtest/CMakeFiles/lib506.dir/first.c.o -MF CMakeFiles/lib506.dir/first.c.o.d -o CMakeFiles/lib506.dir/first.c.o -c /home/rojong/MustGo_raspi/curl-8.5.0/tests/libtest/first.c

tests/libtest/CMakeFiles/lib506.dir/first.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/lib506.dir/first.c.i"
	cd /home/rojong/MustGo_raspi/curl-8.5.0/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/rojong/MustGo_raspi/curl-8.5.0/tests/libtest/first.c > CMakeFiles/lib506.dir/first.c.i

tests/libtest/CMakeFiles/lib506.dir/first.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/lib506.dir/first.c.s"
	cd /home/rojong/MustGo_raspi/curl-8.5.0/tests/libtest && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/rojong/MustGo_raspi/curl-8.5.0/tests/libtest/first.c -o CMakeFiles/lib506.dir/first.c.s

# Object files for target lib506
lib506_OBJECTS = \
"CMakeFiles/lib506.dir/lib506.c.o" \
"CMakeFiles/lib506.dir/__/__/lib/timediff.c.o" \
"CMakeFiles/lib506.dir/first.c.o"

# External object files for target lib506
lib506_EXTERNAL_OBJECTS =

tests/libtest/lib506: tests/libtest/CMakeFiles/lib506.dir/lib506.c.o
tests/libtest/lib506: tests/libtest/CMakeFiles/lib506.dir/__/__/lib/timediff.c.o
tests/libtest/lib506: tests/libtest/CMakeFiles/lib506.dir/first.c.o
tests/libtest/lib506: tests/libtest/CMakeFiles/lib506.dir/build.make
tests/libtest/lib506: lib/libcurl.so.4.8.0
tests/libtest/lib506: /usr/lib/x86_64-linux-gnu/libssl.so
tests/libtest/lib506: /usr/lib/x86_64-linux-gnu/libcrypto.so
tests/libtest/lib506: /usr/lib/x86_64-linux-gnu/libz.so
tests/libtest/lib506: tests/libtest/CMakeFiles/lib506.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rojong/MustGo_raspi/curl-8.5.0/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable lib506"
	cd /home/rojong/MustGo_raspi/curl-8.5.0/tests/libtest && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lib506.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/libtest/CMakeFiles/lib506.dir/build: tests/libtest/lib506
.PHONY : tests/libtest/CMakeFiles/lib506.dir/build

tests/libtest/CMakeFiles/lib506.dir/clean:
	cd /home/rojong/MustGo_raspi/curl-8.5.0/tests/libtest && $(CMAKE_COMMAND) -P CMakeFiles/lib506.dir/cmake_clean.cmake
.PHONY : tests/libtest/CMakeFiles/lib506.dir/clean

tests/libtest/CMakeFiles/lib506.dir/depend:
	cd /home/rojong/MustGo_raspi/curl-8.5.0 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/rojong/MustGo_raspi/curl-8.5.0 /home/rojong/MustGo_raspi/curl-8.5.0/tests/libtest /home/rojong/MustGo_raspi/curl-8.5.0 /home/rojong/MustGo_raspi/curl-8.5.0/tests/libtest /home/rojong/MustGo_raspi/curl-8.5.0/tests/libtest/CMakeFiles/lib506.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/libtest/CMakeFiles/lib506.dir/depend

