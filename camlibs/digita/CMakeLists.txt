#
# libgphoto2
#

# Library
add_library(gphoto2-digita OBJECT commands.c digita.h digita.c serial.c usb.c)
target_link_libraries(gphoto2-digita gphoto2-camlib)
set_target_properties(gphoto2-digita PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-digita)
