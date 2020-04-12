# add executables and test files
add_executable(test_dstk test_dstk.cpp)
target_link_libraries(test_dstk dstk_core)
