cmake_minimum_required (VERSION 3.12)
project (Homology)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()



set(CMAKE_CXX_STANDARD 20)
add_compile_options(-fconcepts -O3)
add_compile_options(-pedantic -Wall -Wextra -Wcast-align -Wcast-qual
                    -Wctor-dtor-privacy -Wdisabled-optimization
                    -Wformat=2 -Winit-self -Wlogical-op -Wmissing-declarations
                    -Wmissing-include-dirs -Wnoexcept -Wold-style-cast
                    -Woverloaded-virtual -Wredundant-decls -Wshadow
                    -Wsign-conversion -Wsign-promo -Wstrict-null-sentinel
                    -Wstrict-overflow=5 -Wswitch-default -Wundef -Werror -Wno-unused)


file(GLOB ZTEST_SOURCES test/z_test/*.cpp)

add_executable(z_test ${ZTEST_SOURCES})
target_include_directories(z_test PUBLIC test)
target_include_directories(z_test PUBLIC include)
set_target_properties(z_test PROPERTIES LINKER_LANGUAGE CXX)

file(GLOB MATRIXTEST_SOURCES test/matrix_test/*.cpp)

add_executable(matrix_test ${MATRIXTEST_SOURCES})
target_include_directories(matrix_test PUBLIC test)
target_include_directories(matrix_test PUBLIC include)
set_target_properties(matrix_test PROPERTIES LINKER_LANGUAGE CXX)




enable_testing()
add_test(NAME ZTest COMMAND z_test)
add_test(NAME MatrixTest COMMAND matrix_test)
