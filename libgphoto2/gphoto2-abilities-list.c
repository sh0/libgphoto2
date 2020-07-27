/** \file gphoto2-abilities-list.c
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

#include <gphoto2-config.h>
#include <gphoto2/gphoto2-abilities-list.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <gphoto2/gphoto2-result.h>
#include <gphoto2/gphoto2-port-log.h>
#include <gphoto2/gphoto2-library.h>

#ifdef ENABLE_NLS
#  include <libintl.h>
#  undef _
#  define _(String) dgettext (GETTEXT_PACKAGE, String)
#  ifdef gettext_noop
#    define N_(String) gettext_noop (String)
#  else
#    define N_(String) (String)
#  endif
#else
#  define textdomain(String) (String)
#  define gettext(String) (String)
#  define dgettext(Domain,Message) (Message)
#  define dcgettext(Domain,Message,Type) (Message)
#  define bindtextdomain(Domain,Directory) (Domain)
#  define bind_textdomain_codeset(Domain,Charset) (Domain)
#  define _(String) (String)
#  define N_(String) (String)
#endif

struct _CameraAbilitiesList {
    unsigned int count;
    CameraAbilities* abilities;
};

const char* gp_message_codeset (const char *codeset)
{
	gp_port_message_codeset (codeset);
	return bind_textdomain_codeset (GETTEXT_PACKAGE, codeset);
}

int gp_abilities_list_new(CameraAbilitiesList** list)
{
    /* Hack to set GetText translations. */
    bindtextdomain(GETTEXT_PACKAGE, GETTEXT_LOCALEDIR);

    /* Check validity. */
    if (!list)
        return GP_ERROR_BAD_PARAMETERS;

    /* Allocate new list. */
    *list = calloc(1, sizeof(CameraAbilitiesList));
    if (!(*list))
        return GP_ERROR_NO_MEMORY;
    (*list)->count = 0;
    (*list)->abilities = NULL;
    return GP_OK;
}

int gp_abilities_list_free(CameraAbilitiesList* list)
{
    /* Check validity. */
    if (!list)
        return GP_ERROR_BAD_PARAMETERS;

    /* Free all entries */
    gp_abilities_list_reset(list);

    /* Free list. */
    free(list);
    return GP_OK;
}

int gp_abilities_list_reset(CameraAbilitiesList* list)
{
    /* Check validity. */
    if (!list)
        return GP_ERROR_BAD_PARAMETERS;

    /* Free all entries. */
    list->count = 0;
    free(list->abilities);
    return GP_OK;
}

int gp_abilities_list_count(CameraAbilitiesList* list)
{
    /* Check validity. */
    if (!list)
        return GP_ERROR_BAD_PARAMETERS;

    /* Get count. */
    return list->count;
}

int gp_abilities_list_get_abilities(CameraAbilitiesList* list, int index, CameraAbilities* abilities)
{
    /* Check validity. */
    if (!list || !abilities)
        return GP_ERROR_BAD_PARAMETERS;
    if (index < 0 || index >= list->count)
        return GP_ERROR_BAD_PARAMETERS;

    /* Copy entry. */
    memcpy(abilities, &list->abilities[index], sizeof(*abilities));
    return GP_OK;
}

int gp_abilities_list_lookup_model(CameraAbilitiesList* list, const char* model)
{
    /* Check validity. */
    if (!list || !model)
        return GP_ERROR_BAD_PARAMETERS;

    /* Search for model. */
    for (int i = 0; i < list->count; i++) {
        if (!strcasecmp(list->abilities[i].model, model))
            return i;
    }

    /* Failure. */
    return GP_ERROR_MODEL_NOT_FOUND;
}

int gp_abilities_list_append(CameraAbilitiesList* list, CameraAbilities abilities)
{
    /* Check validity. */
    if (!list)
        return GP_ERROR_BAD_PARAMETERS;

    /* Allocate new list. */
    list->count += 1;
    list->abilities = realloc(list->abilities, sizeof(CameraAbilities) * list->count);
    if (!list->abilities)
        return GP_ERROR_NO_MEMORY;

    /* Copy entry. */
    memcpy(&(list->abilities[list->count - 1]), &abilities, sizeof(abilities));

    /* FIXME: Replace colon by a space in the model string for compatibility reasons. */
    char* ch = strchr(list->abilities[list->count - 1].model, ':');
    if (ch)
        *ch = ' ';

    /* Success. */
    return GP_OK;
}

static int gp_abilities_list_sort_cmp(const void* a, const void* b)
{
    const CameraAbilities* ca = a;
    const CameraAbilities* cb = b;
    return strcasecmp(ca->model, cb->model);
}

static int gp_abilities_list_sort(CameraAbilitiesList* list)
{
    /* Check validity. */
    if (!list)
        return GP_ERROR_BAD_PARAMETERS;

    /* Sort list. */
    qsort(list->abilities, list->count, sizeof(CameraAbilities), gp_abilities_list_sort_cmp);
    return GP_OK;
}

int gp_abilities_list_load_dir(CameraAbilitiesList* list, const char* dir, GPContext* context)
{
    return gp_abilities_list_load(list, context);
}

