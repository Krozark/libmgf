#EXEMPLE
if(BUILD_EXAMPLES)
    add_executable(basic basic.cpp)
	target_link_libraries(basic ${CMAKE_PROJECT_NAME})
endif()

