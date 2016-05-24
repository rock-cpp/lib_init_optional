
SET(SRC_EXTRA)
SET(HDR_EXTRA)
SET(PKG_CONFIG_EXTRA)


macro(optional_dep LIB_NAME ARG_LIST)
    pkg_check_modules(MODULE ${LIB_NAME})
    if(MODULE_FOUND)
        rock_target_definition(${ARG_LIST} ${ARGN})
#         message("Found ${LIB_NAME} in version ${MODULE_VERSION}")
        SET(SRC_EXTRA ${SRC_EXTRA} ${${ARG_LIST}_SOURCES} )
        SET(HDR_EXTRA ${HDR_EXTRA} ${${ARG_LIST}_HEADERS} )
        SET(PKG_CONFIG_EXTRA ${PKG_CONFIG_EXTRA} ${LIB_NAME} )
    endif()
endmacro()

optional_dep(canbus-proxies 
    SOURCES
        Canbus.cpp    
    HEADERS
        Canbus.hpp
)

message("SRC extra is ${SRC_EXTRA}")

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
