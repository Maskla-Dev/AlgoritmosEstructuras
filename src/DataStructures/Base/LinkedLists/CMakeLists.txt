add_library(LinkedLists OBJECT LinkedLists.c CharLinkedList.c CharLinkedList.h)
target_include_directories(LinkedLists PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})