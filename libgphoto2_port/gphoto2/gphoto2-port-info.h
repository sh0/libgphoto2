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

#ifndef GPHOTO2_PORT_INFO_H
#define GPHOTO2_PORT_INFO_H

#include <gphoto2/gphoto2-port-library.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * \internal GPPortInfo:
 *
 * The internals of this list are private.
 **/
struct _GPPortInfo {
    GPPortType type;        /**< \brief The type of this port. */
    char* name;             /**< \brief The name of this port (usb:) */
    char* path;             /**< \brief The path of this port (usb:001,023) */
    GPPortLibrary* library; /**< \brief Pointer to library descriptor. */
};

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* GPHOTO2_PORT_INFO_H */
