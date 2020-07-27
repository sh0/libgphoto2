#
# libgphoto2
#

# Library
add_library(gphoto2-sonix OBJECT library.c sakar-avi-header.h sonix.h sonix.c)
target_link_libraries(gphoto2-sonix gphoto2-camlib)
set_target_properties(gphoto2-sonix PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-sonix)
