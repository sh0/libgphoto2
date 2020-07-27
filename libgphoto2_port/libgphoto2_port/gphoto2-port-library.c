/** \file
 *
 * \author Copyright 2001 Lutz Mueller <lutz@users.sf.net>
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

#include <gphoto2/gphoto2-port-library.h>

/* Camera port declarations. */
#ifdef BUILD_PORT_DISK
extern GPPortLibrary gp_port_disk_library;
#endif
#ifdef BUILD_PORT_PTPIP
extern GPPortLibrary gp_port_ptpip_library;
#endif
#ifdef BUILD_PORT_SERIAL
extern GPPortLibrary gp_port_serial_library;
#endif
#ifdef BUILD_PORT_LIBUSB1
extern GPPortLibrary gp_port_libusb1_library;
#endif
#ifdef BUILD_PORT_RAWUSB
extern GPPortLibrary gp_port_rawusb_library;
#endif
#ifdef BUILD_PORT_USBDISKDIRECT
extern GPPortLibrary gp_port_usbdiskdirect_library;
#endif
#ifdef BUILD_PORT_USBSCSI
extern GPPortLibrary gp_port_usbscsi_library;
#endif

/* List of internal camera port libraries. */
static GPPortLibrary* gpi_libraries[] = {
#ifdef BUILD_PORT_DISK
	gp_port_disk_library,
#endif
#ifdef BUILD_PORT_PTPIP
	gp_port_ptpip_library,
#endif
#ifdef BUILD_PORT_SERIAL
	gp_port_serial_library,
#endif
#ifdef BUILD_PORT_LIBUSB1
	gp_port_libusb1_library,
#endif
#ifdef BUILD_PORT_RAWUSB
	gp_port_rawusb_library,
#endif
#ifdef BUILD_PORT_USBDISKDIRECT
	gp_port_usbdiskdirect_library,
#endif
#ifdef BUILD_PORT_USBSCSI
	gp_port_usbscsi_library,
#endif
	NULL
};

GPPortLibrary** gp_port_libraries_list()
{
    return gpi_libraries;
}
