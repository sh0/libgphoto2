/** \file
 *
 * \author Copyright 2002 Hans Ulrich Niedermann <gp@n-dimensional.de
 *
 * \par License
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * \par
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * \par
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301  USA
 */

#include <gphoto2-config.h>

#include <stdlib.h>

#include <gphoto2/gphoto2-version.h>

const char **gp_library_version(GPVersionVerbosity verbose)
{
	/* we could also compute/parse the short strings from the long
	   ones, but the current method is easier for now :-) */
	static const char *shrt[] =
		{
			PACKAGE_VERSION,
#ifdef HAVE_LIBEXIF
			"EXIF",
#else
			"no EXIF",
#endif
			NULL
		};
	static const char *verb[] =
		{
			PACKAGE_VERSION,
#ifdef HAVE_LIBEXIF
			"EXIF (for special handling of EXIF files)",
#else
			"no EXIF (for special handling of EXIF files)",
#endif
			NULL
		};
	return((verbose == GP_VERSION_VERBOSE)?verb:shrt);
}
