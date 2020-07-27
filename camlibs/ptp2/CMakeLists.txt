#
# libgphoto2
#

# Library
add_library(gphoto2-ptp2 OBJECT
    chdk.c chdk_live_view.h chdk_ptp.h
    config.c device-flags.h library.c music-players.h
    olympus-wrap.c olympus-wrap.h
    ptp-bugs.h ptp-private.h ptp.c ptp.h ptpip.c
    usb.c
)
target_link_libraries(gphoto2-ptp2 gphoto2-camlib ${ICONV_TARGET} ${LIBXML2_TARGET} ${LIBJPEG_TARGET})
set_target_properties(gphoto2-ptp2 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-ptp2)
