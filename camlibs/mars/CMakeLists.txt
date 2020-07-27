#
# libgphoto2
#

# Library
add_library(gphoto2-mars OBJECT mars.h mars.c library.c)
target_link_libraries(gphoto2-mars gphoto2-camlib)
set_target_properties(gphoto2-mars PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-mars)
