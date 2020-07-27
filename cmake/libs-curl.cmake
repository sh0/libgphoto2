#
# libgphoto2
#

if (PKG_CONFIG_FOUND)
    pkg_check_modules(CURL IMPORTED_TARGET GLOBAL libcurl)
    if (CURL_FOUND)
        set(CURL_TARGET PkgConfig::CURL)
    endif ()
endif ()
