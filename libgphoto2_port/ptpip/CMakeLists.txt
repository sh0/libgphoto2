#
# libgphoto2
#

# Library
add_library(gphoto2-port-ptpip OBJECT ptpip.c)
target_link_libraries(gphoto2-port-ptpip gphoto2-iolib)
set_target_properties(gphoto2-port-ptpip PROPERTIES
    POSITION_INDEPENDENT_CODE ON
    C_STANDARD 11
)
