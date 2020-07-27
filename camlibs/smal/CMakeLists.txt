#
# libgphoto2
#

# Library
add_library(gphoto2-smal OBJECT smal.h smal.c ultrapocket.h ultrapocket.c)
target_link_libraries(gphoto2-smal gphoto2-camlib)
set_target_properties(gphoto2-smal PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-smal)
