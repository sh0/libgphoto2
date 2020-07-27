#
# libgphoto2
#

if (PKG_CONFIG_FOUND)
    pkg_check_modules(LIBUSB IMPORTED_TARGET GLOBAL libusb-1.0)
    if (LIBUSB_FOUND)
        set(LIBUSB_TARGET PkgConfig::LIBUSB)
    endif ()
endif ()
