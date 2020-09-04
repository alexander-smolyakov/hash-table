cmake_minimum_required( VERSION 3.12 )

project( hash-table )

# include files
include_directories( ./include ./src)

# target
add_executable( binary ./src/main.cpp )
