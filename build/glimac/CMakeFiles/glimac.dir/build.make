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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/marion/Documents/KartAndFurious

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marion/Documents/KartAndFurious/build

# Include any dependencies generated for this target.
include glimac/CMakeFiles/glimac.dir/depend.make

# Include the progress variables for this target.
include glimac/CMakeFiles/glimac.dir/progress.make

# Include the compile flags for this target's objects.
include glimac/CMakeFiles/glimac.dir/flags.make

glimac/CMakeFiles/glimac.dir/src/VAO.cpp.o: glimac/CMakeFiles/glimac.dir/flags.make
glimac/CMakeFiles/glimac.dir/src/VAO.cpp.o: ../glimac/src/VAO.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/marion/Documents/KartAndFurious/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object glimac/CMakeFiles/glimac.dir/src/VAO.cpp.o"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/glimac.dir/src/VAO.cpp.o -c /home/marion/Documents/KartAndFurious/glimac/src/VAO.cpp

glimac/CMakeFiles/glimac.dir/src/VAO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glimac.dir/src/VAO.cpp.i"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/marion/Documents/KartAndFurious/glimac/src/VAO.cpp > CMakeFiles/glimac.dir/src/VAO.cpp.i

glimac/CMakeFiles/glimac.dir/src/VAO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glimac.dir/src/VAO.cpp.s"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/marion/Documents/KartAndFurious/glimac/src/VAO.cpp -o CMakeFiles/glimac.dir/src/VAO.cpp.s

glimac/CMakeFiles/glimac.dir/src/VAO.cpp.o.requires:
.PHONY : glimac/CMakeFiles/glimac.dir/src/VAO.cpp.o.requires

glimac/CMakeFiles/glimac.dir/src/VAO.cpp.o.provides: glimac/CMakeFiles/glimac.dir/src/VAO.cpp.o.requires
	$(MAKE) -f glimac/CMakeFiles/glimac.dir/build.make glimac/CMakeFiles/glimac.dir/src/VAO.cpp.o.provides.build
.PHONY : glimac/CMakeFiles/glimac.dir/src/VAO.cpp.o.provides

glimac/CMakeFiles/glimac.dir/src/VAO.cpp.o.provides.build: glimac/CMakeFiles/glimac.dir/src/VAO.cpp.o

glimac/CMakeFiles/glimac.dir/src/Program.cpp.o: glimac/CMakeFiles/glimac.dir/flags.make
glimac/CMakeFiles/glimac.dir/src/Program.cpp.o: ../glimac/src/Program.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/marion/Documents/KartAndFurious/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object glimac/CMakeFiles/glimac.dir/src/Program.cpp.o"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/glimac.dir/src/Program.cpp.o -c /home/marion/Documents/KartAndFurious/glimac/src/Program.cpp

glimac/CMakeFiles/glimac.dir/src/Program.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glimac.dir/src/Program.cpp.i"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/marion/Documents/KartAndFurious/glimac/src/Program.cpp > CMakeFiles/glimac.dir/src/Program.cpp.i

glimac/CMakeFiles/glimac.dir/src/Program.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glimac.dir/src/Program.cpp.s"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/marion/Documents/KartAndFurious/glimac/src/Program.cpp -o CMakeFiles/glimac.dir/src/Program.cpp.s

glimac/CMakeFiles/glimac.dir/src/Program.cpp.o.requires:
.PHONY : glimac/CMakeFiles/glimac.dir/src/Program.cpp.o.requires

glimac/CMakeFiles/glimac.dir/src/Program.cpp.o.provides: glimac/CMakeFiles/glimac.dir/src/Program.cpp.o.requires
	$(MAKE) -f glimac/CMakeFiles/glimac.dir/build.make glimac/CMakeFiles/glimac.dir/src/Program.cpp.o.provides.build
.PHONY : glimac/CMakeFiles/glimac.dir/src/Program.cpp.o.provides

glimac/CMakeFiles/glimac.dir/src/Program.cpp.o.provides.build: glimac/CMakeFiles/glimac.dir/src/Program.cpp.o

