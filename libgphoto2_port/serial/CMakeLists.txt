#
# libgphoto2
#

# Library
add_library(gphoto2-port-serial OBJECT serial.c)
target_link_libraries(gphoto2-port-serial gphoto2-iolib)
set_target_properties(gphoto2-port-serial PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
