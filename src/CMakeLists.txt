
SET(SRC_EXTRA)
SET(HDR_EXTRA)
SET(PKG_CONFIG_EXTRA)

macro(parse TARGET_NAME)
    set(ROCK_TARGET_AVAILABLE_MODES "SOURCES;HEADERS")
    set(${TARGET_NAME}_MODE "SOURCES")
    foreach(ELEMENT ${ARGN})
        list(FIND ROCK_TARGET_AVAILABLE_MODES "${ELEMENT}" IS_KNOWN_MODE)
        if (IS_KNOWN_MODE GREATER -1)
            set(${TARGET_NAME}_MODE "${ELEMENT}")
        else()
            list(APPEND ${TARGET_NAME}_${${TARGET_NAME}_MODE} "${ELEMENT}")
        endif()
    endforeach()
endmacro()

macro(optional_init LIB_NAME)
    pkg_check_modules(${LIB_NAME} ${LIB_NAME})
    if(${LIB_NAME}_FOUND)
        SET(ARG_LIST ${LIB_NAME})
        parse(${ARG_LIST} ${ARGN})
#         message("Found ${LIB_NAME} in version ${${LIB_NAME}_VERSION}")
#         message("Found ${${ARG_LIST}_SOURCES}")
        LIST(APPEND SRC_EXTRA ${${ARG_LIST}_SOURCES} )
        SET(HDR_EXTRA ${HDR_EXTRA} ${${ARG_LIST}_HEADERS} )
        SET(PKG_CONFIG_EXTRA ${PKG_CONFIG_EXTRA} ${LIB_NAME} )
    endif()
endmacro()


optional_init(hbridge-proxies 
    SOURCES
        HBridge.cpp    
    HEADERS
        HBridge.hpp    
)

optional_init(canbus-proxies 
    SOURCES
        Canbus.cpp    
    HEADERS
        Canbus.hpp
)

# message("SRC extra is ${SRC_EXTRA}")
# message("HDR_EXTRA is ${HDR_EXTRA}")
# message("PKG_CONFIG_EXTRA is ${PKG_CONFIG_EXTRA}")

rock_library(lib_init
    SOURCES
        DependentTask.cpp
        Base.cpp
        states/Init.cpp
        ${SRC_EXTRA}
    HEADERS
        Base.hpp
        CameraDriver.hpp
        Container.hpp
        DependentTask.hpp
        IMUDriver.hpp
        JointDriver.hpp
        states/Init.hpp
        ${HDR_EXTRA}
    DEPS_PKGCONFIG
        base-lib
        orocos_cpp_base
        orocos_cpp
        lib_config
        logger-proxies
        state_machine
        lib_config
        ${PKG_CONFIG_EXTRA}
)
