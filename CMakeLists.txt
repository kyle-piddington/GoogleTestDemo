cmake_minimum_required (VERSION 3.0)

#environment Setup,  add C++11, debugging symbols, all warnings
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall ")
option(test "Build all tests." ON) # Makes boolean 'test' available.


project (GoogleTestDemo)
#Enable a testing library with CMAKE
enable_testing()
#Include any libraries
include_directories ("${PROJECT_SOURCE_DIR}/lib")
#Include any include files
include_directories ("${PROJECT_SOURCE_DIR}/include")

#Gather any source files
file(GLOB_RECURSE GoogleTestDemo_SOURCES "src/*.cpp" "src/*.cc")



#Gather header Files
file(GLOB_RECURSE GoogleTestDemo_HEADERS "src/*.h")

#traverse the header files gathered in the last step, and add them to the include path.
#(This allows for top level includes of all headers). If you don't want to do this,
#you'll have to use "include/path/to/header.h" instead of "header.h" on includes.
set (GraphicsEngine_INCLUDE_DIRS "")
foreach (_headerFile ${GraphicsEngine_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND GraphicsEngine_INCLUDE_DIRS ${_dir})
endforeach()
list(REMOVE_DUPLICATES GraphicsEngine_INCLUDE_DIRS)
include_directories(${GraphicsEngine_INCLUDE_DIRS})


#Build the main project as a library, and only link main at the end
list(REMOVE_ITEM GoogleTestDemo_SOURCES ${PROJECT_SOURCE_DIR}/src/main.cpp)
add_library(GoogleTestDemo_Lib ${GoogleTestDemo_SOURCES})

#add main
add_executable(GoogleTestDemo ${PROJECT_SOURCE_DIR}/src/main.cpp)

#and link the 'library'
target_link_libraries(GoogleTestDemo GoogleTestDemo_Lib)


if (test)
  # This adds another subdirectory, which has 'project(gtest)'.
  add_subdirectory(lib/gtest)

  enable_testing()

  # Include the gtest library. gtest_SOURCE_DIR is available due to
  # 'project(gtest)' above.
  include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
  #include all source headers as well
  include_directories(${GraphicsEngine_INCLUDE_DIRS})

  ##############
  # Unit Tests
  ##############
  #Gather all unit tests.
  file(GLOB_RECURSE TEST_SRC_FILES "test/*.cpp")

  #Add tests to the executable
  add_executable(runUnitTests ${TEST_SRC_FILES})

  # Standard linking to gtest stuff.
  target_link_libraries(runUnitTests gtest gtest_main)

  # Extra linking for the project.
  target_link_libraries(runUnitTests GoogleTestDemo_Lib)


endif()