glimac/CMakeFiles/glimac.dir/src/Point3D.cpp.o: glimac/CMakeFiles/glimac.dir/flags.make
glimac/CMakeFiles/glimac.dir/src/Point3D.cpp.o: ../glimac/src/Point3D.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/marion/Documents/KartAndFurious/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object glimac/CMakeFiles/glimac.dir/src/Point3D.cpp.o"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/glimac.dir/src/Point3D.cpp.o -c /home/marion/Documents/KartAndFurious/glimac/src/Point3D.cpp

glimac/CMakeFiles/glimac.dir/src/Point3D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glimac.dir/src/Point3D.cpp.i"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/marion/Documents/KartAndFurious/glimac/src/Point3D.cpp > CMakeFiles/glimac.dir/src/Point3D.cpp.i

glimac/CMakeFiles/glimac.dir/src/Point3D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glimac.dir/src/Point3D.cpp.s"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/marion/Documents/KartAndFurious/glimac/src/Point3D.cpp -o CMakeFiles/glimac.dir/src/Point3D.cpp.s

glimac/CMakeFiles/glimac.dir/src/Point3D.cpp.o.requires:
.PHONY : glimac/CMakeFiles/glimac.dir/src/Point3D.cpp.o.requires

glimac/CMakeFiles/glimac.dir/src/Point3D.cpp.o.provides: glimac/CMakeFiles/glimac.dir/src/Point3D.cpp.o.requires
	$(MAKE) -f glimac/CMakeFiles/glimac.dir/build.make glimac/CMakeFiles/glimac.dir/src/Point3D.cpp.o.provides.build
.PHONY : glimac/CMakeFiles/glimac.dir/src/Point3D.cpp.o.provides

glimac/CMakeFiles/glimac.dir/src/Point3D.cpp.o.provides.build: glimac/CMakeFiles/glimac.dir/src/Point3D.cpp.o

glimac/CMakeFiles/glimac.dir/src/Shader.cpp.o: glimac/CMakeFiles/glimac.dir/flags.make
glimac/CMakeFiles/glimac.dir/src/Shader.cpp.o: ../glimac/src/Shader.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/marion/Documents/KartAndFurious/build/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object glimac/CMakeFiles/glimac.dir/src/Shader.cpp.o"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/glimac.dir/src/Shader.cpp.o -c /home/marion/Documents/KartAndFurious/glimac/src/Shader.cpp

glimac/CMakeFiles/glimac.dir/src/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glimac.dir/src/Shader.cpp.i"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/marion/Documents/KartAndFurious/glimac/src/Shader.cpp > CMakeFiles/glimac.dir/src/Shader.cpp.i

glimac/CMakeFiles/glimac.dir/src/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glimac.dir/src/Shader.cpp.s"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/marion/Documents/KartAndFurious/glimac/src/Shader.cpp -o CMakeFiles/glimac.dir/src/Shader.cpp.s

glimac/CMakeFiles/glimac.dir/src/Shader.cpp.o.requires:
.PHONY : glimac/CMakeFiles/glimac.dir/src/Shader.cpp.o.requires

glimac/CMakeFiles/glimac.dir/src/Shader.cpp.o.provides: glimac/CMakeFiles/glimac.dir/src/Shader.cpp.o.requires
	$(MAKE) -f glimac/CMakeFiles/glimac.dir/build.make glimac/CMakeFiles/glimac.dir/src/Shader.cpp.o.provides.build
.PHONY : glimac/CMakeFiles/glimac.dir/src/Shader.cpp.o.provides

glimac/CMakeFiles/glimac.dir/src/Shader.cpp.o.provides.build: glimac/CMakeFiles/glimac.dir/src/Shader.cpp.o

