CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)
PROJECT(feedback)

FIND_PACKAGE(SystemC REQUIRED)
ADD_DEFINITIONS(-std=c++11)

SET(Boost_USE_STATIC_LIBS OFF)


## Add python support 
SET(PYTHON OFF)
if(PYTHON)
    SET(PYPATH ${CMAKE_SOURCE_DIR}/python)
    ADD_DEFINITIONS(-DPYTHON)
    FIND_PACKAGE(Boost REQUIRED COMPONENTS graph python log)
    ADD_DEFINITIONS(-DBOOST_LOG_DYN_LINK)
    FIND_PACKAGE(PythonLibs REQUIRED)
    INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_DIRS})
else()
    FIND_PACKAGE(Boost REQUIRED COMPONENTS graph)
endif()

INCLUDE_DIRECTORIES(${SystemC_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

ADD_SUBDIRECTORY(src)

if(PYTHON)
else()
    ADD_EXECUTABLE(feedback.out src/main.cpp)
endif()

if(PYTHON)
    MESSAGE("++ Building for python: Modules will be saved in ${PYPATH}")
else()
    TARGET_LINK_LIBRARIES(feedback.out 
        channel
        ${SystemC_LIBRARIES}
        ${Boost_LIBRARIES}
        )
endif()
