CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
SET(SRC Channel.cpp Module.cpp RandomVariable.cpp)

IF(PYTHON)
    ADD_LIBRARY(channel MODULE ${SRC})
    SET_TARGET_PROPERTIES(channel
        PROPERTIES PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY ${PYPATH}
        )
    TARGET_LINK_LIBRARIES(channel 
        ${Python_LIBRARIES}
        ${SystemC_LIBRARIES}
        ${Boost_LIBRARIES}
        )
ELSE()
    ADD_LIBRARY(channel STATIC ${SRC})
ENDIF()

