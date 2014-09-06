CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
SET(SRC Channel.cpp)

ADD_LIBRARY(channel MODULE
    ${SRC}
)

IF(PYTHON)
    SET_TARGET_PROPERTIES(channel
        PROPERTIES PREFIX ""
        LIBRARY_OUTPUT_DIRECTORY ${PYPATH}
        )
    TARGET_LINK_LIBRARIES(channel 
        ${Python_LIBRARIES}
        ${SystemC_LIBRARIES}
        ${Boost_LIBRARIES}
        )
endif()

