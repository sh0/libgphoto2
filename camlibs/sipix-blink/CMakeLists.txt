#
# libgphoto2
#

# Library
add_library(gphoto2-sipix-blink OBJECT blink.c)
target_link_libraries(gphoto2-sipix-blink gphoto2-camlib)
set_target_properties(gphoto2-sipix-blink PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-sipix-blink)
