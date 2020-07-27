#
# libgphoto2
#

if (BUILD_TESTING)
    # Select shared or static libraries to link against
    if (BUILD_SHARED)
        set(TESTS_LIBGPHOTO2_TARGET gphoto2-shared gphoto2-port-shared)
    elseif (BUILD_STATIC)
        set(TESTS_LIBGPHOTO2_TARGET gphoto2-static gphoto2-port-static)
    else ()
        message(FATAL_ERROR "Please enable either BUILD_SHARED or BUILD_STATIC to build tests!")
    endif ()

    # Endianness test
    add_executable(gphoto2-tests-endian test-endian.c)
    target_link_libraries(gphoto2-tests-endian ${TESTS_LIBGPHOTO2_TARGET})
    set_target_properties(gphoto2-tests-endian PROPERTIES C_STANDARD 11)
    set_compiler_settings(gphoto2-tests-endian)

    # Version test
    add_executable(gphoto2-tests-version test-version.c)
    target_link_libraries(gphoto2-tests-version ${TESTS_LIBGPHOTO2_TARGET})
    set_target_properties(gphoto2-tests-version PROPERTIES C_STANDARD 11)
    set_compiler_settings(gphoto2-tests-version)

    # Basic functionality test
    add_executable(gphoto2-tests-gphoto2 test-gphoto2.c)
    target_link_libraries(gphoto2-tests-gphoto2 ${TESTS_LIBGPHOTO2_TARGET})
    set_target_properties(gphoto2-tests-gphoto2 PROPERTIES C_STANDARD 11)
    set_compiler_settings(gphoto2-tests-gphoto2)

    # Filesystem test
    add_executable(gphoto2-tests-filesys test-filesys.c)
    target_link_libraries(gphoto2-tests-filesys ${TESTS_LIBGPHOTO2_TARGET})
    set_target_properties(gphoto2-tests-filesys PROPERTIES C_STANDARD 11)
    set_compiler_settings(gphoto2-tests-filesys)

    # Camera list test
    add_executable(gphoto2-tests-camera-list test-camera-list.c)
    target_link_libraries(gphoto2-tests-camera-list ${TESTS_LIBGPHOTO2_TARGET})
    set_target_properties(gphoto2-tests-camera-list PROPERTIES C_STANDARD 11)
    set_compiler_settings(gphoto2-tests-camera-list)

endif ()
