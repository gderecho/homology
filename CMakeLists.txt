cmake_minimum_required (VERSION 3.1)
project (Homology)


set (CMAKE_CXX_STANDARD 17)


file(GLOB TEST_SOURCES test/*.cpp)

add_executable(homology_test ${TEST_SOURCES})
target_include_directories(homology_test PUBLIC test)
set_target_properties(homology_test PROPERTIES LINKER_LANGUAGE CXX)

enable_testing()
add_test(NAME HomologyTest COMMAND homology_test)
