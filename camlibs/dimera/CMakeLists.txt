#
# libgphoto2
#

# Library
add_library(gphoto2-dimera OBJECT dimera3500.c dimeratab.h mesalib.h mesalib.c)
target_link_libraries(gphoto2-dimera gphoto2-camlib)
set_target_properties(gphoto2-dimera PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-dimera)
