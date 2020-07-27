#
# libgphoto2
#

# Library
add_library(gphoto2-ricoh OBJECT crctab.h library.c ricoh.h ricoh.c)
target_link_libraries(gphoto2-ricoh gphoto2-camlib)
set_target_properties(gphoto2-ricoh PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-ricoh)
