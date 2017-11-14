
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
# add_subdirectory(log_replay)

optional_init(envire_maps    
    HEADERS
        MLSProvider.hpp
        MLTraversabilityMapProvider.hpp
)
 
message("SRC extra is ${SRC_EXTRA}")
# message("HDR_EXTRA is ${HDR_EXTRA}")
# message("PKG_CONFIG_EXTRA is ${PKG_CONFIG_EXTRA}")

rock_library(lib_init
    SOURCES
        Base.cpp
        CommonStart.cpp
        DependentTask.cpp
        InitHelper.cpp
        MapProvider.cpp
        PointCloudProvider.cpp
        states/Init.cpp
        TransformerBroadcaster.cpp
        ${SRC_EXTRA}
        
        log_replay/CommonReplay.cpp
        log_replay/DepthMapProvider.cpp
        log_replay/DistanceImageProvider.cpp
        log_replay/ForceTorqueSensor.cpp
        log_replay/GenericRawToMotion2D.cpp
        log_replay/IMUDriver.cpp
        log_replay/JointDriver.cpp
        log_replay/MLSProvider.cpp
        log_replay/ReplayTask.cpp
        log_replay/ReplayPort.cpp
        log_replay/PointCloudProvider.cpp
        log_replay/PositionProvider.cpp
    HEADERS
        Base.hpp
        CameraDriver.hpp
        Container.hpp
        CommonStart.hpp
        DependentTask.hpp
        ForceTorqueSensor.hpp
        GenericTask.hpp
        IMUDriver.hpp
        InitHelper.hpp
        JointDriver.hpp
        LaserDriver.hpp
        MapProvider.hpp
        DepthMapProvider.hpp
        DistanceImageProvider.hpp
        MotionControl2D.hpp
        MotionControl2DProvider.hpp
        MotionPlannerProvider.hpp
        PointCloudProvider.hpp
        PositionProvider.hpp
        TrajectoryControl.hpp
        states/Init.hpp
        TraversabilityMapProvider.hpp
        TransformerBroadcaster.hpp
#         ${HDR_EXTRA}
        log_replay/CommonReplay.hpp
        log_replay/DepthMapProvider.hpp
        log_replay/DistanceImageProvider.hpp
        log_replay/ForceTorqueSensor.hpp
        log_replay/GenericRawToMotion2D.hpp
        log_replay/IMUDriver.hpp
        log_replay/JointDriver.hpp
        log_replay/MLSProvider.hpp
        log_replay/ReplayTask.hpp
        log_replay/ReplayPort.hpp
        log_replay/PointCloudProvider.hpp
        log_replay/PositionProvider.hpp
    DEPS_PKGCONFIG
        base-lib
        orocos_cpp_base
        orocos_cpp
        lib_config
        logger-proxies
        logger-tasks-gnulinux
        state_machine
        state_machine_viz
        transformer-proxies
        lib_config
        rock_replay
        ${PKG_CONFIG_EXTRA}
)

