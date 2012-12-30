OPTION (BUILD_CLIENT "Build the Client app" ON)
MESSAGE (STATUS "===== Saetta ZMQ Client =====")
IF (BUILD_CLIENT)
	SET (CLIENT_PATH "srcClient")
	SET (CLIENT_SRCS ${PROJECT_SOURCE_DIR}/${CLIENT_PATH}/clientmain.cpp)
	SET (CLIENT_OUT SaettaClient)
	add_executable(
		${CLIENT_OUT} ${CLIENT_SRCS}
	)
#	add_custom_target(
#		${CLIENT_OUT} ALL
#		DEPENDS ${LIBRARY_OUTPUT_PATH}/libzmqcpp.a
#		SOURCES ${CLIENT_SRCS}
#	)
	target_link_libraries(${CLIENT_OUT} zmqcpp protobuf saettamsgs ${ZMQ_LIB} zmq)
	link_directories(${PROJECT_SOURCE_DIR}/objs)
ELSE (BUILD_CLIENT)
    MESSAGE (STATUS "Disabled by user. Use ccmake to enable.")
ENDIF (BUILD_CLIENT)
MESSAGE (STATUS "=============================")
