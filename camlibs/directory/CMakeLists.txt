#
# libgphoto2
#

# Library
add_library(gphoto2-directory OBJECT directory.c)
target_link_libraries(gphoto2-directory gphoto2-camlib ${LIBEXIF_TARGET})
set_target_properties(gphoto2-directory PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-directory)
