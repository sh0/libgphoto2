#
# libgphoto2
#

# Library
add_library(gphoto2-konica-qm150 OBJECT qm150.c)
target_link_libraries(gphoto2-konica-qm150 gphoto2-camlib ${LIBEXIF_TARGET})
set_target_properties(gphoto2-konica-qm150 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-konica-qm150)
