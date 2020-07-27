#
# libgphoto2
#

# Library
add_library(gphoto2-largan-lmini OBJECT largan.c lmini.h lmini.c lmini_ccd.h lmini_ccd.c)
target_link_libraries(gphoto2-largan-lmini gphoto2-camlib)
set_target_properties(gphoto2-largan-lmini PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-largan-lmini)
