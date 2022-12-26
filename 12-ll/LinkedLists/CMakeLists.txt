add_library(LinkedList STATIC LinkedList.c)

target_include_directories(LinkedList INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})