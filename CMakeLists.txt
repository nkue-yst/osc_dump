### Setup cmake project ###
cmake_minimum_required(VERSION 3.10)
project(OSC_DUMP)

### Setup C++ project ###
enable_language(CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

### Setup oscpack ###
set(OSCPACK_DIR ${CMAKE_SOURCE_DIR}/thirdparty/oscpack)
include_directories(${OSCPACK_DIR})
add_library(oscpack
    ${OSCPACK_DIR}/ip/IpEndpointName.h
    ${OSCPACK_DIR}/ip/IpEndpointName.cpp
    ${OSCPACK_DIR}/ip/NetworkingUtils.h
    ${OSCPACK_DIR}/ip/posix/NetworkingUtils.cpp
    ${OSCPACK_DIR}/ip/UdpSocket.h
    ${OSCPACK_DIR}/ip/posix/UdpSocket.cpp
    ${OSCPACK_DIR}/ip/PacketListener.h
    ${OSCPACK_DIR}/ip/TimerListener.h
    ${OSCPACK_DIR}/osc/OscTypes.h
    ${OSCPACK_DIR}/osc/OscTypes.cpp 
    ${OSCPACK_DIR}/osc/OscHostEndianness.h
    ${OSCPACK_DIR}/osc/OscException.h
    ${OSCPACK_DIR}/osc/OscPacketListener.h
    ${OSCPACK_DIR}/osc/MessageMappingOscPacketListener.h
    ${OSCPACK_DIR}/osc/OscReceivedElements.h
    ${OSCPACK_DIR}/osc/OscReceivedElements.cpp
    ${OSCPACK_DIR}/osc/OscPrintReceivedElements.h
    ${OSCPACK_DIR}/osc/OscPrintReceivedElements.cpp
    ${OSCPACK_DIR}/osc/OscOutboundPacketStream.h
    ${OSCPACK_DIR}/osc/OscOutboundPacketStream.cpp
)

### Setup main project ###
add_executable(osc_dump src/osc_dump.cpp)
target_link_libraries(osc_dump oscpack)
