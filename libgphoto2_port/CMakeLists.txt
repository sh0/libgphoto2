#
# libgphoto2
#

# Interface library
add_library(gphoto2-iolib INTERFACE)
target_include_directories(gphoto2-iolib BEFORE
    INTERFACE "${PROJECT_SOURCE_DIR}"
    INTERFACE "${PROJECT_SOURCE_DIR}/libgphoto2_port"
    INTERFACE "${PROJECT_SOURCE_DIR}/libgphoto2"
    INTERFACE "${CMAKE_BINARY_DIR}"
)
target_compile_options(gphoto2-iolib INTERFACE -D_GPHOTO2_INTERNAL_CODE)

# List plugins
if (BUILD_PORT_DISK)
    set(LIBGPHOTO2_PORT_PLUGINS ${LIBGPHOTO2_PORT_PLUGINS} disk)
endif ()
if (BUILD_PORT_PTPIP)
    set(LIBGPHOTO2_PORT_PLUGINS ${LIBGPHOTO2_PORT_PLUGINS} ptpip)
endif ()
if (BUILD_PORT_SERIAL)
    set(LIBGPHOTO2_PORT_PLUGINS ${LIBGPHOTO2_PORT_PLUGINS} serial)
endif ()
if (BUILD_PORT_LIBUSB1)
    set(LIBGPHOTO2_PORT_PLUGINS ${LIBGPHOTO2_PORT_PLUGINS} libusb1)
endif ()
if (BUILD_PORT_RAWUSB)
    set(LIBGPHOTO2_PORT_PLUGINS ${LIBGPHOTO2_PORT_PLUGINS} rawusb)
endif ()
if (BUILD_PORT_USBDISKDIRECT)
    set(LIBGPHOTO2_PORT_PLUGINS ${LIBGPHOTO2_PORT_PLUGINS} usbdiskdirect)
endif ()
if (BUILD_PORT_USBSCSI)
    set(LIBGPHOTO2_PORT_PLUGINS ${LIBGPHOTO2_PORT_PLUGINS} usbscsi)
endif ()

# Add plugins
foreach (LIBGPHOTO2_PORT_PLUGIN ${LIBGPHOTO2_PORT_PLUGINS})
    add_subdirectory(${LIBGPHOTO2_PORT_PLUGIN})
endforeach ()

# Libraries
add_subdirectory(libgphoto2_port)

# Export list of plugins
set(LIBGPHOTO2_PORT_PLUGINS ${LIBGPHOTO2_PORT_PLUGINS} PARENT_SCOPE)
