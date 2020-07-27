#
# libgphoto2
#

# Library
add_library(gphoto2-mustek OBJECT core.h core.c image.h image.c io.h io.c mdc800.c mdc800_spec.h print.h rs232.h rs232.c usb.h usb.c)
target_link_libraries(gphoto2-mustek gphoto2-camlib)
set_target_properties(gphoto2-mustek PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-mustek)
