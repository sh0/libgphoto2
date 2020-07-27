#
# libgphoto2
#

# Library
add_library(gphoto2-sonydscf55 OBJECT camera.c nls.h sony.h sony.c)
target_link_libraries(gphoto2-sonydscf55 gphoto2-camlib)
set_target_properties(gphoto2-sonydscf55 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-sonydscf55)
