#
# libgphoto2
#

# Library
add_library(gphoto2-sx330z OBJECT library.c sx330z.h sx330z.c)
target_link_libraries(gphoto2-sx330z gphoto2-camlib)
set_target_properties(gphoto2-sx330z PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-sx330z)
