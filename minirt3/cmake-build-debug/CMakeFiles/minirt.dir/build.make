# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wrudy/Desktop/minirt3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wrudy/Desktop/minirt3/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/minirt.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/minirt.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/minirt.dir/flags.make

CMakeFiles/minirt.dir/main.c.o: CMakeFiles/minirt.dir/flags.make
CMakeFiles/minirt.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wrudy/Desktop/minirt3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/minirt.dir/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minirt.dir/main.c.o   -c /Users/wrudy/Desktop/minirt3/main.c

CMakeFiles/minirt.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minirt.dir/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wrudy/Desktop/minirt3/main.c > CMakeFiles/minirt.dir/main.c.i

CMakeFiles/minirt.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minirt.dir/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wrudy/Desktop/minirt3/main.c -o CMakeFiles/minirt.dir/main.c.s

CMakeFiles/minirt.dir/linalg/vecalg.c.o: CMakeFiles/minirt.dir/flags.make
CMakeFiles/minirt.dir/linalg/vecalg.c.o: ../linalg/vecalg.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wrudy/Desktop/minirt3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/minirt.dir/linalg/vecalg.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minirt.dir/linalg/vecalg.c.o   -c /Users/wrudy/Desktop/minirt3/linalg/vecalg.c

CMakeFiles/minirt.dir/linalg/vecalg.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minirt.dir/linalg/vecalg.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wrudy/Desktop/minirt3/linalg/vecalg.c > CMakeFiles/minirt.dir/linalg/vecalg.c.i

CMakeFiles/minirt.dir/linalg/vecalg.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minirt.dir/linalg/vecalg.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wrudy/Desktop/minirt3/linalg/vecalg.c -o CMakeFiles/minirt.dir/linalg/vecalg.c.s

CMakeFiles/minirt.dir/canvas/color.c.o: CMakeFiles/minirt.dir/flags.make
CMakeFiles/minirt.dir/canvas/color.c.o: ../canvas/color.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wrudy/Desktop/minirt3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/minirt.dir/canvas/color.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minirt.dir/canvas/color.c.o   -c /Users/wrudy/Desktop/minirt3/canvas/color.c

CMakeFiles/minirt.dir/canvas/color.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minirt.dir/canvas/color.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wrudy/Desktop/minirt3/canvas/color.c > CMakeFiles/minirt.dir/canvas/color.c.i

CMakeFiles/minirt.dir/canvas/color.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minirt.dir/canvas/color.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wrudy/Desktop/minirt3/canvas/color.c -o CMakeFiles/minirt.dir/canvas/color.c.s

CMakeFiles/minirt.dir/canvas/canvas.c.o: CMakeFiles/minirt.dir/flags.make
CMakeFiles/minirt.dir/canvas/canvas.c.o: ../canvas/canvas.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wrudy/Desktop/minirt3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/minirt.dir/canvas/canvas.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minirt.dir/canvas/canvas.c.o   -c /Users/wrudy/Desktop/minirt3/canvas/canvas.c

CMakeFiles/minirt.dir/canvas/canvas.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minirt.dir/canvas/canvas.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wrudy/Desktop/minirt3/canvas/canvas.c > CMakeFiles/minirt.dir/canvas/canvas.c.i

CMakeFiles/minirt.dir/canvas/canvas.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minirt.dir/canvas/canvas.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wrudy/Desktop/minirt3/canvas/canvas.c -o CMakeFiles/minirt.dir/canvas/canvas.c.s

CMakeFiles/minirt.dir/scene/light.c.o: CMakeFiles/minirt.dir/flags.make
CMakeFiles/minirt.dir/scene/light.c.o: ../scene/light.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wrudy/Desktop/minirt3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/minirt.dir/scene/light.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minirt.dir/scene/light.c.o   -c /Users/wrudy/Desktop/minirt3/scene/light.c

