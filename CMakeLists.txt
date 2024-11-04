cmake_minimum_required(VERSION 3.15)
project(IfcExplorer CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES "src/*.cpp")

add_executable(IfcExplorer ${SOURCES})

install(TARGETS IfcExplorer DESTINATION "."
        RUNTIME DESTINATION bin
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        )

# (Optional) Include directories for SQLite
target_include_directories(IfcExplorer PRIVATE external/sqlite)

# (Optional) Specify include directories
# target_include_directories(MyProject PUBLIC /path/to/includes)

# (Optional) Specify libraries to link against
# target_link_libraries(MyProject PRIVATE some_library)
