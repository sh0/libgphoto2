#
# libgphoto2
#

# Library
add_library(gphoto2-polaroid-pdc320 OBJECT pdc320.h pdc320.c)
target_link_libraries(gphoto2-polaroid-pdc320 gphoto2-camlib)
set_target_properties(gphoto2-polaroid-pdc320 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-polaroid-pdc320)
