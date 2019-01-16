cmake_minimum_required(VERSION 2.8.11)

# Tell CMake to run moc when necessary:
set(CMAKE_AUTOMOC ON)
# As moc files are generated in the binary dir, tell CMake
# to always look for includes there:
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set_property(TARGET egcas PROPERTY CXX_STANDARD 11)
set_property(TARGET egcas PROPERTY CXX_STANDARD_REQUIRED ON)


# Widgets finds its own dependencies.
find_package(Qt5 COMPONENTS Widgets Gui Core)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

#this is for showing up abstract interfaces and other sources in the IDE
add_custom_target(mrichtextedit_other_srcs ALL SOURCES
        include/mrichtextedit.h
        include/mtextedit.h
)

qt5_wrap_ui(MRICHTEXTEDIT_UIS
            mrichtextedit.ui
)

qt5_wrap_cpp(MRICHTEXTEDIT_MOC
            include/mrichtextedit.h
            include/mtextedit.h
)

qt5_add_resources(MRICHTEXT_RCCS res/icons.qrc)

add_library(mrichtextedit STATIC
        mrichtextedit.cpp 
        mtextedit.cpp 
        ${MRICHTEXTEDIT_UIS}
        ${MRICHTEXTEDIT_MOC}
        ${MRICHTEXT_RCCS}
)

# Widgets finds its own dependencies.
find_package(Qt5 COMPONENTS Widgets)

target_link_libraries(mrichtextedit Qt5::Gui Qt5::Core Qt5::Widgets)

#for in-tree build (publish API headers in binary dir)
add_custom_command(TARGET mrichtextedit
        COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_BINARY_DIR}/include/richtextedit
        COMMAND ${CMAKE_COMMAND} -E copy include/mtextedit.h ${CMAKE_BINARY_DIR}/include/richtextedit
        COMMAND ${CMAKE_COMMAND} -E copy include/mrichtextedit.h ${CMAKE_BINARY_DIR}/include/richtextedit
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "copy the mrichtextedit library headers to the include directory" VERBATIM)


  
