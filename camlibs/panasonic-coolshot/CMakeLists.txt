#
# libgphoto2
#

# Library
add_library(gphoto2-panasonic-coolshot OBJECT coolshot.c library.h library.c)
target_link_libraries(gphoto2-panasonic-coolshot gphoto2-camlib)
set_target_properties(gphoto2-panasonic-coolshot PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-panasonic-coolshot)
