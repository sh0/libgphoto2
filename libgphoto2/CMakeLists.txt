#
# libgphoto2
#

# Configuration
set(GETTEXT_PACKAGE "${PROJECT_NAME}")
set(GETTEXT_LOCALEDIR "${CMAKE_INSTALL_FULL_LOCALEDIR}/${PROJECT_NAME}")
set(PACKAGE "${PROJECT_NAME}")
set(PACKAGE_VERSION "${CMAKE_PROJECT_VERSION}")
if (Intl_FOUND)
    set(ENABLE_NLS TRUE)
endif ()
configure_file("gphoto2-config.h.in" "${CMAKE_BINARY_DIR}/gphoto2-config.h")

# Sources
set(LIBGPHOTO2_HEADERS
    ../gphoto2/gphoto2-abilities.h
    ../gphoto2/gphoto2-abilities-list.h
    ../gphoto2/gphoto2-camera.h
    ../gphoto2/gphoto2-context.h
    ../gphoto2/gphoto2-endian.h
    ../gphoto2/gphoto2-file.h
    ../gphoto2/gphoto2-filesys.h
    ../gphoto2/gphoto2-library.h
    ../gphoto2/gphoto2-list.h
    ../gphoto2/gphoto2-result.h
    ../gphoto2/gphoto2-setting.h
    ../gphoto2/gphoto2-version.h
    ../gphoto2/gphoto2-widget.h
    ../gphoto2/gphoto2.h
)
set(LIBGPHOTO2_SOURCES
    ahd_bayer.c
    bayer.h
    bayer.c
    exif.h
    exif.c
    gamma.h
    gamma.c
    gphoto2-abilities-list.c
    gphoto2-camera.c
    gphoto2-context.c
    gphoto2-file.c
    gphoto2-filesys.c
    gphoto2-library.c
    gphoto2-list.c
    gphoto2-result.c
    gphoto2-setting.c
    gphoto2-version.c
    gphoto2-widget.c
    jpeg.h
    jpeg.c
)

# Library target setup
function(libgphoto2_setup TARGET)
    # Includes
    target_include_directories(${TARGET}
        PUBLIC "${PROJECT_SOURCE_DIR}"
        PUBLIC "${PROJECT_SOURCE_DIR}/libgphoto2_port"
        PUBLIC "${CMAKE_BINARY_DIR}"
    )

    # Flags
    target_compile_options(${TARGET} PRIVATE -D_GPHOTO2_INTERNAL_CODE)
    set_target_properties(${TARGET} PROPERTIES
        OUTPUT_NAME ${BUILD_LIBGPHOTO2_NAME}
        C_STANDARD 11
    )
    set_compiler_settings(${TARGET})

    # Libraries
    target_link_libraries(${TARGET} m)
    if (ICONV_FOUND)
        target_link_libraries(${TARGET} ${ICONV_TARGET})
    endif ()
    if (INTL_FOUND)
        target_link_libraries(${TARGET} ${INTL_TARGET})
    endif ()
    if (LIBXML2_FOUND)
        target_link_libraries(${TARGET} ${LIBXML2_TARGET})
    endif ()
    if (LIBEXIF_FOUND)
        target_link_libraries(${TARGET} ${LIBEXIF_TARGET})
    endif ()
    if (LIBJPEG_FOUND)
        target_link_libraries(${TARGET} ${LIBJPEG_TARGET})
    endif ()
    if (LIBGD_FOUND)
        target_link_libraries(${TARGET} ${LIBGD_TARGET})
    endif ()
    if (CURL_FOUND)
        target_link_libraries(${TARGET} ${CURL_TARGET})
    endif ()
    foreach (LIBGPHOTO2_CAMERA_PLUGIN ${LIBGPHOTO2_CAMERA_PLUGINS})
        target_link_libraries(${TARGET} $<TARGET_OBJECTS:gphoto2-${LIBGPHOTO2_CAMERA_PLUGIN}>)
        add_dependencies(${TARGET} gphoto2-${LIBGPHOTO2_CAMERA_PLUGIN})
    endforeach ()

    # Installation
    install(TARGETS ${TARGET})
endfunction()

# Shared library
if (BUILD_SHARED)
    add_library(gphoto2-shared SHARED ${LIBGPHOTO2_HEADERS} ${LIBGPHOTO2_SOURCES})
    libgphoto2_setup(gphoto2-shared)
endif ()

# Static library
if (BUILD_STATIC)
    add_library(gphoto2-static STATIC ${LIBGPHOTO2_HEADERS} ${LIBGPHOTO2_SOURCES})
    libgphoto2_setup(gphoto2-static)
endif ()

# Headers installation
install(DIRECTORY ../gphoto2 TYPE INCLUDE)
