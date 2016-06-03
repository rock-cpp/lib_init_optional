
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
        foreach(SOURCE ${${ARG_LIST}_SOURCES})
            LIST(APPEND SRC_EXTRA "${CMAKE_CURRENT_SOURCE_DIR}/${SOURCE}" )
        endforeach()
        SET(SRC_EXTRA ${SRC_EXTRA} PARENT_SCOPE)
        foreach(HEADER ${${ARG_LIST}_HEADERS})
            install(FILES "${CMAKE_CURRENT_SOURCE_DIR}/${HEADER}" DESTINATION include/lib_init)
        endforeach()
        LIST(APPEND PKG_CONFIG_EXTRA ${LIB_NAME})
        SET(PKG_CONFIG_EXTRA ${PKG_CONFIG_EXTRA} PARENT_SCOPE)
    endif()
endmacro()

add_subdirectory(optional)


message("SRC extra is ${SRC_EXTRA}")
# message("HDR_EXTRA is ${HDR_EXTRA}")
# message("PKG_CONFIG_EXTRA is ${PKG_CONFIG_EXTRA}")

rock_library(lib_init
    SOURCES
        DependentTask.cpp
        Base.cpp
        CommonStart.cpp
        states/Init.cpp
        ${SRC_EXTRA}
    HEADERS
        Base.hpp
        CameraDriver.hpp
        Container.hpp
        CommonStart.hpp
        DependentTask.hpp
        IMUDriver.hpp
        JointDriver.hpp
        LaserDriver.hpp
        MotionControl2D.hpp
        MotionPlannerProvider.hpp
        PositionProvider.hpp
        TrajectoryControl.hpp
        states/Init.hpp
        TraversabilityMapProvider.hpp
#         ${HDR_EXTRA}
    DEPS_PKGCONFIG
        base-lib
        orocos_cpp_base
        orocos_cpp
        lib_config
        logger-proxies
        state_machine
        state_machine_viz
        lib_config
        ${PKG_CONFIG_EXTRA}
)
