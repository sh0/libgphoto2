#
# libgphoto2
#

# Library
add_library(gphoto2-hp215 OBJECT crctab.h hp215.h hp215.c)
target_link_libraries(gphoto2-hp215 gphoto2-camlib)
set_target_properties(gphoto2-hp215 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-hp215)
