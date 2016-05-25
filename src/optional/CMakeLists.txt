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

optional_init(mars-proxies
    SOURCES
        SimCameraDriver.cpp
        SimIMUDriver.cpp
        SimJointDriver.cpp
        Simulator.cpp
        SimVelodyneDriver.cpp
    HEADERS
        SimCameraDriver.hpp
        SimIMUDriver.hpp
        SimJointDriver.hpp
        Simulator.hpp
        SimVelodyneDriver.hpp
)

optional_init(odometry-proxies
    SOURCES
        SkidOdometry.cpp
    HEADERS
        SkidOdometry.hpp
)

optional_init(velodyne_lidar-proxies
    SOURCES
        VelodyneDriver.cpp
    HEADERS
        VelodyneDriver.hpp
)

optional_init(ndlcom_device_driver-proxies
    SOURCES
        NDLComJointDriver.cpp
    HEADERS
        NDLComJointDriver.hpp
)


optional_init(serial_ndlcom-proxies
    SOURCES
        NDLComSerial.cpp
    HEADERS
        NDLComSerial.hpp
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