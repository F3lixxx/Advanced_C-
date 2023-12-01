cmake_minimum_required(VERSION 3.26)
project(HW01_Checking_the_basic_functions)

set( CMAKE_CXX_STANDARD 23 )


add_subdirectory(./Catch2 Catch2-build)
add_executable( HW01_Checking_the_basic_functions main.cpp )
target_link_libraries(HW01_Checking_the_basic_functions PRIVATE Catch2::Catch2)