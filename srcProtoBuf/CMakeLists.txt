OPTION (BUILD_MSGS "Build the PROTOBUF Messages" ON)
MESSAGE (STATUS "====== Saetta ZMQ Msg =======")
IF (BUILD_MSGS)
	SET (PROJECT_SRCS saetta.pb.cc)
	set (PROJECT_OBJECT saettamsgs)
	set(MSG_SOURCE "${PROJECT_SOURCE_DIR}/srcProtoBuf")
	EXECUTE_PROCESS(
		COMMAND protoc --cpp_out=${MSG_SOURCE} --proto_path=${MSG_SOURCE} ${MSG_SOURCE}/saetta.proto
	)

	add_library(${PROJECT_OBJECT} ${PROJECT_SRCS})
	link_directories(${PROJECT_SOURCE_DIR}/objs)
ELSE (BUILD_MSGS)
    MESSAGE (STATUS "Disabled by user. Use ccmake to enable.")
ENDIF (BUILD_MSGS)
MESSAGE (STATUS "=============================")
