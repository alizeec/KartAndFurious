# Install script for directory: /home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code

# Set the install prefix
IF(NOT DEFINED CMAKE_INSTALL_PREFIX)
  SET(CMAKE_INSTALL_PREFIX "/usr/local")
ENDIF(NOT DEFINED CMAKE_INSTALL_PREFIX)
STRING(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
IF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  IF(BUILD_TYPE)
    STRING(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  ELSE(BUILD_TYPE)
    SET(CMAKE_INSTALL_CONFIG_NAME "")
  ENDIF(BUILD_TYPE)
  MESSAGE(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
ENDIF(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)

# Set the component getting installed.
IF(NOT CMAKE_INSTALL_COMPONENT)
  IF(COMPONENT)
    MESSAGE(STATUS "Install component: \"${COMPONENT}\"")
    SET(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  ELSE(COMPONENT)
    SET(CMAKE_INSTALL_COMPONENT)
  ENDIF(COMPONENT)
ENDIF(NOT CMAKE_INSTALL_COMPONENT)

# Install shared libraries without execute permission?
IF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  SET(CMAKE_INSTALL_SO_NO_EXE "1")
ENDIF(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libassimp3.0-r1264")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE STATIC_LIBRARY FILES "/home/marion/Documents/KartAndFurious/build/third-party/assimp--3.0.1270/code/libassimp.a")
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libassimp3.0-r1264")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libassimp3.0-r1264-dev")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp" TYPE FILE FILES
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/anim.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/ai_assert.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/camera.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/color4.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/color4.inl"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/config.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/defs.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/cfileio.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/light.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/material.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/material.inl"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/matrix3x3.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/matrix3x3.inl"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/matrix4x4.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/matrix4x4.inl"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/mesh.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/postprocess.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/quaternion.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/quaternion.inl"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/scene.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/texture.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/types.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/vector2.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/vector2.inl"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/vector3.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/vector3.inl"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/version.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/cimport.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/importerdesc.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/Importer.hpp"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/DefaultLogger.hpp"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/ProgressHandler.hpp"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/IOStream.hpp"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/IOSystem.hpp"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/Logger.hpp"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/LogStream.hpp"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/NullLogger.hpp"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/cexport.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/Exporter.hpp"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libassimp3.0-r1264-dev")

IF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libassimp3.0-r1264-dev")
  FILE(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/assimp/Compiler" TYPE FILE FILES
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/Compiler/pushpack1.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/../include/assimp/Compiler/poppack1.h"
    "/home/marion/Documents/KartAndFurious/third-party/assimp--3.0.1270/code/pstdint.h"
    )
ENDIF(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "libassimp3.0-r1264-dev")

