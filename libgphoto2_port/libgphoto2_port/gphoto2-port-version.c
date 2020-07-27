/** \file
 *
 * Copyright 2002 Hans Ulrich Niedermann <gp@n-dimensional.de
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301  USA
 */

#include <gphoto2-port-config.h>
#include <stdlib.h>

#include <gphoto2/gphoto2-port-version.h>

const char **gp_port_library_version(GPVersionVerbosity verbose)
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
#if defined(BUILD_PORT_LIBUSB1) || defined(BUILD_PORT_RAWUSB) || defined(HAVE_LIBUSB_WIN32)
			"USB",
#else
			"no USB",
#endif
#ifdef BUILD_PORT_SERIAL
			"serial "
#if HAVE_TTYLOCK
			"ttylock locking",
#elif HAVE_LOCKDEV
			"lockdev locking",
#else
			"without locking",
#endif

#else
			"no serial",
#endif
			NULL
		};
	static const char *verb[] =
		{
			PACKAGE_VERSION,
#ifdef HAVE_LIBEXIF
			"EXIF (for vusb)",
#else
			"no EXIF (for vusb)",
#endif
#ifdef HAVE_LIBUSB_WIN32
			"USB (libusb-win32, for USB cameras)",
#elif defined(BUILD_PORT_LIBUSB1)
			"USB (libusb1, for USB cameras)",
#elif defined(BUILD_PORT_RAWUSB)
			"USB (libusb0, for USB cameras)",
#else
			"no USB (for USB cameras)",
#endif
#ifdef BUILD_PORT_SERIAL
			"serial (for serial cameras)",
#else
			"no serial (for serial cameras)",
#endif
#ifdef HAVE_TTYLOCK
			"ttylock (serial port locking)",
#else
			"no ttylock (serial port locking)",
#endif
#ifdef HAVE_LOCKDEV
			"lockdev (serial port locking)",
#else
			"no lockdev (serial port locking)",
#endif
			NULL
		};
	return((verbose == GP_VERSION_VERBOSE)?verb:shrt);
}

