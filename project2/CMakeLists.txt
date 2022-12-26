project(project2)
cmake_minimum_required(VERSION 3.23)
file(GLOB SRC *.c *.h)

add_executable(${PROJECT_NAME} ${EXTRA_INCLUDE})