CMakeFiles/minirt.dir/scene/light.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minirt.dir/scene/light.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wrudy/Desktop/minirt3/scene/light.c > CMakeFiles/minirt.dir/scene/light.c.i

CMakeFiles/minirt.dir/scene/light.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minirt.dir/scene/light.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wrudy/Desktop/minirt3/scene/light.c -o CMakeFiles/minirt.dir/scene/light.c.s

CMakeFiles/minirt.dir/scene/camera.c.o: CMakeFiles/minirt.dir/flags.make
CMakeFiles/minirt.dir/scene/camera.c.o: ../scene/camera.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wrudy/Desktop/minirt3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/minirt.dir/scene/camera.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minirt.dir/scene/camera.c.o   -c /Users/wrudy/Desktop/minirt3/scene/camera.c

CMakeFiles/minirt.dir/scene/camera.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minirt.dir/scene/camera.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wrudy/Desktop/minirt3/scene/camera.c > CMakeFiles/minirt.dir/scene/camera.c.i

CMakeFiles/minirt.dir/scene/camera.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minirt.dir/scene/camera.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wrudy/Desktop/minirt3/scene/camera.c -o CMakeFiles/minirt.dir/scene/camera.c.s

CMakeFiles/minirt.dir/scene/scene.c.o: CMakeFiles/minirt.dir/flags.make
CMakeFiles/minirt.dir/scene/scene.c.o: ../scene/scene.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wrudy/Desktop/minirt3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/minirt.dir/scene/scene.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minirt.dir/scene/scene.c.o   -c /Users/wrudy/Desktop/minirt3/scene/scene.c

CMakeFiles/minirt.dir/scene/scene.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minirt.dir/scene/scene.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wrudy/Desktop/minirt3/scene/scene.c > CMakeFiles/minirt.dir/scene/scene.c.i

CMakeFiles/minirt.dir/scene/scene.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minirt.dir/scene/scene.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wrudy/Desktop/minirt3/scene/scene.c -o CMakeFiles/minirt.dir/scene/scene.c.s

CMakeFiles/minirt.dir/scene/scene_objects/sphere.c.o: CMakeFiles/minirt.dir/flags.make
CMakeFiles/minirt.dir/scene/scene_objects/sphere.c.o: ../scene/scene_objects/sphere.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wrudy/Desktop/minirt3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/minirt.dir/scene/scene_objects/sphere.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minirt.dir/scene/scene_objects/sphere.c.o   -c /Users/wrudy/Desktop/minirt3/scene/scene_objects/sphere.c

CMakeFiles/minirt.dir/scene/scene_objects/sphere.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minirt.dir/scene/scene_objects/sphere.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wrudy/Desktop/minirt3/scene/scene_objects/sphere.c > CMakeFiles/minirt.dir/scene/scene_objects/sphere.c.i

CMakeFiles/minirt.dir/scene/scene_objects/sphere.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minirt.dir/scene/scene_objects/sphere.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wrudy/Desktop/minirt3/scene/scene_objects/sphere.c -o CMakeFiles/minirt.dir/scene/scene_objects/sphere.c.s

CMakeFiles/minirt.dir/render.c.o: CMakeFiles/minirt.dir/flags.make
CMakeFiles/minirt.dir/render.c.o: ../render.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wrudy/Desktop/minirt3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/minirt.dir/render.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minirt.dir/render.c.o   -c /Users/wrudy/Desktop/minirt3/render.c

CMakeFiles/minirt.dir/render.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minirt.dir/render.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wrudy/Desktop/minirt3/render.c > CMakeFiles/minirt.dir/render.c.i

CMakeFiles/minirt.dir/render.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minirt.dir/render.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wrudy/Desktop/minirt3/render.c -o CMakeFiles/minirt.dir/render.c.s

