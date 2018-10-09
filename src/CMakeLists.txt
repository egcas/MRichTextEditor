cmake_minimum_required(VERSION 2.8.11)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# Widgets finds its own dependencies.
find_package(Qt5 COMPONENTS Widgets Gui Core)

include_directories(${CMAKE_BINARY_DIR}/include/richtextedit)

qt5_wrap_ui(MRICHTEXTEDIT_UIS
            mrichtextedit.ui
)

add_library(mrichtextedit STATIC  
        mrichtextedit.cpp 
        mtextedit.cpp 
        ${MRICHTEXTEDIT_UIS}
)

# Widgets finds its own dependencies.
find_package(Qt5 COMPONENTS Widgets)

target_link_libraries(mrichtextedit Qt5::Widgets)

#for in-tree build (publish API headers in binary dir)
add_custom_target(mrichtextedit_header
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/include/richtextedit
        COMMAND ${CMAKE_COMMAND} -E copy include/mtextedit.h ${CMAKE_BINARY_DIR}/include/richtextedit
        COMMAND ${CMAKE_COMMAND} -E copy include/mrichtextedit.h ${CMAKE_BINARY_DIR}/include/richtextedit
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "copy the mrichtextedit library headers to the include directory" VERBATIM)
add_dependencies(mrichtextedit mrichtextedit_header)

  
