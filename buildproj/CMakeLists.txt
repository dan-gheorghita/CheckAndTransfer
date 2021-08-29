cmake_minimum_required(VERSION 2.4)

project(check_and_transfer)

file(GLOB_RECURSE SRC_FILES ../*.cpp)
get_filename_component(DIR_ONE_ABOVE ../ ABSOLUTE)
add_executable(check ../checkandtransfer.cpp ../Director.cpp ../Director_input.cpp)
target_include_directories(check PUBLIC ${DIR_ONE_ABOVE}/include)