CMakeFiles/minirt.dir/raytrace/raytrace.c.o: CMakeFiles/minirt.dir/flags.make
CMakeFiles/minirt.dir/raytrace/raytrace.c.o: ../raytrace/raytrace.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wrudy/Desktop/minirt3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/minirt.dir/raytrace/raytrace.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minirt.dir/raytrace/raytrace.c.o   -c /Users/wrudy/Desktop/minirt3/raytrace/raytrace.c

CMakeFiles/minirt.dir/raytrace/raytrace.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minirt.dir/raytrace/raytrace.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wrudy/Desktop/minirt3/raytrace/raytrace.c > CMakeFiles/minirt.dir/raytrace/raytrace.c.i

CMakeFiles/minirt.dir/raytrace/raytrace.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minirt.dir/raytrace/raytrace.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wrudy/Desktop/minirt3/raytrace/raytrace.c -o CMakeFiles/minirt.dir/raytrace/raytrace.c.s

CMakeFiles/minirt.dir/scene/scene_objects/object.c.o: CMakeFiles/minirt.dir/flags.make
CMakeFiles/minirt.dir/scene/scene_objects/object.c.o: ../scene/scene_objects/object.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wrudy/Desktop/minirt3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/minirt.dir/scene/scene_objects/object.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minirt.dir/scene/scene_objects/object.c.o   -c /Users/wrudy/Desktop/minirt3/scene/scene_objects/object.c

CMakeFiles/minirt.dir/scene/scene_objects/object.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minirt.dir/scene/scene_objects/object.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wrudy/Desktop/minirt3/scene/scene_objects/object.c > CMakeFiles/minirt.dir/scene/scene_objects/object.c.i

CMakeFiles/minirt.dir/scene/scene_objects/object.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minirt.dir/scene/scene_objects/object.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wrudy/Desktop/minirt3/scene/scene_objects/object.c -o CMakeFiles/minirt.dir/scene/scene_objects/object.c.s

CMakeFiles/minirt.dir/raytrace/ray.c.o: CMakeFiles/minirt.dir/flags.make
CMakeFiles/minirt.dir/raytrace/ray.c.o: ../raytrace/ray.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wrudy/Desktop/minirt3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building C object CMakeFiles/minirt.dir/raytrace/ray.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minirt.dir/raytrace/ray.c.o   -c /Users/wrudy/Desktop/minirt3/raytrace/ray.c

CMakeFiles/minirt.dir/raytrace/ray.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minirt.dir/raytrace/ray.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wrudy/Desktop/minirt3/raytrace/ray.c > CMakeFiles/minirt.dir/raytrace/ray.c.i

CMakeFiles/minirt.dir/raytrace/ray.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minirt.dir/raytrace/ray.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wrudy/Desktop/minirt3/raytrace/ray.c -o CMakeFiles/minirt.dir/raytrace/ray.c.s

CMakeFiles/minirt.dir/raytrace/intersection.c.o: CMakeFiles/minirt.dir/flags.make
CMakeFiles/minirt.dir/raytrace/intersection.c.o: ../raytrace/intersection.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wrudy/Desktop/minirt3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building C object CMakeFiles/minirt.dir/raytrace/intersection.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minirt.dir/raytrace/intersection.c.o   -c /Users/wrudy/Desktop/minirt3/raytrace/intersection.c

CMakeFiles/minirt.dir/raytrace/intersection.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minirt.dir/raytrace/intersection.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wrudy/Desktop/minirt3/raytrace/intersection.c > CMakeFiles/minirt.dir/raytrace/intersection.c.i

CMakeFiles/minirt.dir/raytrace/intersection.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minirt.dir/raytrace/intersection.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wrudy/Desktop/minirt3/raytrace/intersection.c -o CMakeFiles/minirt.dir/raytrace/intersection.c.s

