/** \file gphoto2-abilities-list.h
 * \brief List of supported camera models including their abilities.
 *
 * \author Copyright 2000 Scott Fritzinger
 *
 * \par
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

#ifndef GPHOTO2_ABILITIES_LIST_H
#define GPHOTO2_ABILITIES_LIST_H

#include <gphoto2/gphoto2-context.h>
#include <gphoto2/gphoto2-list.h>
#include <gphoto2/gphoto2-port-info-list.h>
#include <gphoto2/gphoto2-port-log.h>
#include <gphoto2/gphoto2-abilities.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * \brief List of supported camera models including their abilities
 *
 * Use gp_abilities_list_* functions to access the list.
 */
typedef struct _CameraAbilitiesList CameraAbilitiesList;

/**
 * \brief Allocate the a new empty abilities list.
 *
 * You would then call gp_abilities_list_load() in order to
 * populate it.
 *
 * Function to allocate the memory for a new abilities list.
 * \param list CameraAbilitiesList object to initialize
 * \return gphoto2 error code
 */
int gp_abilities_list_new(CameraAbilitiesList** list);

/**
 * \brief Free the given CameraAbilitiesList object.
 *
 * \param list Abilities list.
 * \return Error code
 */
int gp_abilities_list_free(CameraAbilitiesList* list);

/**
 * \brief Reset the abilities list by removing all entries.
 *
 * \param list Abilities list.
 * \return Error code.
 */
int gp_abilities_list_reset(CameraAbilitiesList* list);

/**
 * \brief Count the entries in the supplied list.
 *
 * \param list Abilities list.
 * \returns Number of list entries or negative error code.
 */
int gp_abilities_list_count(CameraAbilitiesList* list);

/**
 * \brief Retrieve the camera abilities of entry with supplied index number.
 *
 * Retrieves the camera abilities of entry with supplied
 * index number. Typically, you would call gp_camera_set_abilities()
 * afterwards in order to prepare the initialization of a camera.
 *
 * \param list Abilities list.
 * \param index Entry index.
 * \param abilities Pointer to abilities for returned data.
 * \return Error code.
 */
int gp_abilities_list_get_abilities(CameraAbilitiesList *list, int index, CameraAbilities* abilities);

/**
 * \brief Search the list for an entry of given model name
 *
 * \param list Abilities list.
 * \param model Camera model name.
 * \return Index of entry or negative error code.
 */
int gp_abilities_list_lookup_model(CameraAbilitiesList* list, const char* model);

/**
 * \brief Append the abilities entry to the abilities list.
 *
 * \param list Abilities list.
 * \param abilities Abilities entry.
 * \return Error code.
 */
int gp_abilities_list_append(CameraAbilitiesList* list, CameraAbilities abilities);

/**
 * \brief Adds all internally supported camera libraries to abilities list.
 *
 * \param list Abilities list.
 * \param context Camera context.
 * \return Error code.
 */
int gp_abilities_list_load(CameraAbilitiesList* list, GPContext* context);

/**
 * \brief Deprecated function to load camera libraries from given directory.
 *
 * This function now just calls @gp_abilities_list_load as plugin-based camera loading has been deprecated.
 *
 * \param list Abilities list.
 * \param dir Path to a directory containing camera libraries.
 * \param context Camera context.
 * \return Error code.
 */
int gp_abilities_list_load_dir(CameraAbilitiesList* list, const char* dir, GPContext* context);

/**
 * \brief Detect connected cameras.
 *
 * Tries to detect any camera connected to the computer using the supplied
 * list of supported cameras and the supplied info_list of ports.
 *
 * \param list a CameraAbilitiesList
 * \param info_list the GPPortInfoList of ports to use for detection
 * \param l a #CameraList that contains the autodetected cameras after the call
 * \param context a #GPContext
 *
 * \return a gphoto2 error code
 */
int gp_abilities_list_detect(CameraAbilitiesList* list, GPPortInfoList* info_list, CameraList* camera_list, GPContext* context);

/**
 * \brief Set the current character codeset libgphoto2 is operating in.
 *
 * Set the codeset for all messages returned by libgphoto2.
 * \param codeset New codeset for the messages. For instance "utf-8".
 * \return old codeset as returned from bind_textdomain_codeset().
 *
 * You would then call gp_abilities_list_load() in order to
 * populate it.
 */
const char* gp_message_codeset(const char* codeset);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* GPHOTO2_ABILITIES_LIST_H */
