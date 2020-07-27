#
# libgphoto2
#

# Library
add_library(gphoto2-clicksmart310 OBJECT clicksmart.h clicksmart.c library.c spca50x-jpeg-header.h)
target_link_libraries(gphoto2-clicksmart310 gphoto2-camlib)
set_target_properties(gphoto2-clicksmart310 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-clicksmart310)
