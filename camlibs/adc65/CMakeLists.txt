#
# libgphoto2
#

# Library
add_library(gphoto2-adc65 OBJECT adc65.c)
target_link_libraries(gphoto2-adc65 gphoto2-camlib)
set_target_properties(gphoto2-adc65 PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-adc65)
