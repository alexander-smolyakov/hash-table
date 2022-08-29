cmake_minimum_required( VERSION 3.12 )

project( hash-table )

# include files
include_directories( ./include/example_app ./src)

# target
add_executable( binary ./app/example_app.cpp )
