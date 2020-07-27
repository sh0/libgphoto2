#
# libgphoto2
#

# Library
add_library(gphoto2-jl2005c OBJECT
    img_enhance.h img_enhance.c
    jl2005bcd_decompress.h jl2005bcd_decompress.c
    jl2005c.h jl2005c.c
    jpeg_memsrcdest.h jpeg_memsrcdest.c
    library.c
)
target_link_libraries(gphoto2-jl2005c gphoto2-camlib ${LIBJPEG_TARGET})
set_target_properties(gphoto2-jl2005c PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-jl2005c)
