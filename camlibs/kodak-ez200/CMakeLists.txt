#
# libgphoto2
#

# Library
add_library(gphoto2-kodak-ez200 OBJECT ez200.c)
target_link_libraries(gphoto2-kodak-ez200 gphoto2-camlib)
set_target_properties(gphoto2-kodak-ez200 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-kodak-ez200)
