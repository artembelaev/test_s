cmake_minimum_required (VERSION 3.8)
project ("test_saber")

# link boost test

set(Boost_INCLUDE_DIR $ENV{Boost_INCLUDE_DIR})
set(BOOST_LIBRARYDIR ${Boost_INCLUDE_DIR}/lib64-msvc-14.2)
find_package(Boost REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${BOOST_LIBRARYDIR})


# src
add_executable (test_saber 
"tests/initTests.cpp"
"tests/test_dec_to_bin.cpp" 
"tests/test_remove_dups.cpp" 
"tests/test_list_serialize.cpp" "dec_to_bin.h"  "remove_dups.h" "list_node.h")

# include

target_include_directories(test_saber PRIVATE ${CMAKE_SOURCE_DIR})

# libs

target_link_libraries(test_saber PRIVATE ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

