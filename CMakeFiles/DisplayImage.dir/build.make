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
CMAKE_SOURCE_DIR = /home/qilei/Desktop/solvePNP

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/qilei/Desktop/solvePNP

# Include any dependencies generated for this target.
include CMakeFiles/DisplayImage.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DisplayImage.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DisplayImage.dir/flags.make

CMakeFiles/DisplayImage.dir/SolvePNPByOpenCV.cpp.o: CMakeFiles/DisplayImage.dir/flags.make
CMakeFiles/DisplayImage.dir/SolvePNPByOpenCV.cpp.o: SolvePNPByOpenCV.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/qilei/Desktop/solvePNP/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DisplayImage.dir/SolvePNPByOpenCV.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DisplayImage.dir/SolvePNPByOpenCV.cpp.o -c /home/qilei/Desktop/solvePNP/SolvePNPByOpenCV.cpp

CMakeFiles/DisplayImage.dir/SolvePNPByOpenCV.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DisplayImage.dir/SolvePNPByOpenCV.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/qilei/Desktop/solvePNP/SolvePNPByOpenCV.cpp > CMakeFiles/DisplayImage.dir/SolvePNPByOpenCV.cpp.i

CMakeFiles/DisplayImage.dir/SolvePNPByOpenCV.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DisplayImage.dir/SolvePNPByOpenCV.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/qilei/Desktop/solvePNP/SolvePNPByOpenCV.cpp -o CMakeFiles/DisplayImage.dir/SolvePNPByOpenCV.cpp.s

CMakeFiles/DisplayImage.dir/SolvePNPByOpenCV.cpp.o.requires:
.PHONY : CMakeFiles/DisplayImage.dir/SolvePNPByOpenCV.cpp.o.requires

CMakeFiles/DisplayImage.dir/SolvePNPByOpenCV.cpp.o.provides: CMakeFiles/DisplayImage.dir/SolvePNPByOpenCV.cpp.o.requires
	$(MAKE) -f CMakeFiles/DisplayImage.dir/build.make CMakeFiles/DisplayImage.dir/SolvePNPByOpenCV.cpp.o.provides.build
.PHONY : CMakeFiles/DisplayImage.dir/SolvePNPByOpenCV.cpp.o.provides

CMakeFiles/DisplayImage.dir/SolvePNPByOpenCV.cpp.o.provides.build: CMakeFiles/DisplayImage.dir/SolvePNPByOpenCV.cpp.o

CMakeFiles/DisplayImage.dir/stdafx.cpp.o: CMakeFiles/DisplayImage.dir/flags.make
CMakeFiles/DisplayImage.dir/stdafx.cpp.o: stdafx.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/qilei/Desktop/solvePNP/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/DisplayImage.dir/stdafx.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/DisplayImage.dir/stdafx.cpp.o -c /home/qilei/Desktop/solvePNP/stdafx.cpp

CMakeFiles/DisplayImage.dir/stdafx.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DisplayImage.dir/stdafx.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/qilei/Desktop/solvePNP/stdafx.cpp > CMakeFiles/DisplayImage.dir/stdafx.cpp.i

CMakeFiles/DisplayImage.dir/stdafx.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DisplayImage.dir/stdafx.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/qilei/Desktop/solvePNP/stdafx.cpp -o CMakeFiles/DisplayImage.dir/stdafx.cpp.s

CMakeFiles/DisplayImage.dir/stdafx.cpp.o.requires:
.PHONY : CMakeFiles/DisplayImage.dir/stdafx.cpp.o.requires

CMakeFiles/DisplayImage.dir/stdafx.cpp.o.provides: CMakeFiles/DisplayImage.dir/stdafx.cpp.o.requires
	$(MAKE) -f CMakeFiles/DisplayImage.dir/build.make CMakeFiles/DisplayImage.dir/stdafx.cpp.o.provides.build
.PHONY : CMakeFiles/DisplayImage.dir/stdafx.cpp.o.provides

CMakeFiles/DisplayImage.dir/stdafx.cpp.o.provides.build: CMakeFiles/DisplayImage.dir/stdafx.cpp.o

# Object files for target DisplayImage
DisplayImage_OBJECTS = \
"CMakeFiles/DisplayImage.dir/SolvePNPByOpenCV.cpp.o" \
"CMakeFiles/DisplayImage.dir/stdafx.cpp.o"

# External object files for target DisplayImage
DisplayImage_EXTERNAL_OBJECTS =

DisplayImage: CMakeFiles/DisplayImage.dir/SolvePNPByOpenCV.cpp.o
DisplayImage: CMakeFiles/DisplayImage.dir/stdafx.cpp.o
DisplayImage: CMakeFiles/DisplayImage.dir/build.make
DisplayImage: /usr/local/lib/libopencv_calib3d.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_core.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_dnn.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_features2d.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_flann.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_highgui.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_imgcodecs.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_imgproc.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_ml.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_objdetect.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_photo.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_shape.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_stitching.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_superres.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_video.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_videoio.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_videostab.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_viz.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_aruco.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_bgsegm.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_bioinspired.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_ccalib.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_datasets.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_dpm.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_face.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_freetype.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_fuzzy.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_hdf.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_img_hash.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_line_descriptor.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_optflow.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_phase_unwrapping.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_plot.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_reg.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_rgbd.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_saliency.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_stereo.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_structured_light.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_surface_matching.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_text.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_tracking.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_xfeatures2d.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_ximgproc.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_xobjdetect.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_xphoto.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_shape.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_photo.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_calib3d.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_viz.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_phase_unwrapping.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_dnn.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_video.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_datasets.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_plot.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_text.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_features2d.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_flann.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_highgui.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_ml.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_videoio.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_imgcodecs.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_objdetect.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_imgproc.so.3.3.0
DisplayImage: /usr/local/lib/libopencv_core.so.3.3.0
DisplayImage: CMakeFiles/DisplayImage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable DisplayImage"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DisplayImage.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DisplayImage.dir/build: DisplayImage
.PHONY : CMakeFiles/DisplayImage.dir/build

CMakeFiles/DisplayImage.dir/requires: CMakeFiles/DisplayImage.dir/SolvePNPByOpenCV.cpp.o.requires
CMakeFiles/DisplayImage.dir/requires: CMakeFiles/DisplayImage.dir/stdafx.cpp.o.requires
.PHONY : CMakeFiles/DisplayImage.dir/requires

CMakeFiles/DisplayImage.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DisplayImage.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DisplayImage.dir/clean

CMakeFiles/DisplayImage.dir/depend:
	cd /home/qilei/Desktop/solvePNP && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/qilei/Desktop/solvePNP /home/qilei/Desktop/solvePNP /home/qilei/Desktop/solvePNP /home/qilei/Desktop/solvePNP /home/qilei/Desktop/solvePNP/CMakeFiles/DisplayImage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DisplayImage.dir/depend

