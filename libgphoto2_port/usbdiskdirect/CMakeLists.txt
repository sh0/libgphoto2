#
# libgphoto2
#

# Library
add_library(gphoto2-port-usbdiskdirect OBJECT usbdiskdirect.c)
target_link_libraries(gphoto2-port-usbdiskdirect gphoto2-iolib)
set_target_properties(gphoto2-port-usbdiskdirect PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