glimac/CMakeFiles/glimac.dir/src/laurentProgram.cpp.o: glimac/CMakeFiles/glimac.dir/flags.make
glimac/CMakeFiles/glimac.dir/src/laurentProgram.cpp.o: ../glimac/src/laurentProgram.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/marion/Documents/KartAndFurious/build/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object glimac/CMakeFiles/glimac.dir/src/laurentProgram.cpp.o"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/glimac.dir/src/laurentProgram.cpp.o -c /home/marion/Documents/KartAndFurious/glimac/src/laurentProgram.cpp

glimac/CMakeFiles/glimac.dir/src/laurentProgram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glimac.dir/src/laurentProgram.cpp.i"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/marion/Documents/KartAndFurious/glimac/src/laurentProgram.cpp > CMakeFiles/glimac.dir/src/laurentProgram.cpp.i

glimac/CMakeFiles/glimac.dir/src/laurentProgram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glimac.dir/src/laurentProgram.cpp.s"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/marion/Documents/KartAndFurious/glimac/src/laurentProgram.cpp -o CMakeFiles/glimac.dir/src/laurentProgram.cpp.s

glimac/CMakeFiles/glimac.dir/src/laurentProgram.cpp.o.requires:
.PHONY : glimac/CMakeFiles/glimac.dir/src/laurentProgram.cpp.o.requires

glimac/CMakeFiles/glimac.dir/src/laurentProgram.cpp.o.provides: glimac/CMakeFiles/glimac.dir/src/laurentProgram.cpp.o.requires
	$(MAKE) -f glimac/CMakeFiles/glimac.dir/build.make glimac/CMakeFiles/glimac.dir/src/laurentProgram.cpp.o.provides.build
.PHONY : glimac/CMakeFiles/glimac.dir/src/laurentProgram.cpp.o.provides

glimac/CMakeFiles/glimac.dir/src/laurentProgram.cpp.o.provides.build: glimac/CMakeFiles/glimac.dir/src/laurentProgram.cpp.o

glimac/CMakeFiles/glimac.dir/src/OpenGLDebugger.cpp.o: glimac/CMakeFiles/glimac.dir/flags.make
glimac/CMakeFiles/glimac.dir/src/OpenGLDebugger.cpp.o: ../glimac/src/OpenGLDebugger.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/marion/Documents/KartAndFurious/build/CMakeFiles $(CMAKE_PROGRESS_6)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object glimac/CMakeFiles/glimac.dir/src/OpenGLDebugger.cpp.o"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/glimac.dir/src/OpenGLDebugger.cpp.o -c /home/marion/Documents/KartAndFurious/glimac/src/OpenGLDebugger.cpp

glimac/CMakeFiles/glimac.dir/src/OpenGLDebugger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glimac.dir/src/OpenGLDebugger.cpp.i"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/marion/Documents/KartAndFurious/glimac/src/OpenGLDebugger.cpp > CMakeFiles/glimac.dir/src/OpenGLDebugger.cpp.i

glimac/CMakeFiles/glimac.dir/src/OpenGLDebugger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glimac.dir/src/OpenGLDebugger.cpp.s"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/marion/Documents/KartAndFurious/glimac/src/OpenGLDebugger.cpp -o CMakeFiles/glimac.dir/src/OpenGLDebugger.cpp.s

glimac/CMakeFiles/glimac.dir/src/OpenGLDebugger.cpp.o.requires:
.PHONY : glimac/CMakeFiles/glimac.dir/src/OpenGLDebugger.cpp.o.requires

glimac/CMakeFiles/glimac.dir/src/OpenGLDebugger.cpp.o.provides: glimac/CMakeFiles/glimac.dir/src/OpenGLDebugger.cpp.o.requires
	$(MAKE) -f glimac/CMakeFiles/glimac.dir/build.make glimac/CMakeFiles/glimac.dir/src/OpenGLDebugger.cpp.o.provides.build
.PHONY : glimac/CMakeFiles/glimac.dir/src/OpenGLDebugger.cpp.o.provides

glimac/CMakeFiles/glimac.dir/src/OpenGLDebugger.cpp.o.provides.build: glimac/CMakeFiles/glimac.dir/src/OpenGLDebugger.cpp.o

