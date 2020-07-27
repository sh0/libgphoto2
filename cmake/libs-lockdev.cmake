#
# libgphoto2
#

# Find lockdev headers
find_path(LOCKDEV_INCLUDE_LOCKDEV_H "lockdev.h")
find_path(LOCKDEV_INCLUDE_TTYLOCK_H "ttylock.h")

# Find lockdev library
find_library(LOCKDEV_LIBRARY lockdev)
if (LOCKDEV_LIBRARY)
    set(LOCKDEV_FOUND TRUE)
    add_library(liblockdev SHARED IMPORTED GLOBAL)
    target_include_directories(liblockdev SYSTEM INTERFACE ${LOCKDEV_INCLUDE_LOCKDEV_H} ${LOCKDEV_INCLUDE_TTYLOCK_H})
    set_property(TARGET liblockdev PROPERTY IMPORTED_LOCATION ${LOCKDEV_LIBRARY})
    set(LOCKDEV_TARGET liblockdev)
endif ()
