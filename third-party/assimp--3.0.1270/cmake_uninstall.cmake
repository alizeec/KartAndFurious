IF(NOT EXISTS "/home/l-naej/IMAC2/FatAndFurious/third-party/assimp--3.0.1270/install_manifest.txt")
    MESSAGE(FATAL_ERROR "Cannot find install manifest: \"/home/l-naej/IMAC2/FatAndFurious/third-party/assimp--3.0.1270/install_manifest.txt\"")
ENDIF()

FILE(READ "/home/l-naej/IMAC2/FatAndFurious/third-party/assimp--3.0.1270/install_manifest.txt" files)
STRING(REGEX REPLACE "\n" ";" files "${files}")

FOREACH(file ${files})
    MESSAGE(STATUS "Uninstalling \"${file}\"")
    IF(EXISTS "${file}")
        EXECUTE_PROCESS(
            COMMAND /usr/bin/cmake -E remove "$ENV{DESTDIR}${file}"
            OUTPUT_VARIABLE rm_out
            RESULT_VARIABLE rm_retval
        )
        IF(NOT "${rm_retval}" STREQUAL 0)
            MESSAGE(FATAL_ERROR "Problem when removing \"${file}\"")
        ENDIF()
    ELSEIF(IS_SYMLINK "${file}")
        EXEC_PROGRAM(
            "/usr/bin/cmake" ARGS "-E remove \"${file}\""
            OUTPUT_VARIABLE rm_out
            RETURN_VALUE rm_retval
            )
        IF(NOT "${rm_retval}" STREQUAL 0)
            MESSAGE(FATAL_ERROR "Problem when removing \"${file}\"")
        ENDIF()
    ELSE()
        MESSAGE(STATUS "File \"${file}\" does not exist.")
    ENDIF()
ENDFOREACH()