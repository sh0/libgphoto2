#
# libgphoto2
#

# Library
add_library(gphoto2-digigr8 OBJECT digi_postprocess.c digigr8.h digigr8.c library.c)
target_link_libraries(gphoto2-digigr8 gphoto2-camlib)
set_target_properties(gphoto2-digigr8 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-digigr8)
