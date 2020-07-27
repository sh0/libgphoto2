#
# libgphoto2
#

# Library
add_library(gphoto2-fuji OBJECT fuji.h fuji.c library.c)
target_link_libraries(gphoto2-fuji gphoto2-camlib)
set_target_properties(gphoto2-fuji PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-fuji)
