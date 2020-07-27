#
# libgphoto2
#

# Library
add_library(gphoto2-ax203 OBJECT
    ax203.h ax203.c ax203_compress_jpeg.c ax203_decode_yuv.c ax203_decode_yuv_delta.c
    jidctflt.c jpeg_memsrcdest.h jpeg_memsrcdest.c library.c
    tinyjpeg-internal.h tinyjpeg.h tinyjpeg.c
)
target_link_libraries(gphoto2-ax203 gphoto2-camlib ${LIBGD_TARGET} ${LIBJPEG_TARGET})
set_target_properties(gphoto2-ax203 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-ax203)
