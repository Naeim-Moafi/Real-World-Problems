cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_COMPILER "g++-11")

project(my_google_test)

#get googletest
include(FetchContent)
FetchContent_Declare(googletest 
GIT_REPOSITORY https://github.com/google/googletest
GIT_TAG v1.13.0)
FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
	FetchContent_Populate(googletest)
	add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

add_library(func_lib STATIC func.cpp)

add_executable(main main.cpp )
target_link_libraries(main func_lib)

add_executable(testRunner test.cpp)
target_link_libraries(testRunner func_lib gtest_main gmock_main)