#
# libgphoto2
#

# Library
add_library(gphoto2-minolta-dimagev OBJECT capture.c data.c delete.c dimagev.h dimagev.c download.c info.c packet.c status.c upload.c util.c)
target_link_libraries(gphoto2-minolta-dimagev gphoto2-camlib)
set_target_properties(gphoto2-minolta-dimagev PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-minolta-dimagev)
