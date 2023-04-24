add_library(Graph_lib
	SHARED
	${CMAKE_CURRENT_SOURCE_DIR}/src/Graph.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/GUI.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/Window.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/src/gl_utils.cpp
)
target_link_libraries(Graph_lib
	PUBLIC -L${CMAKE_SOURCE_DIR}/fltk/lib
)
target_link_libraries(Graph_lib
	PUBLIC fltk
	PUBLIC fltk_forms
	PUBLIC fltk_gl
	PUBLIC fltk_images
)
target_include_directories(Graph_lib
	PUBLIC ${CMAKE_SOURCE_DIR}/fltk/include
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)
