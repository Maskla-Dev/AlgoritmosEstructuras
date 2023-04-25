add_library(LinkedLists STATIC LinkedLists.c CharLinkedList.c SimpleLinkedLists.c DoubleLinkedLists.c)
target_include_directories(LinkedLists PUBLIC "${CMAKE_SOURCE_DIR}/include/Data Structures")