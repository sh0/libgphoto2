#
# libgphoto2
#

# Library
add_library(gphoto2-sierra OBJECT
    epson-desc.c library.h library.c
    nikon-desc.c olympus-desc.c
    sierra-desc.h sierra-desc.c sierra-usbwrap.h sierra-usbwrap.c sierra.h sierra.c
)
target_link_libraries(gphoto2-sierra gphoto2-camlib)
set_target_properties(gphoto2-sierra PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
set_compiler_settings(gphoto2-sierra)
