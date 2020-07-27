#
# libgphoto2
#

# Library
add_library(gphoto2-stv0680 OBJECT
    bayer.h bayer.c
    demosaic_sharpen.h demosaic_sharpen.c
    library.h library.c
    saturate.h saturate.c
    sharpen.h sharpen.c
    stv0680.h stv0680.c)
target_link_libraries(gphoto2-stv0680 gphoto2-camlib)
set_target_properties(gphoto2-stv0680 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-stv0680)
