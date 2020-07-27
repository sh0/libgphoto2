#
# libgphoto2
#

find_package(Intl)
if (Intl_FOUND)
    set(INTL_FOUND TRUE)
    if ("${Intl_LIBRARIES}" STREQUAL "")
        add_library(libintl INTERFACE IMPORTED GLOBAL)
        target_include_directories(libintl SYSTEM INTERFACE ${Intl_INCLUDE_DIRS})
        set(INTL_TARGET libintl)
    else ()
        add_library(libintl SHARED IMPORTED GLOBAL)
        target_include_directories(libintl SYSTEM INTERFACE ${Intl_INCLUDE_DIRS})
        set_property(TARGET libintl PROPERTY IMPORTED_LOCATION ${Intl_LIBRARIES})
        set(INTL_TARGET libintl)
    endif ()
endif ()
