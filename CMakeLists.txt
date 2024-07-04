cmake_minimum_required(VERSION 3.22)
project(SnorlaxProtocol C)
include(ExternalProject)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS_RELEASE "${CMAKE_C_FLAGS_RELEASE} -DSNORLAX_DEBUG")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DSNORLAX_DEBUG")

include_directories(src include)

message(${CMAKE_CURRENT_SOURCE_DIR})

ExternalProject_Add(snorlax-std
    PREFIX          "${PROJECT_SOURCE_DIR}/lib/snorlax/std"
    TMP_DIR         "${PROJECT_SOURCE_DIR}/lib/snorlax/std/tmp"
    STAMP_DIR       "${PROJECT_SOURCE_DIR}/lib/snorlax/std/stamp"
    DOWNLOAD_DIR    "${PROJECT_SOURCE_DIR}/lib/snorlax/std/src"
    SOURCE_DIR      "${PROJECT_SOURCE_DIR}/lib/snorlax/std/src"
    BINARY_DIR      "${PROJECT_SOURCE_DIR}/lib/snorlax/std/build"
    INSTALL_DIR     "${PROJECT_SOURCE_DIR}/lib/snorlax/std/install"
    LOG_DIR         "${PROJECT_SOURCE_DIR}/lib/snorlax/std/log"
    GIT_REPOSITORY  git@github.com:SnorlaxBio/std.git
    GIT_TAG         main
    GIT_REMOTE_NAME origin
    CONFIGURE_COMMAND ${CMAKE_COMMAND} -DCMAKE_BUILD_TYPE=Debug
                                       -S "${PROJECT_SOURCE_DIR}/lib/snorlax/std/src"
                                       -B "${PROJECT_SOURCE_DIR}/lib/snorlax/std/build"
                                       --install-prefix ${PROJECT_SOURCE_DIR}
    BUILD_COMMAND     ${CMAKE_COMMAND} --build "${PROJECT_SOURCE_DIR}/lib/snorlax/std/build"
                                       --target all)

link_directories(${PROJECT_SOURCE_DIR}/lib ${PROJECT_SOURCE_DIR}/build)

set(SNORLAX_PROTOCOL_SOURCE                             src/snorlax/protocol.c)
set(SNORLAX_PROTOCOL_HEADER                             src/snorlax/protocol.h)
set(SNORLAX_PROTOCOL_ETHERNET_SOURCE                    src/snorlax/protocol/ethernet.c)
set(SNORLAX_PROTOCOL_ETHERNET_HEADER                    src/snorlax/protocol/ethernet.h)
set(SNORLAX_PROTOCOL_INTERNET_VERSION4_SOURCE           src/snorlax/protocol/internet/version4.c)
set(SNORLAX_PROTOCOL_INTERNET_VERSION4_HEADER           src/snorlax/protocol/internet/version4.h)
set(SNORLAX_PROTOCOL_INTERNET_VERSION6_SOURCE           src/snorlax/protocol/internet/version6.c)
set(SNORLAX_PROTOCOL_INTERNET_VERSION6_HEADER           src/snorlax/protocol/internet/version6.h)
set(SNORLAX_PROTOCOL_INTERNET_SOURCE                    src/snorlax/protocol/internet.c)
set(SNORLAX_PROTOCOL_INTERNET_HEADER                    src/snorlax/protocol/internet.h)
set(SNORLAX_PROTOCOL_INTERNET_CONTROL_MESSAGE_SOURCE    src/snorlax/protocol/internet/control-message.c)
set(SNORLAX_PROTOCOL_INTERNET_CONTROL_MESSAGE_HEADER    src/snorlax/protocol/internet/control-message.h)
set(SNORLAX_PROTOCOL_TRANSMISSION_CONTROL_SOURCE        src/snorlax/protocol/transmission-control.c)
set(SNORLAX_PROTOCOL_TRANSMISSION_CONTROL_HEADER        src/snorlax/protocol/transmission-control.h)
set(SNORLAX_PROTOCOL_USER_DATAGRAM_SOURCE               src/snorlax/protocol/user-datagram.c)
set(SNORLAX_PROTOCOL_USER_DATAGRAM_HEADER               src/snorlax/protocol/user-datagram.h)

add_library(snorlax-protocol-ethernet ${SNORLAX_PROTOCOL_ETHERNET_SOURCE} ${SNORLAX_PROTOCOL_ETHERNET_HEADER})
target_compile_options(snorlax-protocol-ethernet PUBLIC "-ffile-prefix-map=${CMAKE_SOURCE_DIR}=.")

add_library(snorlax-protocol-internet ${SNORLAX_PROTOCOL_INTERNET_SOURCE} ${SNORLAX_PROTOCOL_INTERNET_HEADER})
target_compile_options(snorlax-protocol-internet PUBLIC "-ffile-prefix-map=${CMAKE_SOURCE_DIR}=.")

add_library(snorlax-protocol-internet-version4 ${SNORLAX_PROTOCOL_INTERNET_VERSION4_SOURCE} ${SNORLAX_PROTOCOL_INTERNET_VERSION4_HEADER})
target_compile_options(snorlax-protocol-internet-version4 PUBLIC "-ffile-prefix-map=${CMAKE_SOURCE_DIR}=.")

add_library(snorlax-protocol-internet-version6 ${SNORLAX_PROTOCOL_INTERNET_VERSION6_SOURCE} ${SNORLAX_PROTOCOL_INTERNET_VERSION6_HEADER})
target_compile_options(snorlax-protocol-internet-version6 PUBLIC "-ffile-prefix-map=${CMAKE_SOURCE_DIR}=.")

add_library(snorlax-protocol-internet-control-message ${SNORLAX_PROTOCOL_INTERNET_CONTROL_MESSAGE_SOURCE} ${SNORLAX_PROTOCOL_INTERNET_CONTROL_MESSAGE_HEADER})
target_compile_options(snorlax-protocol-internet-control-message PUBLIC "-ffile-prefix-map=${CMAKE_SOURCE_DIR}=.")

add_library(snorlax-protocol-transmission-control ${SNORLAX_PROTOCOL_TRANSMISSION_CONTROL_SOURCE} ${SNORLAX_PROTOCOL_TRANSMISSION_CONTROL_HEADER})
target_compile_options(snorlax-protocol-transmission-control PUBLIC "-ffile-prefix-map=${CMAKE_SOURCE_DIR}=.")

add_library(snorlax-protocol-user-datagram ${SNORLAX_PROTOCOL_USER_DATAGRAM_SOURCE} ${SNORLAX_PROTOCOL_USER_DATAGRAM_HEADER})
target_compile_options(snorlax-protocol-user-datagram PUBLIC "-ffile-prefix-map=${CMAKE_SOURCE_DIR}=.")

add_library(snorlax-protocol ${SNORLAX_PROTOCOL_SOURCE} ${SNORLAX_PROTOCOL_HEADER})
target_compile_options(snorlax-protocol PUBLIC "-ffile-prefix-map=${CMAKE_SOURCE_DIR}=.")
target_link_libraries(snorlax-protocol      snorlax-protocol-user-datagram
                                            snorlax-protocol-transmission-control
                                            snorlax-protocol-internet-control-message
                                            snorlax-protocol-internet-version6
                                            snorlax-protocol-internet-version4
                                            snorlax-protocol-internet
                                            snorlax-protocol-ethernet)

