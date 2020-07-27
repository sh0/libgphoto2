#
# libgphoto2
#

# Library
add_library(gphoto2-canon OBJECT canon.h canon.c crc.h crc.c library.h library.c serial.h serial.c usb.h usb.c util.h util.c)
target_link_libraries(gphoto2-canon gphoto2-camlib ${LIBEXIF_TARGET})
set_target_properties(gphoto2-canon PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-canon)