CMakeFiles/minirt.dir/scene/scene_objects/plane.c.o: CMakeFiles/minirt.dir/flags.make
CMakeFiles/minirt.dir/scene/scene_objects/plane.c.o: ../scene/scene_objects/plane.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wrudy/Desktop/minirt3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building C object CMakeFiles/minirt.dir/scene/scene_objects/plane.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minirt.dir/scene/scene_objects/plane.c.o   -c /Users/wrudy/Desktop/minirt3/scene/scene_objects/plane.c

CMakeFiles/minirt.dir/scene/scene_objects/plane.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minirt.dir/scene/scene_objects/plane.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wrudy/Desktop/minirt3/scene/scene_objects/plane.c > CMakeFiles/minirt.dir/scene/scene_objects/plane.c.i

CMakeFiles/minirt.dir/scene/scene_objects/plane.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minirt.dir/scene/scene_objects/plane.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wrudy/Desktop/minirt3/scene/scene_objects/plane.c -o CMakeFiles/minirt.dir/scene/scene_objects/plane.c.s

CMakeFiles/minirt.dir/scene/scene_objects/square.c.o: CMakeFiles/minirt.dir/flags.make
CMakeFiles/minirt.dir/scene/scene_objects/square.c.o: ../scene/scene_objects/square.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wrudy/Desktop/minirt3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building C object CMakeFiles/minirt.dir/scene/scene_objects/square.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minirt.dir/scene/scene_objects/square.c.o   -c /Users/wrudy/Desktop/minirt3/scene/scene_objects/square.c

CMakeFiles/minirt.dir/scene/scene_objects/square.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minirt.dir/scene/scene_objects/square.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wrudy/Desktop/minirt3/scene/scene_objects/square.c > CMakeFiles/minirt.dir/scene/scene_objects/square.c.i

CMakeFiles/minirt.dir/scene/scene_objects/square.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minirt.dir/scene/scene_objects/square.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wrudy/Desktop/minirt3/scene/scene_objects/square.c -o CMakeFiles/minirt.dir/scene/scene_objects/square.c.s

CMakeFiles/minirt.dir/scene/scene_objects/cylinder.c.o: CMakeFiles/minirt.dir/flags.make
CMakeFiles/minirt.dir/scene/scene_objects/cylinder.c.o: ../scene/scene_objects/cylinder.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wrudy/Desktop/minirt3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building C object CMakeFiles/minirt.dir/scene/scene_objects/cylinder.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minirt.dir/scene/scene_objects/cylinder.c.o   -c /Users/wrudy/Desktop/minirt3/scene/scene_objects/cylinder.c

CMakeFiles/minirt.dir/scene/scene_objects/cylinder.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minirt.dir/scene/scene_objects/cylinder.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wrudy/Desktop/minirt3/scene/scene_objects/cylinder.c > CMakeFiles/minirt.dir/scene/scene_objects/cylinder.c.i

CMakeFiles/minirt.dir/scene/scene_objects/cylinder.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minirt.dir/scene/scene_objects/cylinder.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wrudy/Desktop/minirt3/scene/scene_objects/cylinder.c -o CMakeFiles/minirt.dir/scene/scene_objects/cylinder.c.s

CMakeFiles/minirt.dir/scene/scene_objects/triangle.c.o: CMakeFiles/minirt.dir/flags.make
CMakeFiles/minirt.dir/scene/scene_objects/triangle.c.o: ../scene/scene_objects/triangle.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wrudy/Desktop/minirt3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building C object CMakeFiles/minirt.dir/scene/scene_objects/triangle.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/minirt.dir/scene/scene_objects/triangle.c.o   -c /Users/wrudy/Desktop/minirt3/scene/scene_objects/triangle.c

CMakeFiles/minirt.dir/scene/scene_objects/triangle.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/minirt.dir/scene/scene_objects/triangle.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/wrudy/Desktop/minirt3/scene/scene_objects/triangle.c > CMakeFiles/minirt.dir/scene/scene_objects/triangle.c.i