glimac/CMakeFiles/glimac.dir/src/TextFile.cpp.o: glimac/CMakeFiles/glimac.dir/flags.make
glimac/CMakeFiles/glimac.dir/src/TextFile.cpp.o: ../glimac/src/TextFile.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/marion/Documents/KartAndFurious/build/CMakeFiles $(CMAKE_PROGRESS_7)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object glimac/CMakeFiles/glimac.dir/src/TextFile.cpp.o"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/glimac.dir/src/TextFile.cpp.o -c /home/marion/Documents/KartAndFurious/glimac/src/TextFile.cpp

glimac/CMakeFiles/glimac.dir/src/TextFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glimac.dir/src/TextFile.cpp.i"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/marion/Documents/KartAndFurious/glimac/src/TextFile.cpp > CMakeFiles/glimac.dir/src/TextFile.cpp.i

glimac/CMakeFiles/glimac.dir/src/TextFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glimac.dir/src/TextFile.cpp.s"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/marion/Documents/KartAndFurious/glimac/src/TextFile.cpp -o CMakeFiles/glimac.dir/src/TextFile.cpp.s

glimac/CMakeFiles/glimac.dir/src/TextFile.cpp.o.requires:
.PHONY : glimac/CMakeFiles/glimac.dir/src/TextFile.cpp.o.requires

glimac/CMakeFiles/glimac.dir/src/TextFile.cpp.o.provides: glimac/CMakeFiles/glimac.dir/src/TextFile.cpp.o.requires
	$(MAKE) -f glimac/CMakeFiles/glimac.dir/build.make glimac/CMakeFiles/glimac.dir/src/TextFile.cpp.o.provides.build
.PHONY : glimac/CMakeFiles/glimac.dir/src/TextFile.cpp.o.provides

glimac/CMakeFiles/glimac.dir/src/TextFile.cpp.o.provides.build: glimac/CMakeFiles/glimac.dir/src/TextFile.cpp.o

glimac/CMakeFiles/glimac.dir/src/Matrix2D.cpp.o: glimac/CMakeFiles/glimac.dir/flags.make
glimac/CMakeFiles/glimac.dir/src/Matrix2D.cpp.o: ../glimac/src/Matrix2D.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/marion/Documents/KartAndFurious/build/CMakeFiles $(CMAKE_PROGRESS_8)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object glimac/CMakeFiles/glimac.dir/src/Matrix2D.cpp.o"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/glimac.dir/src/Matrix2D.cpp.o -c /home/marion/Documents/KartAndFurious/glimac/src/Matrix2D.cpp

glimac/CMakeFiles/glimac.dir/src/Matrix2D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glimac.dir/src/Matrix2D.cpp.i"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/marion/Documents/KartAndFurious/glimac/src/Matrix2D.cpp > CMakeFiles/glimac.dir/src/Matrix2D.cpp.i

glimac/CMakeFiles/glimac.dir/src/Matrix2D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glimac.dir/src/Matrix2D.cpp.s"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/marion/Documents/KartAndFurious/glimac/src/Matrix2D.cpp -o CMakeFiles/glimac.dir/src/Matrix2D.cpp.s

glimac/CMakeFiles/glimac.dir/src/Matrix2D.cpp.o.requires:
.PHONY : glimac/CMakeFiles/glimac.dir/src/Matrix2D.cpp.o.requires

glimac/CMakeFiles/glimac.dir/src/Matrix2D.cpp.o.provides: glimac/CMakeFiles/glimac.dir/src/Matrix2D.cpp.o.requires
	$(MAKE) -f glimac/CMakeFiles/glimac.dir/build.make glimac/CMakeFiles/glimac.dir/src/Matrix2D.cpp.o.provides.build
.PHONY : glimac/CMakeFiles/glimac.dir/src/Matrix2D.cpp.o.provides

glimac/CMakeFiles/glimac.dir/src/Matrix2D.cpp.o.provides.build: glimac/CMakeFiles/glimac.dir/src/Matrix2D.cpp.o

