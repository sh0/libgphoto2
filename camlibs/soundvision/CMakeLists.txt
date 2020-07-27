#
# libgphoto2
#

# Library
add_library(gphoto2-soundvision OBJECT agfa_cl18.c commands.h commands.c soundvision.h soundvision.c tiger_fastflicks.c)
target_link_libraries(gphoto2-soundvision gphoto2-camlib)
set_target_properties(gphoto2-soundvision PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-soundvision)
