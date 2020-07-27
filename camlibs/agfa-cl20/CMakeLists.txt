#
# libgphoto2
#

# Library
add_library(gphoto2-agfa-cl20 OBJECT agfa_cl20.c)
target_link_libraries(gphoto2-agfa-cl20 gphoto2-camlib)
set_target_properties(gphoto2-agfa-cl20 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-agfa-cl20)
