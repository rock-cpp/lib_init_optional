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


optional_init(ctrl_lib-proxies)

optional_init(camera_usb-proxies
    SOURCES
        UsbCameraDriver.cpp
    HEADERS
        UsbCameraDriver.hpp
)

optional_init(canbus-proxies 
    SOURCES
        Canbus.cpp   
    HEADERS
        Canbus.hpp
)

optional_init(controldev-proxies
    SOURCES
        Joypad.cpp
        GenericRawToMotion2D.cpp
    HEADERS
        Joypad.hpp
        GenericRawToMotion2D.hpp
)

optional_init(depth_map_preprocessing-proxies
    SOURCES
        DepthMapToPCLConverter.cpp
        OutlierFilter.cpp
    HEADERS
        DepthMapToPCLConverter.hpp
        OutlierFilter.hpp
)

optional_init(hbridge-proxies 
    SOURCES
        HBridge.cpp    
    HEADERS
        HBridge.hpp    
)

optional_init(encoder_ichaus-proxies
    SOURCES
        EncoderIcHaus.cpp
    HEADERS
        EncoderIcHaus.hpp
)

optional_init(hokuyo-proxies
    SOURCES
        HokuyoLaserDriver.cpp
    HEADERS
        HokuyoLaserDriver.hpp
)

optional_init(graph_slam-proxies
    SOURCES
        VelodyneSlam.cpp
    HEADERS
        VelodyneSlam.hpp
)

optional_init(imu_xsens-proxies
    SOURCES
        IMUXsensDriver.cpp
    HEADERS
        IMUXsensDriver.hpp
)

optional_init(robot_frames-proxies
    SOURCES
        RobotFrames.cpp
    HEADERS
        RobotFrames.hpp
)

optional_init(kccd-proxies)

optional_init(laser_filter-proxies)

optional_init(localization-proxies
    SOURCES
        Localization.cpp
    HEADERS
        Localization.hpp
)

optional_init(local_tsdf_mapper-proxies
    SOURCES
        LocalTSDFMapper.cpp
    HEADERS
        LocalTSDFMapper.hpp
)

optional_init(mars-proxies
    SOURCES
        SimCameraDriver.cpp
        SimDepthMapDriver.cpp
        SimForceTorqueSensor.cpp
        SimIMUDriver.cpp
        SimJointDriver.cpp
        SimLaserDriver.cpp
        Simulator.cpp
        SimVelodyneDriver.cpp
        SimDistanceImageDriver.cpp
    HEADERS
        SimCameraDriver.hpp
        SimDepthMapDriver.hpp
        SimForceTorqueSensor.hpp
        SimIMUDriver.hpp
        SimJointDriver.hpp
        SimLaserDriver.hpp
        Simulator.hpp
        SimVelodyneDriver.hpp
        SimDistanceImageDriver.hpp
)

optional_init(manipulator_motion_planner-proxies
    SOURCES
        ArmPlannerCartesianSpace.cpp
        ArmPlannerJointSpace.cpp
    HEADERS
        ArmPlanner.hpp
        ArmPlannerCartesianSpace.hpp
        ArmPlannerJointSpace.hpp
)

optional_init(motion_planning_libraries-proxies
    SOURCES
        MotionPlanner.cpp
    HEADERS
        MotionPlanner.hpp
)

# optional_init(ndlcom_force_torque_sensor-proxies 
#     SOURCES
#         NDLComForceTorqueSensor.cpp
#     HEADERS
#         NDLComForceTorqueSensor.hpp
# )

optional_init(ndlcom_lipo_watcher-proxies 
    SOURCES
        NDLComLipoWatcher.cpp
    HEADERS
        NDLComLipoWatcher.hpp
)

optional_init(ndlcom_cpmb_watcher-proxies 
    SOURCES
        NDLComCpmbWatcher.cpp
    HEADERS
        NDLComCpmbWatcher.hpp
)

