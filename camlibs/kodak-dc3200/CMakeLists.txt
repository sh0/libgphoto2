#
# libgphoto2
#

# Library
add_library(gphoto2-kodak-dc3200 OBJECT dc3200.h dc3200.c library.h library.c)
target_link_libraries(gphoto2-kodak-dc3200 gphoto2-camlib)
set_target_properties(gphoto2-kodak-dc3200 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-kodak-dc3200)
