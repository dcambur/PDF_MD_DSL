# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\dcamb\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\203.7148.70\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\dcamb\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\203.7148.70\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\dcamb\CLionProjects\PDF_MD_DSL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\dcamb\CLionProjects\PDF_MD_DSL\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\PDF_MD_DSL.dir\depend.make

# Include the progress variables for this target.
include CMakeFiles\PDF_MD_DSL.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\PDF_MD_DSL.dir\flags.make

CMakeFiles\PDF_MD_DSL.dir\lex.cpp.obj: CMakeFiles\PDF_MD_DSL.dir\flags.make
CMakeFiles\PDF_MD_DSL.dir\lex.cpp.obj: ..\lex.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\dcamb\CLionProjects\PDF_MD_DSL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PDF_MD_DSL.dir/lex.cpp.obj"
	C:\PROGRA~2\MICROS~3\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoCMakeFiles\PDF_MD_DSL.dir\lex.cpp.obj /FdCMakeFiles\PDF_MD_DSL.dir\ /FS -c C:\Users\dcamb\CLionProjects\PDF_MD_DSL\lex.cpp
<<

CMakeFiles\PDF_MD_DSL.dir\lex.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PDF_MD_DSL.dir/lex.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\PDF_MD_DSL.dir\lex.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\dcamb\CLionProjects\PDF_MD_DSL\lex.cpp
<<

CMakeFiles\PDF_MD_DSL.dir\lex.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PDF_MD_DSL.dir/lex.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\PDF_MD_DSL.dir\lex.cpp.s /c C:\Users\dcamb\CLionProjects\PDF_MD_DSL\lex.cpp
<<

# Object files for target PDF_MD_DSL
PDF_MD_DSL_OBJECTS = \
"CMakeFiles\PDF_MD_DSL.dir\lex.cpp.obj"

# External object files for target PDF_MD_DSL
PDF_MD_DSL_EXTERNAL_OBJECTS =

PDF_MD_DSL.exe: CMakeFiles\PDF_MD_DSL.dir\lex.cpp.obj
PDF_MD_DSL.exe: CMakeFiles\PDF_MD_DSL.dir\build.make
PDF_MD_DSL.exe: CMakeFiles\PDF_MD_DSL.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\dcamb\CLionProjects\PDF_MD_DSL\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PDF_MD_DSL.exe"
	C:\Users\dcamb\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\203.7148.70\bin\cmake\win\bin\cmake.exe -E vs_link_exe --intdir=CMakeFiles\PDF_MD_DSL.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests  -- C:\PROGRA~2\MICROS~3\2019\BUILDT~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\PDF_MD_DSL.dir\objects1.rsp @<<
 /out:PDF_MD_DSL.exe /implib:PDF_MD_DSL.lib /pdb:C:\Users\dcamb\CLionProjects\PDF_MD_DSL\cmake-build-debug\PDF_MD_DSL.pdb /version:0.0  /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\PDF_MD_DSL.dir\build: PDF_MD_DSL.exe

.PHONY : CMakeFiles\PDF_MD_DSL.dir\build

CMakeFiles\PDF_MD_DSL.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\PDF_MD_DSL.dir\cmake_clean.cmake
.PHONY : CMakeFiles\PDF_MD_DSL.dir\clean

CMakeFiles\PDF_MD_DSL.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\dcamb\CLionProjects\PDF_MD_DSL C:\Users\dcamb\CLionProjects\PDF_MD_DSL C:\Users\dcamb\CLionProjects\PDF_MD_DSL\cmake-build-debug C:\Users\dcamb\CLionProjects\PDF_MD_DSL\cmake-build-debug C:\Users\dcamb\CLionProjects\PDF_MD_DSL\cmake-build-debug\CMakeFiles\PDF_MD_DSL.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\PDF_MD_DSL.dir\depend

