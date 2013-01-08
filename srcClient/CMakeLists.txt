OPTION (BUILD_CLIENT "Build the Client app" ON)
MESSAGE (STATUS "===== Saetta ZMQ Client =====")
IF (BUILD_CLIENT)
	MESSAGE(STATUS)
	FIND_PACKAGE (Threads REQUIRED)
	MESSAGE(STATUS)
	IF (THREADS_FOUND)
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
		target_link_libraries(${CLIENT_OUT} zmqcpp protobuf saettamsgs ${ZMQ_LIB} zmq pthread)
		link_directories(${PROJECT_SOURCE_DIR}/objs)
	ELSE (THREADS_FOUND)
		MESSAGE(STATUS "Required library Threads not found. Not building.")
	ENDIF(THREADS_FOUND)
ELSE (BUILD_CLIENT)
    MESSAGE (STATUS "Disabled by user. Use ccmake to enable.")
ENDIF (BUILD_CLIENT)
MESSAGE (STATUS "=============================")
