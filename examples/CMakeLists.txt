set(INCROOT ${PROJECT_SOURCE_DIR}/examples)
set(SRCROOT ${PROJECT_SOURCE_DIR}/examples)

find_library(LIBS mgf)

add_executable(basic mgf.cpp)
target_link_libraries(basic ${LIBS})


