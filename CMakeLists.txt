cmake_minimum_required(VERSION 3.0)

project(core-cs)
include(gtest.cmake)

SET(COVERAGE OFF CACHE BOOL "Coverage")
add_definitions(-Wall -std=c++11)

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "data-structures/*.cpp")
add_executable(data_structures_tests ${SOURCES})
file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "algorithms/*.cpp")
add_executable(algorithms_tests ${SOURCES})

find_package (Threads)
target_link_libraries(data_structures_tests PUBLIC gtest ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(algorithms_tests PUBLIC gtest ${CMAKE_THREAD_LIBS_INIT})

if (MSVC)
    target_compile_options(data_structures_tests PRIVATE /std:c++17 /W4 /WX)
    target_compile_options(algorithms_tests PRIVATE /std:c++17 /W4 /WX)

    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /Ox")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /Od")

    # VS 2017 removed tr1
    add_definitions(-DGTEST_HAS_TR1_TUPLE=0)
else()
    target_compile_options(data_structures_tests PRIVATE -std=c++11 -g -Wall -Werror -Wextra -Wpedantic -Wconversion -Wswitch-default -Wswitch-enum -Wunreachable-code -Wwrite-strings -Wcast-align -Wshadow -Wundef)
    target_compile_options(algorithms_tests PRIVATE -std=c++11 -g -Wall -Werror -Wextra -Wpedantic -Wconversion -Wswitch-default -Wswitch-enum -Wunreachable-code -Wwrite-strings -Wcast-align -Wshadow -Wundef)

    if (COVERAGE)
        target_compile_options(data_structures_tests PRIVATE --coverage)
        target_compile_options(algorithms_tests PRIVATE --coverage)
        target_link_libraries(data_structures_tests PRIVATE --coverage)
        target_link_libraries(algorithms_tests PRIVATE --coverage)
    endif()
endif()
