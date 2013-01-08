OPTION (BUILD_SERVER "Build the Server app" ON)
MESSAGE (STATUS "===== Saetta ZMQ Server =====")
IF (BUILD_SERVER)
        MESSAGE(STATUS)
        FIND_PACKAGE (Threads QUIET)
        MESSAGE(STATUS)
        IF (THREADS_FOUND)

		SET (SERVER_PATH "srcServer")
		SET (SERVER_SRCS ${PROJECT_SOURCE_DIR}/${SERVER_PATH}/servermain.cpp)
		SET (SERVER_OUT SaettaServer)
		add_executable(
			${SERVER_OUT} ${SERVER_SRCS}
		)
	#	add_custom_target(
	#		${SERVER_OUT} ALL
	#		DEPENDS ${LIBRARY_OUTPUT_PATH}/libzmqcpp.a
	#		SOURCES ${SERVER_SRCS}
	#	)
		target_link_libraries(${SERVER_OUT} zmqcpp protobuf saettamsgs ${ZMQ_LIB} zmq pthread)
		link_directories(${PROJECT_SOURCE_DIR}/objs)
	ELSE (THREADS_FOUND)
		MESSAGE(STATUS "Required library Threads not found. Not building.")
	ENDIF (THREADS_FOUND)
ELSE (BUILD_SERVER)
    MESSAGE (STATUS "Disabled by user. Use ccmake to enable.")
ENDIF (BUILD_SERVER)
#MESSAGE (STATUS "=============================")
