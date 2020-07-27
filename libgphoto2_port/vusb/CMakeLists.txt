#
# libgphoto2
#

# Library
add_library(gphoto2-port-vusb OBJECT vcamera.h vcamera.c vusb.h vusb.c)
target_link_libraries(gphoto2-port-vusb gphoto2-iolib)
set_target_properties(gphoto2-port-vusb PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
target_link_libraries(gphoto2-port-vusb PkgConfig::LIBEXIF)
