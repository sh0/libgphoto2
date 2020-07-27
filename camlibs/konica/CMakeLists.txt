#
# libgphoto2
#

# Library
add_library(gphoto2-konica OBJECT konica.h konica.c library.c lowlevel.h lowlevel.c)
target_compile_options(gphoto2-konica PRIVATE -DLOCALIZATION="${CMAKE_INSTALL_FULL_DATADIR}/${PROJECT_NAME}/konica")
target_link_libraries(gphoto2-konica gphoto2-camlib)
set_target_properties(gphoto2-konica PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-konica)
