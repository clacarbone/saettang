cmake_minimum_required (VERSION 2.6)
SET ( CZMQ_FIND_REQUIRED TRUE )
SET ( ZEROMQ_FIND_REQUIRED TRUE )

# Set the build type.  Options are:
#  Coverage       : w/ debug symbols, w/o optimization, w/ code-coverage
#  Debug          : w/ debug symbols, w/o optimization
#  Release        : w/o debug symbols, w/ optimization
#  RelWithDebInfo : w/ debug symbols, w/ optimization
#  MinSizeRel     : w/o debug symbols, w/ optimization, stripped binaries
set(CMAKE_BUILD_TYPE Debug)
if (NOT CMAKE_BUILD_TYPE)
		message(STATUS "No build type selected, default to Release")
		set(CMAKE_BUILD_TYPE "Release")
endif()


# Set the project name (helps Visual Studio, mainly)
PROJECT (SaettaNG)
STRING (TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWER)
# Set the package version
set (SaettaZMQ_VERSION_MAJOR 0)
set (SaettaZMQ_VERSION_MINOR 1)
SET (SAETTAZMQ_VERSION 0.1.0 CACHE STRING "SaettaNG version")
SET (ZMQ_CPP_VERSION 0.1.0 CACHE STRING "ZMQ-CPP API version")
MESSAGE("")
MESSAGE ("     ${PROJECT_NAME} version ${SAETTAZMQ_VERSION}")

# Set where to find our internal CMake scripts
SET (SAETTANG_CMAKE_DIR ${PROJECT_SOURCE_DIR}/cmake CACHE PATH "Location of CMake scripts")
SET (CMAKE_C_FLAGS ${CMAKE_C_FLAGS} "-Wall -fpermissive")
SET (CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -fpermissive")
SET (CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_SOURCE_DIR}/../CMakeModules ${PROJECT_SOURCE_DIR}/CMakeModules)

#set paths
SET(EXECUTABLE_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/bin")
SET(LIBRARY_OUTPUT_PATH "${PROJECT_SOURCE_DIR}/lib")
SET(INC_MSGS "${PROJECT_SOURCE_DIR}/srcProtoBuf/")
SET(INC_ZMQCPP "${PROJECT_SOURCE_DIR}/srcZMQCpp")
SET(INC_SERVICE "${PROJECT_SOURCE_DIR}/srcService")

MESSAGE("     Checking required dependencies")
MESSAGE("")
#find_package (ZMQ REQUIRED)
include(FindProtobuf)
find_package(Protobuf REQUIRED)
#FIND_LIBRARY(ZMQ_LIB libzmq)
FIND_PACKAGE (DEPS REQUIRED)

link_directories(${LIBRARY_OUTPUT_PATH})

# Set the directories where include files can be found.
include_directories (include)
include_directories (${INC_MSGS})
include_directories (${INC_ZMQCPP})
include_directories (${INC_SERVICE})
include_directories(${PROTOBUF_INCLUDE_DIR})
include_directories(${ZMQ_INCLUDE_DIR})

MESSAGE("")
MESSAGE("     Selecting modules to build")
MESSAGE("")
ADD_SUBDIRECTORY ("srcProtoBuf")
ADD_SUBDIRECTORY ("srcZMQCpp")
ADD_SUBDIRECTORY ("srcClient")
ADD_SUBDIRECTORY ("srcServer")
MESSAGE (STATUS "")







IF(NOT CZMQ_FOUND)
MESSAGE(STATUS "CZMQ library missing.")
MESSAGE(STATUS "Please check http://czmq.zeromq.org")
ENDIF(NOT CZMQ_FOUND)
IF(NOT ZMQ_FOUND)
MESSAGE(STATUS "ZMQ library missing.")
MESSAGE(STATUS "Please check http://www.zeromq.org")
ENDIF(NOT ZMQ_FOUND)


#add_custom_target(base SOURCES ${PROJECT_SOURCE_DIR}src/base.cpp)
#add_custom_target(teleop_saetta SOURCES ${PROJECT_SOURCE_DIR}src/saetta_teleop.cpp)

#common commands for building c++ executables and libraries
#target_link_libraries(${PROJECT_NAME} another_library)
#target_link_libraries(base core serverWIFI)
#target_link_libraries(teleop_saetta joystick ${SDL_LIBRARY})

