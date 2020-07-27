#
# libgphoto2
#

# Library
add_library(gphoto2-st2205 OBJECT library.c st2205.h st2205.c st2205_decode.c st2205_tables.c)
target_link_libraries(gphoto2-st2205 gphoto2-camlib ${ICONV_TARGET})
set_target_properties(gphoto2-st2205 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-st2205)
