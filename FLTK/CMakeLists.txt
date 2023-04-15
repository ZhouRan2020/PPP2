cmake_minimum_required(VERSION 3.0)
project(fltk_demo)
#-----------------------------------------------
set(CLANG_DEFAULT_CXX_STDLIB libc++)
ADD_EXECUTABLE(main
	${CMAKE_SOURCE_DIR}/src/main.cpp
)
TARGET_LINK_LIBRARIES(main
	-L${CMAKE_SOURCE_DIR}/lib
)
TARGET_LINK_LIBRARIES(main
	-lfltk
	-lfltk_forms
	-lfltk_gl
	-lfltk_images
)
target_include_directories(main
	PUBLIC
	${CMAKE_SOURCE_DIR}/include
)

