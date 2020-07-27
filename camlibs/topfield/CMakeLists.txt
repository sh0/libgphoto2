#
# libgphoto2
#

# Library
add_library(gphoto2-topfield OBJECT crc16.h crc16.c mjd.h mjd.c puppy.c tf_bytes.h tf_bytes.c usb_io.h usb_io.c)
target_link_libraries(gphoto2-topfield gphoto2-camlib ${ICONV_TARGET})
set_target_properties(gphoto2-topfield PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-topfield)
