#
# libgphoto2
#

# Headers
include(CheckIncludeFile)
include(CheckSymbolExists)
include(CheckStructHasMember)

# Unix compability level
set(CMAKE_REQUIRED_DEFINITIONS -D_DEFAULT_SOURCE -D_GNU_SOURCE -D_BSD_SOURCE)

# Whether we compile with libexif support.
set(HAVE_LIBEXIF ${LIBEXIF_FOUND})
# Whether we use a version of libexif with ExifData.ifd[[]]
set(HAVE_LIBEXIF_IFD ${LIBEXIF_IFD})
# Whether we compile with gdlib support.
set(HAVE_LIBGD ${LIBGD_FOUND})
# Define if we found LIBJPEG and its headers.
set(HAVE_LIBJPEG ${LIBJPEG_FOUND})
# Whether we compile with libxml-2.0 support.
set(HAVE_LIBXML2 ${LIBXML2_FOUND})
# Define if you have the iconv() function.
set(HAVE_ICONV ${ICONV_FOUND})
# Whether we compile with Avahi support.
set(HAVE_MDNS_BONJOUR ${AVAHI_FOUND})

# Define to 1 if you have the `localtime_r' function.
check_symbol_exists(localtime_r "time.h" HAVE_LOCALTIME_R)
# Whether struct tm has tm_gmtoff field.
check_struct_has_member("struct tm" tm_gmtoff "time.h" HAVE_TM_GMTOFF LANGUAGE C)
# Define to 1 if you have the `gmtime_r' function.
check_symbol_exists(gmtime_r "time.h" HAVE_GMTIME_R)

# Define to 1 if you have the <locale.h> header file.
check_include_file("locale.h" HAVE_LOCALE_H)
# Define to 1 if you have the <limits.h> header file.
check_include_file("limits.h" HAVE_LIMITS_H)

# Define to 1 if you have the <langinfo.h> header file.
check_include_file("langinfo.h" HAVE_LANGINFO_H)
# Define to 1 if you have the <sys/statvfs.h> header file.
check_include_file("sys/statvfs.h" HAVE_SYS_STATVFS_H)
# Define to 1 if you have the <sys/param.h> header file.
check_include_file("sys/param.h" HAVE_SYS_PARAM_H)
# Define to 1 if you have the <sys/vfs.h> header file.
check_include_file("sys/vfs.h" HAVE_SYS_VFS_H)
# Define to 1 if you have the <sys/mount.h> header file.
check_include_file("sys/mount.h" HAVE_SYS_MOUNT_H)
# Define to 1 if you have the <sys/statfs.h> header file.
check_include_file("sys/statfs.h" HAVE_SYS_STATFS_H)
# Define to 1 if you have the <sys/select.h> header file.
check_include_file("sys/select.h" HAVE_SYS_SELECT_H)
# Define to 1 if you have the <sys/mman.h> header file.
check_include_file("sys/mman.h" HAVE_SYS_MMAN_H)
# Define to 1 if you have the <unistd.h> header file.
check_include_file("unistd.h" HAVE_UNISTD_H)
# Define to 1 if you have the <memory.h> header file.
check_include_file("memory.h" HAVE_MEMORY_H)

# Define to 1 if you have the `lstat' function.
check_symbol_exists(lstat "sys/types.h;sys/stat.h;unistd.h" HAVE_LSTAT)
# Define to 1 if you have the `statfs' function.
check_symbol_exists(statfs "sys/vfs.h;sys/statfs.h" HAVE_STATFS)
# Define to 1 if you have the `setenv' function.
check_symbol_exists(setenv "stdlib.h" HAVE_SETENV)
# Define to 1 if you have the `inet_aton' function.
check_symbol_exists(inet_aton "sys/socket.h;netinet/in.h;arpa/inet.h" HAVE_INET_ATON)
# Define to 1 if you have the `rand_r' function.
check_symbol_exists(rand_r "stdlib.h" HAVE_RAND_R)

# Whether we have the va_copy() function.
check_symbol_exists(va_copy "stdarg.h" HAVE_VA_COPY)

# Whether we have regex.h
check_include_file("regex.h" HAVE_REGEX)
# Define if you have GNU regex.
check_symbol_exists(re_compile_pattern "regex.h" HAVE_GNU_REGEX)

# Define to 1 if you have the <mntent.h> header file.
check_include_file("mntent.h" HAVE_MNTENT_H)
# Define to 1 if you have the <sys/mntent.h> header file.
check_include_file("sys/mntent.h" HAVE_SYS_MNTENT_H)
# Define to 1 if you have the <sys/mnttab.h> header file.
check_include_file("sys/mnttab.h" HAVE_SYS_MNTTAB_H)
# Define to 1 if you have the `setmntent' function.
if (HAVE_MNTENT_H)
    check_symbol_exists(setmntent "mntent.h" HAVE_SETMNTENT)
elseif (HAVE_SYS_MNTENT_H)
    check_symbol_exists(setmntent "sys/mntent.h" HAVE_SETMNTENT)
endif ()
# Define to 1 if you have the `endmntent' function.
if (HAVE_MNTENT_H)
    check_symbol_exists(endmntent "mntent.h" HAVE_ENDMNTENT)
elseif (HAVE_SYS_MNTENT_H)
    check_symbol_exists(endmntent "sys/mntent.h" HAVE_ENDMNTENT)
endif ()
# Whether struct mnttag has mnt_mountp field.
if (HAVE_SYS_MNTENT_H AND HAVE_SYS_MNTTAB_H)
    check_struct_has_member("struct mnttag" mnt_mountp "sys/mntent.h;sys/mnttab.h" HAVE_MNTTAB LANGUAGE C)
endif ()

# Define to 1 if you have the <termios.h> header file.
check_include_file("termios.h" HAVE_TERMIOS_H)
# Define to 1 if you have the <fcntl.h> header file.
check_include_file("fcntl.h" HAVE_FCNTL_H)
# Define to 1 if you have the <errno.h> header file.
check_include_file("errno.h" HAVE_ERRNO_H)
# Define to 1 if you have the <sys/time.h> header file.
check_include_file("sys/time.h" HAVE_SYS_TIME_H)
# Define to 1 if you have the <sys/file.h> header file.
check_include_file("sys/file.h" HAVE_SYS_FILE_H)
# Define to 1 if you have the <sys/ioctl.h> header file.
check_include_file("sys/ioctl.h" HAVE_SYS_IOCTL_H)
# Define to 1 if you have the <sys/select.h> header file.
check_include_file("sys/select.h" HAVE_SYS_SELECT_H)
# Define to 1 if you have the <sys/param.h> header file.
check_include_file("sys/param.h" HAVE_SYS_PARAM_H)
# Define to 1 if you have the <scsi/sg.h> header file.
check_include_file("scsi/sg.h" HAVE_SCSI_SG_H)

# Define if you have ttylock based tty locking.
check_include_file("ttylock.h" HAVE_TTYLOCK)
# Define if you have dev_lock/lockdev based locking.
check_include_file("lockdev.h" HAVE_LOCKDEV)
# Define to 1 if you have the `flock' function.
check_symbol_exists(flock "sys/file.h" HAVE_FLOCK)
