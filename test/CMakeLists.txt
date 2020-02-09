
add_subdirectory(googletest EXCLUDE_FROM_ALL)

aux_source_directory(${CMAKE_CURRENT_SOURCE_DIR} TEST_SOURCES)
add_executable(sl4c_test ${TEST_SOURCES})

target_link_libraries(sl4c_test sl4c gtest_main)

add_test(NAME sl4c_test COMMAND sl4c_test)
