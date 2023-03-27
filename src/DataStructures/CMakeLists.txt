add_subdirectory(Base)
add_library(DataStructures OBJECT HashTables/HashTables.c Stacks/Stacks.c Queues/Queues.c)
target_include_directories(DataStructures PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(DataStructures PUBLIC Arrays LinkedLists)