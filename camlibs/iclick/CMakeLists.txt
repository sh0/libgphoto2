#
# libgphoto2
#

# Library
add_library(gphoto2-iclick OBJECT iclick.h iclick.c library.c)
target_link_libraries(gphoto2-iclick gphoto2-camlib)
set_target_properties(gphoto2-iclick PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-iclick)
