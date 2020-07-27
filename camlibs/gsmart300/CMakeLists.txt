#
# libgphoto2
#

# Library
add_library(gphoto2-gsmart300 OBJECT gsmart300-jpeg-header.h gsmart300.h gsmart300.c library.c)
target_link_libraries(gphoto2-gsmart300 gphoto2-camlib)
set_target_properties(gphoto2-gsmart300 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-gsmart300)
