cmake_minimum_required(VERSION 3.1)
project(boost_named_pipe_tests)

# manage dependencies
if (EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
	find_package(Boost REQUIRED)
endif()
if (NOT Boost_FOUND)
	message("Can't find Boost libraries!" FATAL_ERROR)
endif()
find_package(Threads)

add_executable(test_boost_pipes_client
	"server.cpp"
	"terminal_charset_utils.cpp")
target_include_directories(test_boost_pipes_client SYSTEM PUBLIC ${Boost_INCLUDE_DIRS})
target_include_directories(test_boost_pipes_client PUBLIC include)
target_link_libraries(test_boost_pipes_client ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

add_executable(test_boost_pipes_server
	"client.cpp"
	"terminal_charset_utils.cpp")

target_include_directories(test_boost_pipes_server SYSTEM PUBLIC ${Boost_INCLUDE_DIRS})
target_include_directories(test_boost_pipes_server PUBLIC include)
target_link_libraries(test_boost_pipes_server ${Boost_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})
