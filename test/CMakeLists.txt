cmake_minimum_required(VERSION 2.8.11)

project(test_mrichtextedit)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(test_mrichtextedit 
        test.cpp
)

# Widgets finds its own dependencies.
find_package(Qt5 COMPONENTS Widgets )
target_link_libraries(test_mrichtextedit mrichtextedit Qt5::Widgets)
include_directories(../src/include)
  