cmake_minimum_required(VERSION 3.5)

file (GLOB_RECURSE SOURCES "*.c")
file (GLOB_RECURSE HEADERS "../include/*.h")

set(GCC_COVERAGE_COMPILE_FLAGS "-g -Wall -Wpedantic")

include_directories(
  ${CMAKE_CURRENT_LIST_DIR}/../include
)
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
  
add_executable(emu86 ${SOURCES} ${HEADERS})