#
# libgphoto2
#

# Library
add_library(gphoto2-casio OBJECT
    cam2jpgtab.h camtojpeg.h camtojpeg.c
    casio-qv-commands.h casio-qv-commands.c casio-qv.c
    jpegtab_f.h ycctoppm.h ycctoppm.c
)
target_link_libraries(gphoto2-casio gphoto2-camlib)
set_target_properties(gphoto2-casio PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-casio)
