cmake_minimum_required(VERSION 3.8)
project(anafind VERSION 1.0.0 LANGUAGES CXX C)

include(GNUInstallDirs)
include(CTest)

# require pthreads
set(CMAKE_THREAD_PREFER_PTHREAD ON)
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

###################
# anafind library #
################################################################################

# get list of source files
file(GLOB_RECURSE anafind_src relative ${CMAKE_CURRENT_SOURCE_DIR} "src/*.cpp" "src/*c")
add_library(anafind SHARED ${anafind_src})

set_property(TARGET anafind PROPERTY POSITION_INDEPENDENT_CODE on)
target_compile_options(anafind PRIVATE -g -Wall -pedantic -Wshadow -Wfatal-errors)

target_compile_features(anafind
  PRIVATE cxx_std_17
)

target_include_directories(anafind
	PUBLIC $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
	PUBLIC $<INSTALL_INTERFACE:include>
	PRIVATE src
)

target_link_libraries(anafind
	Threads::Threads
)

# 'make install' to the correct locations (provided by GNUInstallDirs)
install(TARGETS anafind
	EXPORT anafind_config
	LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
	ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR})
install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

# This makes the project importable from the install directory
# Put config file in per-project dir (name MUST match), can also
# just go into 'cmake'
install(EXPORT anafind_config DESTINATION share/anafind/cmake)

# uninstall target
if(NOT TARGET uninstall)
	configure_file(
		"${CMAKE_CURRENT_SOURCE_DIR}/cmake_uninstall.cmake.in"
		"${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
		IMMEDIATE @ONLY)
	add_custom_target(uninstall
		COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)
endif()

################################################################################

# test case 1
add_executable(BasicTest test/BasicTest.cpp)
target_link_libraries(BasicTest anafind)
add_test(BasicTest BasicTest)
