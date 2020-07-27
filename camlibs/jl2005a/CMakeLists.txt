#
# libgphoto2
#

# Library
add_library(gphoto2-jl2005a OBJECT jl2005a.h jl2005a.c library.c)
target_link_libraries(gphoto2-jl2005a gphoto2-camlib)
set_target_properties(gphoto2-jl2005a PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-jl2005a)
