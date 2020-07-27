#
# libgphoto2
#

# Configuration
set(GETTEXT_PACKAGE "${PROJECT_NAME}_port")
set(GETTEXT_LOCALEDIR "${CMAKE_INSTALL_FULL_LOCALEDIR}/${PROJECT_NAME}")
set(PACKAGE_VERSION "${CMAKE_PROJECT_VERSION}")
if (Intl_FOUND)
    set(ENABLE_NLS TRUE)
endif ()
configure_file("gphoto2-port-config.h.in" "${CMAKE_BINARY_DIR}/gphoto2-port-config.h")

# Sources
set(LIBGPHOTO2_PORT_HEADERS
    ../gphoto2/gphoto2-port.h
    ../gphoto2/gphoto2-port-info.h
    ../gphoto2/gphoto2-port-info-list.h
    ../gphoto2/gphoto2-port-library.h
    ../gphoto2/gphoto2-port-log.h
    ../gphoto2/gphoto2-port-portability.h
    ../gphoto2/gphoto2-port-result.h
    ../gphoto2/gphoto2-port-version.h
)
set(LIBGPHOTO2_PORT_SOURCES
    gphoto2-port-info-list.c
    gphoto2-port-library.c
    gphoto2-port-log.c
    gphoto2-port-version.c
    gphoto2-port.c
    gphoto2-port-portability.c
    gphoto2-port-result.c
)

# Library target setup
function(libgphoto2_port_setup TARGET)
    # Includes
    target_include_directories(${TARGET}
        PUBLIC "${PROJECT_SOURCE_DIR}/libgphoto2_port"
        PUBLIC "${CMAKE_BINARY_DIR}"
    )

    # Flags
    target_compile_options(${TARGET} PRIVATE -D_GPHOTO2_INTERNAL_CODE)
    set_target_properties(${TARGET} PROPERTIES
        OUTPUT_NAME ${BUILD_LIBGPHOTO2_PORT_NAME}
        C_STANDARD 11
    )
    set_compiler_settings(${TARGET})

    # Libraries
    if (INTL_FOUND)
        target_link_libraries(${TARGET} ${INTL_TARGET})
    endif ()
    if (LIBUSB_FOUND)
        target_link_libraries(${TARGET} ${LIBUSB_TARGET})
    endif ()
    if (LOCKDEV_FOUND)
        target_link_libraries(${TARGET} ${LOCKDEV_TARGET})
    endif ()
    foreach (LIBGPHOTO2_PORT_PLUGIN ${LIBGPHOTO2_PORT_PLUGINS})
        target_link_libraries(${TARGET} $<TARGET_OBJECTS:gphoto2-port-${LIBGPHOTO2_PORT_PLUGIN}>)
        add_dependencies(${TARGET} gphoto2-port-${LIBGPHOTO2_PORT_PLUGIN})
    endforeach ()

    # Installation
    install(TARGETS ${TARGET})
endfunction()

# Shared library
if (BUILD_SHARED)
    add_library(gphoto2-port-shared SHARED ${LIBGPHOTO2_PORT_HEADERS} ${LIBGPHOTO2_PORT_SOURCES})
    libgphoto2_port_setup(gphoto2-port-shared)
endif ()

# Static library
if (BUILD_STATIC)
    add_library(gphoto2-port-static SHARED ${LIBGPHOTO2_PORT_HEADERS} ${LIBGPHOTO2_PORT_SOURCES})
    libgphoto2_port_setup(gphoto2-port-static)
endif ()

# Headers installation
install(DIRECTORY ../gphoto2 TYPE INCLUDE)
