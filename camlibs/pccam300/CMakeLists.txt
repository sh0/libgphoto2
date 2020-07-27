#
# libgphoto2
#

# Library
add_library(gphoto2-pccam300 OBJECT library.c pccam300.h pccam300.c)
target_link_libraries(gphoto2-pccam300 gphoto2-camlib)
set_target_properties(gphoto2-pccam300 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-pccam300)
