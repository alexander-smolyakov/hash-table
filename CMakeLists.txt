project(hash_table)               # Create project "simple_example"

# Add main.cpp file of project root directory as source file
set(SOURCE_FILES main.cpp)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(hash_table ${SOURCE_FILES})