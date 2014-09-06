CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
SET(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_modules)

PROJECT(feedback)

FIND_PACKAGE(SystemC REQUIRED)
SET(Boost_USE_STATIC_LIBS ON)

## Add python support 
SET(PYTHON ON)
if(PYTHON)
    ADD_DEFINITIONS(-DPYTHON)
    FIND_PACKAGE(Boost REQUIRED COMPONENTS graph python)
    FIND_PACKAGE(PythonLibs REQUIRED)
    INCLUDE_DIRECTORIES(${PYTHON_INCLUDE_DIRS})
else()
    FIND_PACKAGE(Boost REQUIRED COMPONENTS graph)
endif()

 
INCLUDE_DIRECTORIES(${SystemC_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

ADD_EXECUTABLE(feedback.out src/main.cpp)
ADD_SUBDIRECTORY(src)


if(PYTHON)
    TARGET_LINK_LIBRARIES(feedback.out 
        ${SystemC_LIBRARIES}
        ${Boost_LIBRARIES}
        ${PYTHON_LIBRARIES}
        )
else()
    TARGET_LINK_LIBRARIES(feedback.out 
        channel
        ${SystemC_LIBRARIES}
        ${Boost_LIBRARIES}
        )
endif()
