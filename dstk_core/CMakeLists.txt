# CMakeList.txt : CMake project for dstk_core, include source and define
cmake_minimum_required (VERSION 3.8)

# Set include directories folder
set(DSTK_CORE_DIR "${PROJECT_SOURCE_DIR}/dstk_core/")
include_directories("${DSTK_CORE_DIR}/include")

# Set source files and executable.
set(DSTK_SOURCE_DIR "${DSTK_CORE_DIR}/src")
set(DSTK_SRC "${DSTK_SOURCE_DIR}/dstk_core.cpp")
add_library (lib_dstk_core STATIC ${DSTK_SRC})

# Set target include directory
target_include_directories(lib_dstk_core PUBLIC "${DSTK_CORE_DIR}/include/extern")

# TODO: Add tests and install targets if needed.
option(INCLUDE_TESTS "GENERATE TESTS EXECUTABLES" ON)
if(INCLUDE_TESTS)
	message("GENERATING TEST EXECUTABLES.")
	add_subdirectory("tests")
endif()