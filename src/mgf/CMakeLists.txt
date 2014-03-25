set(INCROOT ${PROJECT_SOURCE_DIR}/include/${CMAKE_PROJECT_NAME})
set(SRCROOT ${PROJECT_SOURCE_DIR}/src/${CMAKE_PROJECT_NAME})

if(UNIX)
	FIND_PACKAGE(BISON REQUIRED)
	SET(BisonOutputSrc ${SRCROOT}/Parser.cpp)
	set(BisonOutputInc ${SRCROOT}/Parser.hpp ${SRCROOT}/location.hh ${SRCROOT}/position.hh ${SRCROOT}/stack.hh)
	IF(BISON_FOUND)
		ADD_CUSTOM_COMMAND(
			OUTPUT ${BisonOutputSrc} ${BisonOutputInc}
		  COMMAND ${BISON_EXECUTABLE}
		  --output=${BisonOutputSrc}
				  ${SRCROOT}/Parser.yy
		  COMMENT "Generating Parser.cpp"
		)
	else()
		message( SEND_ERROR "Bison is required" )
	ENDIF()

	FIND_PACKAGE(FLEX REQUIRED)
	SET(FlexOutputSrc ${SRCROOT}/Lexer.cpp)
	IF(FLEX_FOUND)
		ADD_CUSTOM_COMMAND(
			OUTPUT ${FlexOutputSrc}
		  COMMAND ${FLEX_EXECUTABLE}
		  --outfile=${FlexOutputSrc}
				  ${SRCROOT}/Lexer.lex
				  COMMENT "Generating Lexer.cpp"
		)
	else()
		message( SEND_ERROR "Flex is required" )
	ENDIF()
elseif(WIN32)
    set(FlexOutputSrc ${SRCROOT}/Win/Lexer.cpp)
	set(BisonOutputSrc ${SRCROOT}/Win/Parser.cpp)
	set(BisonOutputInc ${SRCROOT}/Win/Parser.hpp ${SRCROOT}/Win/location.hh ${SRCROOT}/Win/position.hh ${SRCROOT}/Win/stack.hh)
endif()

#ROOT files
set(ROOT_SRC
    ${SRCROOT}/Analyse.cpp
    ${SRCROOT}/Convert.cpp
    ${SRCROOT}/Driver.cpp
    ${SRCROOT}/GlobalHeader.cpp
    ${SRCROOT}/LocalHeader.cpp
    ${SRCROOT}/Peak.cpp
    ${SRCROOT}/Scanner.cpp
    ${SRCROOT}/Spectrum.cpp
    ${BisonOutputSrc}
    ${FlexOutputSrc}
)
set(ROOT_HEADER
    ${INCROOT}/Analyse.hpp
    ${INCROOT}/Convert.hpp
    ${INCROOT}/defines.hpp
    ${INCROOT}/Driver.hpp
    ${INCROOT}/FlexLexer.hpp
    ${INCROOT}/GlobalHeader.hpp
    ${INCROOT}/LocalHeader.hpp
    ${INCROOT}/Peak.hpp
    ${INCROOT}/Scanner.hpp
    ${INCROOT}/Spectrum.hpp
    ${BisonOutputInc}
)
set(ROOT_FILES
    ${ROOT_HEADER}
    ${ROOT_SRC}
)

#FILES
set(FILES_HEADER
    ${ROOT_HEADER}
)
set(FILES_SRC
    ${ROOT_SRC}
)

#SHARED lib
add_library(${CMAKE_PROJECT_NAME} SHARED ${FILES_HEADER} ${FILES_SRC})
SET_TARGET_PROPERTIES(${CMAKE_PROJECT_NAME}
    PROPERTIES
    VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}
    SOVERSION ${VERSION_MAJOR}.${VERSION_MINOR}
)
INSTALL(TARGETS ${CMAKE_PROJECT_NAME}
    DESTINATION lib
)


#static lib
add_library(${CMAKE_PROJECT_NAME}-static STATIC ${FILES_HEADER} ${FILES_SRC})
SET_TARGET_PROPERTIES(${CMAKE_PROJECT_NAME}-static
    PROPERTIES
    VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}
    SOVERSION ${VERSION_MAJOR}.${VERSION_MINOR}
)
INSTALL(TARGETS ${CMAKE_PROJECT_NAME}-static
    DESTINATION lib
)

#EXEMPLE
if(BUILD_EXAMPLES)
    add_executable(basic basic.cpp)
	target_link_libraries(basic ${CMAKE_PROJECT_NAME})
endif()

#header
#INSTALL(FILES ${INCROOT}
#    DESTINATION include
#    PERMISSIONS OWNER_READ GROUP_READ WORLD_READ
#)

file(GLOB DEPLOY_FILES_AND_DIRS "${PROJECT_SOURCE_DIR}/include/${CMAKE_PROJECT_NAME}/*")
foreach(ITEM ${DEPLOY_FILES_AND_DIRS})
   IF( IS_DIRECTORY "${ITEM}" )
      LIST( APPEND DIRS_TO_DEPLOY "${ITEM}" )
   ELSE()
      LIST( APPEND FILES_TO_DEPLOY "${ITEM}" )
   ENDIF()
endforeach()
INSTALL( FILES ${FILES_TO_DEPLOY} ${BisonOutputInc} DESTINATION include/${CMAKE_PROJECT_NAME} )
INSTALL( DIRECTORY ${DIRS_TO_DEPLOY} DESTINATION include/${CMAKE_PROJECT_NAME} )


########################################################################
# Create uninstall target
########################################################################
CONFIGURE_FILE(
    "${PROJECT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
    "${PROJECT_SOURCE_DIR}/cmake/cmake_uninstall.cmake"
  IMMEDIATE @ONLY)
ADD_CUSTOM_TARGET(uninstall
    "${CMAKE_COMMAND}" -P "${PROJECT_SOURCE_DIR}/cmake/cmake_uninstall.cmake"
)
