OPTION (BUILD_ZMQCPP "Build the Helper Library" ON)
MESSAGE (STATUS "====== Saetta ZMQ Lib =======")
IF (BUILD_ZMQCPP)
	SET (PROJECT_SRCS zmqcpp)
	set (PROJECT_OBJECT zmqcpp)
	add_library(${PROJECT_OBJECT} ${PROJECT_SRCS})
	link_directories(${PROJECT_SOURCE_DIR}/objs)
ELSE (BUILD_ZMQCPP)
    MESSAGE (STATUS "Disabled by user. Use ccmake to enable.")
ENDIF (BUILD_ZMQCPP)
#MESSAGE (STATUS "=============================")




