# Set include directories folder
set(DSTK_CORE_DIR "${PROJECT_SOURCE_DIR}/dstk_core/")
include_directories("${DSTK_CORE_DIR}/include")

# Set source files and executable.
set(DSTK_SOURCE_DIR "${DSTK_CORE_DIR}/src")
set(DSTK_SRC 
	"${DSTK_SOURCE_DIR}/dstk_core.cpp"
	"${DSTK_SOURCE_DIR}/dstk_mat.cpp")
message("DSTK_SRC : ${DSTK_SRC}")
add_library (dstk_core STATIC ${DSTK_SRC})

# Set target include directory
target_include_directories(dstk_core PUBLIC "${DSTK_CORE_DIR}/include/extern")

# TODO: Add tests and install targets if needed.
option(INCLUDE_TESTS "GENERATE TESTS EXECUTABLES" ON)
if(INCLUDE_TESTS)
	message("GENERATING TEST EXECUTABLES.")
	add_subdirectory("tests")
endif()