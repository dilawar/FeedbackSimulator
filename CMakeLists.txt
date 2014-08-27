CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
PROJECT(cell_control)

include(ExternalProject)
ExternalProject_Add(
   systemc-2.3
   PREFIX ${CMAKE_SOURCE_DIR}/systemc-2.3
   SOURCE_DIR  ${CMAKE_SOURCE_DIR}/systemc-2.3
   CONFIGURE_COMMAND ${CMAKE_SOURCE_DIR}/systemc-2.3/configure --prefix=${CMAKE_SOURCE_DIR}/systemc-2.3
   BUILD_COMMAND ${MAKE}
   BUILD_IN_SOURCE 1
) 
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/systemc-2.3/include)
LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/systemc-2.3/lib)

ADD_EXECUTABLE(cell_control src/main.cpp)


