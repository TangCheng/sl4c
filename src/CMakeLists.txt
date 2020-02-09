
set(headers ${CMAKE_SOURCE_DIR}/include)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} SOURCES)

add_library(sl4c ${SOURCES})
target_include_directories(sl4c PUBLIC "${headers}")
