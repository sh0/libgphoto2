#
# libgphoto2
#

if (PKG_CONFIG_FOUND)
    pkg_check_modules(LIBGD IMPORTED_TARGET GLOBAL gdlib)
    if (LIBGD_FOUND)
        set(LIBGD_TARGET PkgConfig::LIBGD)
    endif ()
endif ()
