add_subdirectory(Base)
add_library(DataStructures OBJECT HashTables/HashTables.c Stacks/Stacks.c Queues/Queues.c HashTables/HashFunctions/HashFunctions.c)
target_include_directories(DataStructures PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/HashTables ${CMAKE_CURRENT_SOURCE_DIR}/Stacks ${CMAKE_CURRENT_SOURCE_DIR}/Queues ${CMAKE_CURRENT_SOURCE_DIR}/HashTables/HashFunctions)
target_link_libraries(DataStructures PUBLIC Arrays LinkedLists)