#
# libgphoto2
#

# Library
add_library(gphoto2-lumix OBJECT lumix.c)
target_link_libraries(gphoto2-lumix gphoto2-camlib ${LIBXML2_TARGET} ${CURL_TARGET})
set_target_properties(gphoto2-lumix PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-lumix)
