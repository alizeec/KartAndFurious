# The set of languages for which implicit dependencies are needed:
SET(CMAKE_DEPENDS_LANGUAGES
  )
# The set of files for implicit dependencies of each language:

# Preprocessor definitions for this target.
SET(CMAKE_TARGET_DEFINITIONS
  "ASSIMP_BUILD_BOOST_WORKAROUND"
  "ASSIMP_BUILD_NO_OWN_ZLIB"
  "ENABLE_BOOST_WORKAROUND=ON"
  "GLEW_STATIC=1"
  )

# Targets to which this target links.
SET(CMAKE_TARGET_LINKED_INFO_FILES
  )

# The include file search paths:
SET(CMAKE_C_TARGET_INCLUDE_PATH
  "/usr/local/include"
  "third-party/glew-1.10.0/include"
  "third-party/assimp--3.0.1270/include"
  "third-party/assimp--3.0.1270/code/BoostWorkaround"
  )
SET(CMAKE_CXX_TARGET_INCLUDE_PATH ${CMAKE_C_TARGET_INCLUDE_PATH})
SET(CMAKE_Fortran_TARGET_INCLUDE_PATH ${CMAKE_C_TARGET_INCLUDE_PATH})
SET(CMAKE_ASM_TARGET_INCLUDE_PATH ${CMAKE_C_TARGET_INCLUDE_PATH})
