#
# libgphoto2
#

# Library
add_library(gphoto2-port-usbscsi OBJECT usbscsi.c)
target_link_libraries(gphoto2-port-usbscsi gphoto2-iolib)
set_target_properties(gphoto2-port-usbscsi PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
