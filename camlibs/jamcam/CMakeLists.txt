#
# libgphoto2
#

# Library
add_library(gphoto2-jamcam OBJECT jamcam.c library.h library.c)
target_link_libraries(gphoto2-jamcam gphoto2-camlib)
set_target_properties(gphoto2-jamcam PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-jamcam)
