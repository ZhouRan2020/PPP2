cmake_minimum_required(VERSION 3.26)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_C_COMPILER "clang")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -stdlib=libc++")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build)
project(gcodes VERSION 04.15.23 LANGUAGES CXX C)
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
#file(GLOB all_sources ${CMAKE_SOURCE_DIR}/interface-lib/src/fltk/*.cpp)
#link_directories(${CMAKE_SOURCE_DIR}/Graph_lib/lib32)
add_executable(testall 
	${CMAKE_SOURCE_DIR}/src/testall.cpp
	#${all_sources}	
)
#target_link_libraries(rrrrrr
#	-L${CMAKE_SOURCE_DIR}/Graph_lib/lib
#)
target_link_libraries(testall
	Graph_lib 
	#fltkd
	#fltkformsd
	#fltkgld
	#fltkimagesd
	#fltkjpegd
	#fltkpngd
	#fltkzd
)
target_include_directories(testall
	PUBLIC ${CMAKE_SOURCE_DIR}/Graph_lib/include
	#${CMAKE_SOURCE_DIR}/Graph_lib/fltk-dist-1.3.8/include	
)

add_executable(gui
	${CMAKE_SOURCE_DIR}/src/gui.cpp
	#${all_sources}	
)
#target_link_libraries(rrrrrr
#	-L${CMAKE_SOURCE_DIR}/Graph_lib/lib
#)
target_link_libraries(gui
	Graph_lib 
	#fltkd
	#fltkformsd
	#fltkgld
	#fltkimagesd
	#fltkjpegd
	#fltkpngd
	#fltkzd
)
target_include_directories(gui
	PUBLIC ${CMAKE_SOURCE_DIR}/Graph_lib/include
	#${CMAKE_SOURCE_DIR}/Graph_lib/fltk-dist-1.3.8/include	
)

add_executable(function
	${CMAKE_SOURCE_DIR}/src/function.cpp
	#${all_sources}	
)
#target_link_libraries(rrrrrr
#	-L${CMAKE_SOURCE_DIR}/Graph_lib/lib
#)
target_link_libraries(function
	Graph_lib 
	#fltkd
	#fltkformsd
	#fltkgld
	#fltkimagesd
	#fltkjpegd
	#fltkpngd
	#fltkzd
)
target_include_directories(function
	PUBLIC ${CMAKE_SOURCE_DIR}/Graph_lib/include
	#${CMAKE_SOURCE_DIR}/Graph_lib/fltk-dist-1.3.8/include	
)
add_executable(exp
	${CMAKE_SOURCE_DIR}/src/exp.cpp
	#${all_sources}	
)
#target_link_libraries(rrrrrr
#	-L${CMAKE_SOURCE_DIR}/Graph_lib/lib
#)
target_link_libraries(exp
	Graph_lib 
	#fltkd
	#fltkformsd
	#fltkgld
	#fltkimagesd
	#fltkjpegd
	#fltkpngd
	#fltkzd
)
target_include_directories(exp
	PUBLIC ${CMAKE_SOURCE_DIR}/Graph_lib/include
	#${CMAKE_SOURCE_DIR}/Graph_lib/fltk-dist-1.3.8/include	
)