optional_init(ndlcom_device_driver-proxies
    SOURCES
        NDLComJointDriver.cpp
    HEADERS
        NDLComJointDriver.hpp
)

optional_init(ndlcom_aila_joints-proxies
    SOURCES
        AILAJointDriver.cpp
    HEADERS
        AILAJointDriver.hpp
)

# optional_init(ndlcom_sherpa_tt_joints-proxies
#     SOURCES
#         SherpaTTJointDriver.cpp
#     HEADERS
#         SherpaTTJointDriver.hpp
# )

optional_init(odometry-proxies
    SOURCES
        SkidOdometry.cpp
        LateralOdometry.cpp
        ContactPointOdometry.cpp
    HEADERS
        BodyContactsProvider.hpp
        SkidOdometry.hpp
        LateralOdometry.hpp
        ContactPointOdometry.hpp
)

optional_init(projection-proxies
    SOURCES
        ColorizedPointcloud.cpp
    HEADERS
        ColorizedPointcloud.hpp
)

optional_init(realtime_urdf_filter-proxies
    SOURCES
        RealtimeUrdfFilter.cpp
    HEADERS
        RealtimeUrdfFilter.hpp
)

optional_init(slam3d-proxies
    SOURCES
        Slam3d.cpp
    HEADERS
        Slam3d.hpp
)

optional_init(safety_control-proxies
    SOURCES
        SafetyController.cpp
    HEADERS
        SafetyController.hpp
)

optional_init(tofcamera_picoflex-proxies
    SOURCES
        TOFPicoFlex.cpp
    HEADERS
        TOFPicoFlex.hpp
)

optional_init(serial_ndlcom-proxies
    SOURCES
        NDLComSerial.cpp
    HEADERS
        NDLComSerial.hpp
)

optional_init(skid4_control-proxies
    SOURCES
        Skid4SafeControl.cpp
        Skid4MotionControl.cpp
    HEADERS
        Skid4SafeControl.hpp
        Skid4MotionControl.hpp
)

optional_init(servo_dynamixel-proxies
    SOURCES
        Dynamixel.cpp
    HEADERS
        Dynamixel.hpp
)

optional_init(simple_pose_integrator-proxies
    SOURCES
        PoseProvider.cpp
    HEADERS
        PoseProvider.hpp
)

optional_init(traversability-proxies
    SOURCES
        TraversabilitySimple.cpp
    HEADERS
        TraversabilitySimple.hpp
)

optional_init(tilt_scan-proxies
    SOURCES
        TiltScan.cpp
    HEADERS
        TiltScan.hpp
)

optional_init(trajectory_generation-proxies
    SOURCES
        TrajectoryGeneration.cpp
        TrajectoryGenerationVelocity.cpp
    HEADERS
        TrajectoryGeneration.hpp
        TrajectoryGenerationVelocity.hpp
)

optional_init(trajectory_follower-proxies
    SOURCES
        TrajectoryFollower.cpp
        TrajectoryFollowerWithSafeGuard.cpp
        PoseWatchdog.cpp
    HEADERS
        TrajectoryFollower.hpp
        TrajectoryFollowerWithSafeGuard.hpp
        PoseWatchdog.hpp
)

optional_init(velodyne_lidar-proxies
    SOURCES
        VelodyneDriver.cpp
    HEADERS
        VelodyneDriver.hpp
)

optional_init(wbc-proxies
    SOURCES
        WholeBodyControl.cpp
    HEADERS
        WholeBodyControl.hpp
)
optional_init(waypoint_provider-proxies)

optional_init(tagger-proxies
    SOURCES
        LogTagger.cpp
    HEADERS
        LogTagger.hpp
)

optional_init(dcdl-proxies
    SOURCES
        DCDL.cpp
    HEADERS
        DCDL.hpp
)

rock_library(lib_init_optional
    SOURCES
        ${SRC_EXTRA}
    HEADERS
#         ${HDR_EXTRA}
    DEPS_PKGCONFIG
        lib_init
        ${PKG_CONFIG_EXTRA}
)

