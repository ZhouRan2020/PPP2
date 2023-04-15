#cmake_minimum_required(VERSION 3.23.1)
#project(Graph_lib)

add_library(Graph_lib
	SHARED
	${CMAKE_CURRENT_SOURCE_DIR}/src/Graph.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/GUI.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Window.cpp
)
target_link_libraries(Graph_lib
	PUBLIC -L${CMAKE_SOURCE_DIR}/fltk/lib
)
target_link_libraries(Graph_lib
	PUBLIC fltk
	PUBLIC fltk_forms
	PUBLIC fltk_gl
	PUBLIC fltk_images
	#fltk_jpegd
	#fltk_pngd
	#fltk_zd
)
target_include_directories(Graph_lib
	PUBLIC ${CMAKE_SOURCE_DIR}/fltk/include
	#PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/include
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
	#PUBLIC ${CMAKE_SOURCE_DIR}/fltk-dist-1.3.8/include
)
#target_include_directories(Graph_lib
	#PUBLIC ${CMAKE_SOURCE_DIR}/tpl-fltk/include

#)