glimac/CMakeFiles/glimac.dir/src/oldShader.cpp.o: glimac/CMakeFiles/glimac.dir/flags.make
glimac/CMakeFiles/glimac.dir/src/oldShader.cpp.o: ../glimac/src/oldShader.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/marion/Documents/KartAndFurious/build/CMakeFiles $(CMAKE_PROGRESS_9)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object glimac/CMakeFiles/glimac.dir/src/oldShader.cpp.o"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/glimac.dir/src/oldShader.cpp.o -c /home/marion/Documents/KartAndFurious/glimac/src/oldShader.cpp

glimac/CMakeFiles/glimac.dir/src/oldShader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glimac.dir/src/oldShader.cpp.i"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/marion/Documents/KartAndFurious/glimac/src/oldShader.cpp > CMakeFiles/glimac.dir/src/oldShader.cpp.i

glimac/CMakeFiles/glimac.dir/src/oldShader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glimac.dir/src/oldShader.cpp.s"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/marion/Documents/KartAndFurious/glimac/src/oldShader.cpp -o CMakeFiles/glimac.dir/src/oldShader.cpp.s

glimac/CMakeFiles/glimac.dir/src/oldShader.cpp.o.requires:
.PHONY : glimac/CMakeFiles/glimac.dir/src/oldShader.cpp.o.requires

glimac/CMakeFiles/glimac.dir/src/oldShader.cpp.o.provides: glimac/CMakeFiles/glimac.dir/src/oldShader.cpp.o.requires
	$(MAKE) -f glimac/CMakeFiles/glimac.dir/build.make glimac/CMakeFiles/glimac.dir/src/oldShader.cpp.o.provides.build
.PHONY : glimac/CMakeFiles/glimac.dir/src/oldShader.cpp.o.provides

glimac/CMakeFiles/glimac.dir/src/oldShader.cpp.o.provides.build: glimac/CMakeFiles/glimac.dir/src/oldShader.cpp.o

glimac/CMakeFiles/glimac.dir/src/Texture.cpp.o: glimac/CMakeFiles/glimac.dir/flags.make
glimac/CMakeFiles/glimac.dir/src/Texture.cpp.o: ../glimac/src/Texture.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/marion/Documents/KartAndFurious/build/CMakeFiles $(CMAKE_PROGRESS_10)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object glimac/CMakeFiles/glimac.dir/src/Texture.cpp.o"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/glimac.dir/src/Texture.cpp.o -c /home/marion/Documents/KartAndFurious/glimac/src/Texture.cpp

glimac/CMakeFiles/glimac.dir/src/Texture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glimac.dir/src/Texture.cpp.i"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/marion/Documents/KartAndFurious/glimac/src/Texture.cpp > CMakeFiles/glimac.dir/src/Texture.cpp.i

glimac/CMakeFiles/glimac.dir/src/Texture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glimac.dir/src/Texture.cpp.s"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/marion/Documents/KartAndFurious/glimac/src/Texture.cpp -o CMakeFiles/glimac.dir/src/Texture.cpp.s

glimac/CMakeFiles/glimac.dir/src/Texture.cpp.o.requires:
.PHONY : glimac/CMakeFiles/glimac.dir/src/Texture.cpp.o.requires

glimac/CMakeFiles/glimac.dir/src/Texture.cpp.o.provides: glimac/CMakeFiles/glimac.dir/src/Texture.cpp.o.requires
	$(MAKE) -f glimac/CMakeFiles/glimac.dir/build.make glimac/CMakeFiles/glimac.dir/src/Texture.cpp.o.provides.build
.PHONY : glimac/CMakeFiles/glimac.dir/src/Texture.cpp.o.provides

glimac/CMakeFiles/glimac.dir/src/Texture.cpp.o.provides.build: glimac/CMakeFiles/glimac.dir/src/Texture.cpp.o

