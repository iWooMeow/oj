add_subdirectory(LinkedLists)

add_executable(josephus josephus.c)

target_link_libraries(josephus PUBLIC LinkedList)
