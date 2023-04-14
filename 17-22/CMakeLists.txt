cmake_minimum_required(VERSION 3.23)
set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
project(gcodes VERSION 23.4.6 LANGUAGES C CXX)
### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory. Feel free to remove CMakeCache.txt and CMakeFiles.")
endif()

add_subdirectory(Graph_lib)
#file(GLOB all_sources ${CMAKE_SOURCE_DIR}/interface-lib/src/fltk/*.cpp)
#link_directories(${CMAKE_SOURCE_DIR}/Graph_lib/lib32)
add_executable(rrrrrr 
	${CMAKE_SOURCE_DIR}/src/rrrrrr.cpp
	#${all_sources}	
)
#target_link_libraries(rrrrrr
#	-L${CMAKE_SOURCE_DIR}/Graph_lib/lib
#)
target_link_libraries(rrrrrr
	Graph_lib 
	#fltkd
	#fltkformsd
	#fltkgld
	#fltkimagesd
	#fltkjpegd
	#fltkpngd
	#fltkzd
)
target_include_directories(rrrrrr
PUBLIC ${CMAKE_SOURCE_DIR}/Graph_lib/include
	#${CMAKE_SOURCE_DIR}/Graph_lib/fltk-dist-1.3.8/include	
)

add_executable(test
	${CMAKE_SOURCE_DIR}/src/test.cpp
	#${all_sources}	
)