int gp_abilities_list_load(CameraAbilitiesList* list, GPContext* context)
{
    /* Check validity. */
    if (!list)
        return GP_ERROR_BAD_PARAMETERS;

    /* Libraries. */
    CameraLibrary** libraries = gp_camera_libraries_list();
    int libraries_count = 0;
    while (libraries[libraries_count])
        libraries_count++;

    /* Start progress tracking. */
    unsigned int progress = gp_context_progress_start(context, libraries_count, _("Loading camera libraries..."));

    /* Load libraries. */
    for (int i = 0; libraries[i]; i++) {
        /* Validate functions. */
        CameraLibrary* library = libraries[i];
        if (!library->id || !library->abilities || !library->init) {
            GP_LOG_E("Failed to load camera library: library descriptor is missing callbacks, skipping!");
            continue;
        }

        /* Check if already added. */
        int found = FALSE;
        for (int j = 0; j < list->count; j++) {
            if (library == list->abilities[i].library)
                found = TRUE;
        }
        if (found)
            continue;

        /* Get camera abilities. */
        int count = list->count;
        if (library->abilities(list) != GP_OK) {
            GP_LOG_E("Failed to load camera library: error obtaining library '%s' abilities, skipping!", library->id);
            continue;
        }
        for (; count < list->count; count++)
            list->abilities[count].library = library;

        /* Progress status update. */
        gp_context_progress_update(context, progress, i);
        if (gp_context_cancel(context) == GP_CONTEXT_FEEDBACK_CANCEL)
            return GP_ERROR_CANCEL;
    }

    /* Stop progress tracking. */
    gp_context_progress_stop(context, progress);

    /* Sort list of abilities by name. */
    if (gp_abilities_list_sort(list) != GP_OK)
        return GP_ERROR;

    /* Success */
    return GP_OK;
}

static int gp_abilities_list_detect_usb(CameraAbilitiesList* list, int* ability, GPPort* port)
{
    int res = GP_ERROR_IO_USB_FIND;

    int count = gp_abilities_list_count(list);
    if (count < 0)
        return GP_ERROR;

    /* Detect USB cameras */
    GP_LOG_D("Auto-detecting USB cameras...");
    *ability = -1;
    for (int i = 0; i < count; i++) {
        if (!(list->abilities[i].port & port->type))
            continue;

        int v = list->abilities[i].usb_vendor;
        int p = list->abilities[i].usb_product;
        if (v) {
            res = gp_port_usb_find_device(port, v, p);
            if (res == GP_OK) {
                GP_LOG_D("Found '%s' (0x%x,0x%x)", list->abilities[i].model, v, p);
                *ability = i;
            } else if (res < 0 && res != GP_ERROR_IO_USB_FIND) {
                GP_LOG_D("gp_port_usb_find_device(vendor=0x%x, product=0x%x) returned %i", v, p, res);
            }

            if (res != GP_ERROR_IO_USB_FIND)
                return res;
        }

        int c = list->abilities[i].usb_class;
        int s = list->abilities[i].usb_subclass;
        p = list->abilities[i].usb_protocol;
        if (c) {
            res = gp_port_usb_find_device_by_class(port, c, s, p);
            if (res == GP_OK) {
                GP_LOG_D("Found '%s' (0x%x,0x%x,0x%x)", list->abilities[i].model, c, s, p);
                *ability = i;
            } else if (res < 0 && res != GP_ERROR_IO_USB_FIND) {
                GP_LOG_D("gp_port_usb_find_device_by_class(class=0x%x, subclass=0x%x, protocol=0x%x) returned %i", c, s, p, res);
            }

            if (res != GP_ERROR_IO_USB_FIND)
                return res;
        }
    }
    return res;
}

int gp_abilities_list_detect(CameraAbilitiesList* list, GPPortInfoList* info_list, CameraList* camera_list, GPContext* context)
{
    /* Check validity. */
    if (!list || !info_list || !camera_list)
        return GP_ERROR_BAD_PARAMETERS;

    int res = gp_list_reset(camera_list);
    if (res != GP_OK)
        return res;

    int info_count = gp_port_info_list_count(info_list);
    if (info_count < 0)
        return GP_ERROR;

    GPPort* port = NULL;
    if (gp_port_new(&port) < 0)
        return GP_ERROR;

    for (int i = 0; i < info_count; i++) {
        GPPortInfo info;
        res = gp_port_info_list_get_info(info_list, i, &info);
        if (res != GP_OK)
            return res;

        res = gp_port_set_info(port, info);
        if (res != GP_OK)
            return res;

        GPPortType type;
        gp_port_info_get_type(info, &type);

        char* xpath = NULL;
        res = gp_port_info_get_path(info, &xpath);
        if (res < GP_OK)
            continue;

        switch (type) {
            case GP_PORT_USB:
            case GP_PORT_USB_SCSI:
            case GP_PORT_USB_DISK_DIRECT: {
                int ability = 0;
                res = gp_abilities_list_detect_usb(list, &ability, port);
                if (res == GP_OK) {
                    gp_list_append(camera_list, list->abilities[ability].model, xpath);
                } else if (res < 0) {
                    gp_port_set_error(port, NULL);
                }
                break;
            }
            case GP_PORT_DISK: {
                struct stat stbuf;

                char* s = strchr(xpath, ':');
                if (!s)
                    break;
                s++;

                char path[1024];
                snprintf(path, sizeof(path), "%s/DCIM", s);
                if (stat(path, &stbuf) == -1) {
                    snprintf (path, sizeof(path), "%s/dcim", s);
                    if (-1 == stat(path, &stbuf))
                        continue;
                }
                gp_list_append (camera_list, "Mass Storage Camera", xpath);
                break;
            }
            case GP_PORT_PTPIP: {
                char* s = strchr(xpath, ':');
                if (!s)
                    break;
                s++;
                if (!strlen(s))
                    break;

                gp_list_append (camera_list, "PTP/IP Camera", xpath);
                break;
            }
            default:
                /*  We currently cannot detect any cameras on this port */
                break;
        }
    }

    gp_port_free(port);

    return GP_OK;
}