glimac/CMakeFiles/glimac.dir/src/ShaderProgram.cpp.o: glimac/CMakeFiles/glimac.dir/flags.make
glimac/CMakeFiles/glimac.dir/src/ShaderProgram.cpp.o: ../glimac/src/ShaderProgram.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/marion/Documents/KartAndFurious/build/CMakeFiles $(CMAKE_PROGRESS_11)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object glimac/CMakeFiles/glimac.dir/src/ShaderProgram.cpp.o"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/glimac.dir/src/ShaderProgram.cpp.o -c /home/marion/Documents/KartAndFurious/glimac/src/ShaderProgram.cpp

glimac/CMakeFiles/glimac.dir/src/ShaderProgram.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glimac.dir/src/ShaderProgram.cpp.i"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/marion/Documents/KartAndFurious/glimac/src/ShaderProgram.cpp > CMakeFiles/glimac.dir/src/ShaderProgram.cpp.i

glimac/CMakeFiles/glimac.dir/src/ShaderProgram.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glimac.dir/src/ShaderProgram.cpp.s"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/marion/Documents/KartAndFurious/glimac/src/ShaderProgram.cpp -o CMakeFiles/glimac.dir/src/ShaderProgram.cpp.s

glimac/CMakeFiles/glimac.dir/src/ShaderProgram.cpp.o.requires:
.PHONY : glimac/CMakeFiles/glimac.dir/src/ShaderProgram.cpp.o.requires

glimac/CMakeFiles/glimac.dir/src/ShaderProgram.cpp.o.provides: glimac/CMakeFiles/glimac.dir/src/ShaderProgram.cpp.o.requires
	$(MAKE) -f glimac/CMakeFiles/glimac.dir/build.make glimac/CMakeFiles/glimac.dir/src/ShaderProgram.cpp.o.provides.build
.PHONY : glimac/CMakeFiles/glimac.dir/src/ShaderProgram.cpp.o.provides

glimac/CMakeFiles/glimac.dir/src/ShaderProgram.cpp.o.provides.build: glimac/CMakeFiles/glimac.dir/src/ShaderProgram.cpp.o

glimac/CMakeFiles/glimac.dir/src/ShaderTexture.cpp.o: glimac/CMakeFiles/glimac.dir/flags.make
glimac/CMakeFiles/glimac.dir/src/ShaderTexture.cpp.o: ../glimac/src/ShaderTexture.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/marion/Documents/KartAndFurious/build/CMakeFiles $(CMAKE_PROGRESS_12)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object glimac/CMakeFiles/glimac.dir/src/ShaderTexture.cpp.o"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/glimac.dir/src/ShaderTexture.cpp.o -c /home/marion/Documents/KartAndFurious/glimac/src/ShaderTexture.cpp

glimac/CMakeFiles/glimac.dir/src/ShaderTexture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glimac.dir/src/ShaderTexture.cpp.i"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/marion/Documents/KartAndFurious/glimac/src/ShaderTexture.cpp > CMakeFiles/glimac.dir/src/ShaderTexture.cpp.i

glimac/CMakeFiles/glimac.dir/src/ShaderTexture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glimac.dir/src/ShaderTexture.cpp.s"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/marion/Documents/KartAndFurious/glimac/src/ShaderTexture.cpp -o CMakeFiles/glimac.dir/src/ShaderTexture.cpp.s

glimac/CMakeFiles/glimac.dir/src/ShaderTexture.cpp.o.requires:
.PHONY : glimac/CMakeFiles/glimac.dir/src/ShaderTexture.cpp.o.requires

glimac/CMakeFiles/glimac.dir/src/ShaderTexture.cpp.o.provides: glimac/CMakeFiles/glimac.dir/src/ShaderTexture.cpp.o.requires
	$(MAKE) -f glimac/CMakeFiles/glimac.dir/build.make glimac/CMakeFiles/glimac.dir/src/ShaderTexture.cpp.o.provides.build
.PHONY : glimac/CMakeFiles/glimac.dir/src/ShaderTexture.cpp.o.provides

