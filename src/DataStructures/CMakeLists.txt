add_subdirectory(Base)
add_library(DataStructures OBJECT HashTables/HashTables.c Stacks/Stacks.c Queues/Queues.c HashTables/HashFunctions/HashFunctions.c)
target_include_directories(DataStructures PUBLIC "${CMAKE_SOURCE_DIR}/include/Data Structures")
target_link_libraries(DataStructures PUBLIC Arrays LinkedLists)