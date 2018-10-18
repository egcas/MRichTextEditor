cmake_minimum_required(VERSION 2.8.11)

project(test_mrichtextedit)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set_property(TARGET egcas PROPERTY CXX_STANDARD 11)
set_property(TARGET egcas PROPERTY CXX_STANDARD_REQUIRED ON)

# Widgets finds its own dependencies.
find_package(Qt5 COMPONENTS Widgets )
include_directories(../src/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(test_mrichtextedit 
        test.cpp
)

target_link_libraries(test_mrichtextedit mrichtextedit Qt5::Gui Qt5::Core Qt5::Widgets)

  
