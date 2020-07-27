#
# libgphoto2
#

# Library
add_library(gphoto2-toshiba-pdrm11 OBJECT library.c pdrm11.h pdrm11.c)
target_link_libraries(gphoto2-toshiba-pdrm11 gphoto2-camlib)
set_target_properties(gphoto2-toshiba-pdrm11 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-toshiba-pdrm11)
