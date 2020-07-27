#
# libgphoto2
#

# Library
add_library(gphoto2-spca50x OBJECT library.c
    spca50x-avi-header.h spca50x-flash.h spca50x-flash.c spca50x-jpeg-header.h
    spca50x-registers.h spca50x-sdram.h spca50x-sdram.c spca50x.h spca50x.c
)
target_link_libraries(gphoto2-spca50x gphoto2-camlib)
set_target_properties(gphoto2-spca50x PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-spca50x)
