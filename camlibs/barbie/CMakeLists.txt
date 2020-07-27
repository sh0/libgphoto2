#
# libgphoto2
#

# Library
add_library(gphoto2-barbie OBJECT barbie.c)
target_link_libraries(gphoto2-barbie gphoto2-camlib)
set_target_properties(gphoto2-barbie PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-barbie)
