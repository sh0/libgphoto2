#
# libgphoto2
#

# Library
add_library(gphoto2-aox OBJECT aox.h aox.c library.c)
target_link_libraries(gphoto2-aox gphoto2-camlib)
set_target_properties(gphoto2-aox PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-aox)
