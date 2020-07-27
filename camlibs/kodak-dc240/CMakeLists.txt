#
# libgphoto2
#

# Library
add_library(gphoto2-kodak-dc240 OBJECT dc240.h dc240.c library.h library.c)
target_link_libraries(gphoto2-kodak-dc240 gphoto2-camlib)
set_target_properties(gphoto2-kodak-dc240 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-kodak-dc240)
