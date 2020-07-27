/** \file
 * \brief Camery driver header.
 *
 * \author Copyright 2000 Scott Fritzinger
 *
 * \note
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * \note
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * \note
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA  02110-1301  USA
 */

#ifndef GPHOTO2_LIBRARY_H
#define GPHOTO2_LIBRARY_H

#include <gphoto2/gphoto2-abilities-list.h>
#include <gphoto2/gphoto2-camera.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * \brief Adds the abilities of the supported models to the supplied list.
 *
 * \param list Abilities list.
 * \return Error code.
 */
typedef int (*CameraLibraryAbilitiesFunc)(CameraAbilitiesList* list);

/**
 * \brief Initializes the camera.
 *
 * \param camera Camera context.
 * \param context gPhoto2 context.
 * \return Error code.
 *
 * The camera driver will establish a first connection
 * to the camera and configure the camera variable (i.e. using
 * #gp_filesystem_set_list_funcs or #gp_port_get_settings).
 */
typedef int (*CameraLibraryInitFunc)(Camera* camera, GPContext* context);

/**
 * \brief Camera library descriptor.
 *
 * If you want to write a camera library then you should fill the following
 * structure with callbacks to library functions.
 */
struct _CameraLibrary {
    const char* id;
    CameraLibraryAbilitiesFunc abilities;
    CameraLibraryInitFunc init;
};

/**
 * \brief Get a null-terminated list of built-in camera libraries.
 *
 * Applications should not use this function directly, but rely on
 * gp_abilities_* and gp_camera_* functions.
 *
 * \return Null-terminated list of camera library descriptor pointers.
 */
CameraLibrary** gp_camera_libraries_list();

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* GPHOTO2_LIBRARY_H */