glimac/CMakeFiles/glimac.dir/src/ShaderTexture.cpp.o.provides.build: glimac/CMakeFiles/glimac.dir/src/ShaderTexture.cpp.o

glimac/CMakeFiles/glimac.dir/src/VBO.cpp.o: glimac/CMakeFiles/glimac.dir/flags.make
glimac/CMakeFiles/glimac.dir/src/VBO.cpp.o: ../glimac/src/VBO.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/marion/Documents/KartAndFurious/build/CMakeFiles $(CMAKE_PROGRESS_13)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object glimac/CMakeFiles/glimac.dir/src/VBO.cpp.o"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/glimac.dir/src/VBO.cpp.o -c /home/marion/Documents/KartAndFurious/glimac/src/VBO.cpp

glimac/CMakeFiles/glimac.dir/src/VBO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/glimac.dir/src/VBO.cpp.i"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/marion/Documents/KartAndFurious/glimac/src/VBO.cpp > CMakeFiles/glimac.dir/src/VBO.cpp.i

glimac/CMakeFiles/glimac.dir/src/VBO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/glimac.dir/src/VBO.cpp.s"
	cd /home/marion/Documents/KartAndFurious/build/glimac && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/marion/Documents/KartAndFurious/glimac/src/VBO.cpp -o CMakeFiles/glimac.dir/src/VBO.cpp.s

glimac/CMakeFiles/glimac.dir/src/VBO.cpp.o.requires:
.PHONY : glimac/CMakeFiles/glimac.dir/src/VBO.cpp.o.requires

glimac/CMakeFiles/glimac.dir/src/VBO.cpp.o.provides: glimac/CMakeFiles/glimac.dir/src/VBO.cpp.o.requires
	$(MAKE) -f glimac/CMakeFiles/glimac.dir/build.make glimac/CMakeFiles/glimac.dir/src/VBO.cpp.o.provides.build
.PHONY : glimac/CMakeFiles/glimac.dir/src/VBO.cpp.o.provides

glimac/CMakeFiles/glimac.dir/src/VBO.cpp.o.provides.build: glimac/CMakeFiles/glimac.dir/src/VBO.cpp.o

# Object files for target glimac
glimac_OBJECTS = \
"CMakeFiles/glimac.dir/src/VAO.cpp.o" \
"CMakeFiles/glimac.dir/src/Program.cpp.o" \
"CMakeFiles/glimac.dir/src/Point3D.cpp.o" \
"CMakeFiles/glimac.dir/src/Shader.cpp.o" \
"CMakeFiles/glimac.dir/src/laurentProgram.cpp.o" \
"CMakeFiles/glimac.dir/src/OpenGLDebugger.cpp.o" \
"CMakeFiles/glimac.dir/src/TextFile.cpp.o" \
"CMakeFiles/glimac.dir/src/Matrix2D.cpp.o" \
"CMakeFiles/glimac.dir/src/oldShader.cpp.o" \
"CMakeFiles/glimac.dir/src/Texture.cpp.o" \
"CMakeFiles/glimac.dir/src/ShaderProgram.cpp.o" \
"CMakeFiles/glimac.dir/src/ShaderTexture.cpp.o" \
"CMakeFiles/glimac.dir/src/VBO.cpp.o"

# External object files for target glimac
glimac_EXTERNAL_OBJECTS =

