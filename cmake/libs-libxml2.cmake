#
# libgphoto2
#

if (PKG_CONFIG_FOUND)
    pkg_check_modules(LIBXML2 IMPORTED_TARGET GLOBAL libxml-2.0)
    if (LIBXML2_FOUND)
        set(LIBXML2_TARGET PkgConfig::LIBXML2)
    endif ()
endif ()
