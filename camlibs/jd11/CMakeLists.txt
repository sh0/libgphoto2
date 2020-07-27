#
# libgphoto2
#

# Library
add_library(gphoto2-jd11 OBJECT decomp.h decomp.c jd11.c serial.h serial.c)
target_link_libraries(gphoto2-jd11 gphoto2-camlib)
set_target_properties(gphoto2-jd11 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-jd11)
