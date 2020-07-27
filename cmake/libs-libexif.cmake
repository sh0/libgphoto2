#
# libgphoto2
#

if (PKG_CONFIG_FOUND)
    pkg_check_modules(LIBEXIF IMPORTED_TARGET GLOBAL libexif)
    if (LIBEXIF_FOUND)
        set(LIBEXIF_TARGET PkgConfig::LIBEXIF)
    endif ()
endif ()

# Check if ExifData structure has ifd[[]] member
if (LIBEXIF_FOUND)
    include(CheckStructHasMember)
    find_file(LIBEXIF_DATA_H "exif-data.h" PATHS ${LIBEXIF_INCLUDE_DIRS})
    if (LIBEXIF_DATA_H)
        check_struct_has_member(ExifData ifd "${LIBEXIF_DATA_H}" LIBEXIF_IFD)
    endif ()
endif ()