CMakeFiles/minirt.dir/scene/scene_objects/triangle.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/minirt.dir/scene/scene_objects/triangle.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/wrudy/Desktop/minirt3/scene/scene_objects/triangle.c -o CMakeFiles/minirt.dir/scene/scene_objects/triangle.c.s

# Object files for target minirt
minirt_OBJECTS = \
"CMakeFiles/minirt.dir/main.c.o" \
"CMakeFiles/minirt.dir/linalg/vecalg.c.o" \
"CMakeFiles/minirt.dir/canvas/color.c.o" \
"CMakeFiles/minirt.dir/canvas/canvas.c.o" \
"CMakeFiles/minirt.dir/scene/light.c.o" \
"CMakeFiles/minirt.dir/scene/camera.c.o" \
"CMakeFiles/minirt.dir/scene/scene.c.o" \
"CMakeFiles/minirt.dir/scene/scene_objects/sphere.c.o" \
"CMakeFiles/minirt.dir/render.c.o" \
"CMakeFiles/minirt.dir/raytrace/raytrace.c.o" \
"CMakeFiles/minirt.dir/scene/scene_objects/object.c.o" \
"CMakeFiles/minirt.dir/raytrace/ray.c.o" \
"CMakeFiles/minirt.dir/raytrace/intersection.c.o" \
"CMakeFiles/minirt.dir/scene/scene_objects/plane.c.o" \
"CMakeFiles/minirt.dir/scene/scene_objects/square.c.o" \
"CMakeFiles/minirt.dir/scene/scene_objects/cylinder.c.o" \
"CMakeFiles/minirt.dir/scene/scene_objects/triangle.c.o"

# External object files for target minirt
minirt_EXTERNAL_OBJECTS =

minirt: CMakeFiles/minirt.dir/main.c.o
minirt: CMakeFiles/minirt.dir/linalg/vecalg.c.o
minirt: CMakeFiles/minirt.dir/canvas/color.c.o
minirt: CMakeFiles/minirt.dir/canvas/canvas.c.o
minirt: CMakeFiles/minirt.dir/scene/light.c.o
minirt: CMakeFiles/minirt.dir/scene/camera.c.o
minirt: CMakeFiles/minirt.dir/scene/scene.c.o
minirt: CMakeFiles/minirt.dir/scene/scene_objects/sphere.c.o
minirt: CMakeFiles/minirt.dir/render.c.o
minirt: CMakeFiles/minirt.dir/raytrace/raytrace.c.o
minirt: CMakeFiles/minirt.dir/scene/scene_objects/object.c.o
minirt: CMakeFiles/minirt.dir/raytrace/ray.c.o
minirt: CMakeFiles/minirt.dir/raytrace/intersection.c.o
minirt: CMakeFiles/minirt.dir/scene/scene_objects/plane.c.o
minirt: CMakeFiles/minirt.dir/scene/scene_objects/square.c.o
minirt: CMakeFiles/minirt.dir/scene/scene_objects/cylinder.c.o
minirt: CMakeFiles/minirt.dir/scene/scene_objects/triangle.c.o
minirt: CMakeFiles/minirt.dir/build.make
minirt: ../mlx/libmlx.a
minirt: CMakeFiles/minirt.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wrudy/Desktop/minirt3/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking C executable minirt"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/minirt.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/minirt.dir/build: minirt

.PHONY : CMakeFiles/minirt.dir/build

CMakeFiles/minirt.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/minirt.dir/cmake_clean.cmake
.PHONY : CMakeFiles/minirt.dir/clean

CMakeFiles/minirt.dir/depend:
	cd /Users/wrudy/Desktop/minirt3/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wrudy/Desktop/minirt3 /Users/wrudy/Desktop/minirt3 /Users/wrudy/Desktop/minirt3/cmake-build-debug /Users/wrudy/Desktop/minirt3/cmake-build-debug /Users/wrudy/Desktop/minirt3/cmake-build-debug/CMakeFiles/minirt.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/minirt.dir/depend

