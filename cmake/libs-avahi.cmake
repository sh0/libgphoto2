#
# libgphoto2
#

if (PKG_CONFIG_FOUND)
    pkg_check_modules(AVAHI IMPORTED_TARGET GLOBAL avahi-client)
    if (AVAHI_FOUND)
        set(AVAHI_TARGET PkgConfig::AVAHI)
    endif ()
endif ()
