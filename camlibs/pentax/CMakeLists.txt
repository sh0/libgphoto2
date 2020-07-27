#
# libgphoto2
#

# Library
add_library(gphoto2-pentax OBJECT js0n.h js0n.c library.c pslr.h pslr.c pslr_enum.h pslr_enum.c pslr_lens.h pslr_lens.c pslr_model.h pslr_model.c pslr_scsi.h)
target_compile_options(gphoto2-pentax PRIVATE -DLIBGPHOTO2 -DPKTDATADIR=\"\")
target_link_libraries(gphoto2-pentax gphoto2-camlib)
set_target_properties(gphoto2-pentax PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-pentax)
