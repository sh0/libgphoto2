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

#ifndef GPHOTO2_PORT_INFO_LIST_H
#define GPHOTO2_PORT_INFO_LIST_H

#include <gphoto2/gphoto2-port.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef _GPHOTO2_INTERNAL_CODE
#include <gphoto2/gphoto2-port-log.h>
extern const StringFlagItem gpi_gphoto_port_type_map[];
#endif

int gp_port_info_new(GPPortInfo* info);
int gp_port_info_get_name(GPPortInfo info, char** name);
int gp_port_info_set_name(GPPortInfo info, const char* name);
int gp_port_info_get_path(GPPortInfo info, char** path);
int gp_port_info_set_path(GPPortInfo info, const char* path);
int gp_port_info_get_type(GPPortInfo info, GPPortType* type);
int gp_port_info_set_type(GPPortInfo info, const GPPortType type);
int gp_port_info_get_library(GPPortInfo info, GPPortLibrary** library);
int gp_port_info_set_library(GPPortInfo info, GPPortLibrary* library);

/* Internals are private */
typedef struct _GPPortInfoList GPPortInfoList;

int gp_port_info_list_new(GPPortInfoList** list);
int gp_port_info_list_free(GPPortInfoList* list);
int gp_port_info_list_append(GPPortInfoList* list, GPPortInfo info);
int gp_port_info_list_load(GPPortInfoList* list);
int gp_port_info_list_count(GPPortInfoList* list);
int gp_port_info_list_lookup_path(GPPortInfoList* list, const char* path);
int gp_port_info_list_lookup_name(GPPortInfoList* list, const char* name);
int gp_port_info_list_get_info(GPPortInfoList* list, int n, GPPortInfo* info);

const char *gp_port_message_codeset (const char*);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* GPHOTO2_PORT_INFO_LIST_H */
