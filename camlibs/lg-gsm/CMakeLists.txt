#
# libgphoto2
#

# Library
add_library(gphoto2-lg-gsm OBJECT lg_gsm.h lg_gsm.c library.c)
target_link_libraries(gphoto2-lg-gsm gphoto2-camlib)
set_target_properties(gphoto2-lg-gsm PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-lg-gsm)
