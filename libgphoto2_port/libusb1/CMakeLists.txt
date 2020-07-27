#
# libgphoto2
#

# Library
add_library(gphoto2-port-libusb1 OBJECT libusb1.c)
target_link_libraries(gphoto2-port-libusb1 gphoto2-iolib)
set_target_properties(gphoto2-port-libusb1 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
target_link_libraries(gphoto2-port-libusb1 PkgConfig::LIBUSB)
