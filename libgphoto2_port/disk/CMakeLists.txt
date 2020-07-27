#
# libgphoto2
#

# Library
add_library(gphoto2-port-disk OBJECT disk.c)
target_link_libraries(gphoto2-port-disk gphoto2-iolib)
set_target_properties(gphoto2-port-disk PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
