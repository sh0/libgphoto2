#
# libgphoto2
#

find_package(Iconv)
if (Iconv_FOUND)
    set(ICONV_FOUND TRUE)
    set(ICONV_TARGET Iconv::Iconv)
endif ()
