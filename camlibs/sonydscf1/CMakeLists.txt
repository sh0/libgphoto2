#
# libgphoto2
#

# Library
add_library(gphoto2-sonydscf1 OBJECT command.h command.c pmp.h sonydscf1.c)
target_link_libraries(gphoto2-sonydscf1 gphoto2-camlib)
set_target_properties(gphoto2-sonydscf1 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-sonydscf1)
