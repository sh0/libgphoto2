#
# libgphoto2
#

if (PKG_CONFIG_FOUND)
    pkg_check_modules(LIBJPEG IMPORTED_TARGET GLOBAL libjpeg)
    if (LIBJPEG_FOUND)
        set(LIBJPEG_TARGET PkgConfig::LIBJPEG)
    endif ()
endif ()
