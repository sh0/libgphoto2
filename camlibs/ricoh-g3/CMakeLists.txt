#
# libgphoto2
#

# Library
add_library(gphoto2-ricoh-g3 OBJECT g3.c)
target_link_libraries(gphoto2-ricoh-g3 gphoto2-camlib)
set_target_properties(gphoto2-ricoh-g3 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-ricoh-g3)
