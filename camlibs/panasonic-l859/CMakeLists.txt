#
# libgphoto2
#

# Library
add_library(gphoto2-panasonic-l859 OBJECT l859.h l859.c)
target_link_libraries(gphoto2-panasonic-l859 gphoto2-camlib)
set_target_properties(gphoto2-panasonic-l859 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-panasonic-l859)
