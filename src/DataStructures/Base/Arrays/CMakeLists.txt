add_library(Arrays STATIC IntSortingAlgorithms.c Arrays.c Utils.c IntSearchingAlgorithms.c)
target_include_directories(Arrays PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/Data Structures")