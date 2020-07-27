#
# libgphoto2
#

# Library
add_library(gphoto2-tp6801 OBJECT library.c tp6801.h tp6801.c)
target_link_libraries(gphoto2-tp6801 gphoto2-camlib ${LIBGD_TARGET})
set_target_properties(gphoto2-tp6801 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-tp6801)
