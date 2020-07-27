/****************************************************************************
 *
 * File: util.h
 *
 ****************************************************************************/

#ifndef _CANON_UTIL_H
#define _CANON_UTIL_H

#include <gphoto2/gphoto2-endian.h>

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

/****************************************************************************
 *
 * prototypes
 *
 ****************************************************************************/
void canon_dump_hex ( FILE *fp, void *buffer, int length );

int canon_is_thumbnail (const char *name);
int canon_is_audio (const char *name);
int canon_is_image (const char *name);
int canon_is_movie (const char *name);
int canon_is_jpeg (const char *name);
int canon_is_crw (const char *name);
int canon_is_cr2 (const char *name);

const char *canon_filename2mimetype(const char *filename);

#endif /* _CANON_UTIL_H */

/****************************************************************************
 *
 * End of file: util.h
 *
 ****************************************************************************/

/*
 * Local Variables:
 * c-file-style:"linux"
 * indent-tabs-mode:t
 * End:
 */
