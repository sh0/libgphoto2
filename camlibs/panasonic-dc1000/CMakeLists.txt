#
# libgphoto2
#

# Library
add_library(gphoto2-panasonic-dc1000 OBJECT dc.h dc.c dc1000.h dc1000.c)
target_link_libraries(gphoto2-panasonic-dc1000 gphoto2-camlib)
set_target_properties(gphoto2-panasonic-dc1000 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-panasonic-dc1000)
