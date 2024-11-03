# Minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Project name
project(MyProject)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the SQLite source files
set(SQLITE_SOURCE_FILES
    external/sqlite/sqlite3.c
    external/sqlite/sqlite3.h
)

# Collect all source files in the 'src' directory
file(GLOB SOURCES "src/*.cpp")

# Add the executable target
add_executable(MyProject ${SOURCES} ${SQLITE_SOURCE_FILES})

# (Optional) Include directories for SQLite
target_include_directories(MyProject PRIVATE external/sqlite)

# (Optional) Specify include directories
# target_include_directories(MyProject PUBLIC /path/to/includes)

# (Optional) Specify libraries to link against
# target_link_libraries(MyProject PRIVATE some_library)