glimac/libglimac.a: glimac/CMakeFiles/glimac.dir/src/VAO.cpp.o
glimac/libglimac.a: glimac/CMakeFiles/glimac.dir/src/Program.cpp.o
glimac/libglimac.a: glimac/CMakeFiles/glimac.dir/src/Point3D.cpp.o
glimac/libglimac.a: glimac/CMakeFiles/glimac.dir/src/Shader.cpp.o
glimac/libglimac.a: glimac/CMakeFiles/glimac.dir/src/laurentProgram.cpp.o
glimac/libglimac.a: glimac/CMakeFiles/glimac.dir/src/OpenGLDebugger.cpp.o
glimac/libglimac.a: glimac/CMakeFiles/glimac.dir/src/TextFile.cpp.o
glimac/libglimac.a: glimac/CMakeFiles/glimac.dir/src/Matrix2D.cpp.o
glimac/libglimac.a: glimac/CMakeFiles/glimac.dir/src/oldShader.cpp.o
glimac/libglimac.a: glimac/CMakeFiles/glimac.dir/src/Texture.cpp.o
glimac/libglimac.a: glimac/CMakeFiles/glimac.dir/src/ShaderProgram.cpp.o
glimac/libglimac.a: glimac/CMakeFiles/glimac.dir/src/ShaderTexture.cpp.o
glimac/libglimac.a: glimac/CMakeFiles/glimac.dir/src/VBO.cpp.o
glimac/libglimac.a: glimac/CMakeFiles/glimac.dir/build.make
glimac/libglimac.a: glimac/CMakeFiles/glimac.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX static library libglimac.a"
	cd /home/marion/Documents/KartAndFurious/build/glimac && $(CMAKE_COMMAND) -P CMakeFiles/glimac.dir/cmake_clean_target.cmake
	cd /home/marion/Documents/KartAndFurious/build/glimac && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/glimac.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glimac/CMakeFiles/glimac.dir/build: glimac/libglimac.a
.PHONY : glimac/CMakeFiles/glimac.dir/build

glimac/CMakeFiles/glimac.dir/requires: glimac/CMakeFiles/glimac.dir/src/VAO.cpp.o.requires
glimac/CMakeFiles/glimac.dir/requires: glimac/CMakeFiles/glimac.dir/src/Program.cpp.o.requires
glimac/CMakeFiles/glimac.dir/requires: glimac/CMakeFiles/glimac.dir/src/Point3D.cpp.o.requires
glimac/CMakeFiles/glimac.dir/requires: glimac/CMakeFiles/glimac.dir/src/Shader.cpp.o.requires
glimac/CMakeFiles/glimac.dir/requires: glimac/CMakeFiles/glimac.dir/src/laurentProgram.cpp.o.requires
glimac/CMakeFiles/glimac.dir/requires: glimac/CMakeFiles/glimac.dir/src/OpenGLDebugger.cpp.o.requires
glimac/CMakeFiles/glimac.dir/requires: glimac/CMakeFiles/glimac.dir/src/TextFile.cpp.o.requires
glimac/CMakeFiles/glimac.dir/requires: glimac/CMakeFiles/glimac.dir/src/Matrix2D.cpp.o.requires
glimac/CMakeFiles/glimac.dir/requires: glimac/CMakeFiles/glimac.dir/src/oldShader.cpp.o.requires
glimac/CMakeFiles/glimac.dir/requires: glimac/CMakeFiles/glimac.dir/src/Texture.cpp.o.requires
glimac/CMakeFiles/glimac.dir/requires: glimac/CMakeFiles/glimac.dir/src/ShaderProgram.cpp.o.requires
glimac/CMakeFiles/glimac.dir/requires: glimac/CMakeFiles/glimac.dir/src/ShaderTexture.cpp.o.requires
glimac/CMakeFiles/glimac.dir/requires: glimac/CMakeFiles/glimac.dir/src/VBO.cpp.o.requires
.PHONY : glimac/CMakeFiles/glimac.dir/requires

glimac/CMakeFiles/glimac.dir/clean:
	cd /home/marion/Documents/KartAndFurious/build/glimac && $(CMAKE_COMMAND) -P CMakeFiles/glimac.dir/cmake_clean.cmake
.PHONY : glimac/CMakeFiles/glimac.dir/clean

glimac/CMakeFiles/glimac.dir/depend:
	cd /home/marion/Documents/KartAndFurious/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/marion/Documents/KartAndFurious /home/marion/Documents/KartAndFurious/glimac /home/marion/Documents/KartAndFurious/build /home/marion/Documents/KartAndFurious/build/glimac /home/marion/Documents/KartAndFurious/build/glimac/CMakeFiles/glimac.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : glimac/CMakeFiles/glimac.dir/depend
