cmake_minimum_required (VERSION 3.8)
project ("test_saber")

set(Boost_INCLUDE_DIR $ENV{Boost_INCLUDE_DIR})
set(BOOST_LIBRARYDIR ${Boost_INCLUDE_DIR}/lib64-msvc-14.2)


find_package(Boost REQUIRED)

message("found: " ${Boost_FOUND} " " ${BOOST_LIBRARYDIR})

include_directories(${Boost_INCLUDE_DIR})
link_directories(${BOOST_LIBRARYDIR})
add_executable (test_saber 
	"tests/initTests.cpp"
)
target_link_libraries(test_saber PRIVATE ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})


