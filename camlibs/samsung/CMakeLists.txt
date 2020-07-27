#
# libgphoto2
#

# Library
add_library(gphoto2-samsung OBJECT samsung.c)
target_link_libraries(gphoto2-samsung gphoto2-camlib)
set_target_properties(gphoto2-samsung PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-samsung)
