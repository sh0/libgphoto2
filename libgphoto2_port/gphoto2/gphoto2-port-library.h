/** \file gphoto2-port-library.h
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

#ifndef GPHOTO2_PORT_LIBRARY_H
#define GPHOTO2_PORT_LIBRARY_H

#include <gphoto2/gphoto2-port-info-list.h>
#include <gphoto2/gphoto2-port.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * \brief The port operations
 *
 * These operations are to be implemented and set by the port library,
 * which drives the lowlevel protocol (serial, usb, etc.).
 *
 * They are acessed using the accessor functions, like gp_port_open(),
 * gp_port_read() and gp_port_write().
 */
typedef struct _GPPortOperations {
    int (*init)(GPPort*);
    int (*exit)(GPPort*);
    int (*open)(GPPort*);
    int (*close)(GPPort*);
    int (*read)(GPPort*, char*, int);
    int (*check_int)(GPPort*, char*, int, int);
    int (*write)(GPPort*, const char*, int);
    int (*update)(GPPort*);

    /* Pointers to devices. */

    /* for serial devices */
    int (*get_pin)(GPPort*, GPPin, GPLevel*);
    int (*set_pin)(GPPort*, GPPin, GPLevel);
    int (*send_break)(GPPort*, int);
    int (*flush)(GPPort*, int);

    /* for USB devices */
    int (*find_device)(GPPort* dev, int idvendor, int idproduct);
    int (*find_device_by_class)(GPPort* dev, int class, int subclass, int protocol);
    int (*clear_halt)(GPPort* dev, int ep);
    int (*msg_write)(GPPort* dev, int request, int value, int index, char* bytes, int size);
    int (*msg_read)(GPPort* dev, int request, int value, int index, char* bytes, int size);
    int (*msg_interface_write)(GPPort* dev, int request, int value, int index, char* bytes, int size);
    int (*msg_interface_read)(GPPort* dev, int request, int value, int index, char* bytes, int size);
    int (*msg_class_write)(GPPort* dev, int request, int value, int index, char* bytes, int size);
    int (*msg_class_read) (GPPort* dev, int request, int value, int index, char* bytes, int size);

    /* For USB disk direct IO devices */
    int (*seek)(GPPort* dev, int offset, int whence);

    /* For USB Mass Storage raw SCSI ports */
    int (*send_scsi_cmd)(GPPort* port, int to_dev, char* cmd, int cmd_size, char* sense, int sense_size, char* data, int data_size);
    int (*reset)(GPPort* port);
} GPPortOperations;

typedef int (*GPPortLibraryList)(GPPortInfoList* list);
typedef GPPortOperations* (*GPPortLibraryOperations)(void);

/**
 * \brief Port library descriptor.
 *
 * Fill this structure when implementing a new port library.
 */
struct _GPPortLibrary {
    GPPortType type;
    GPPortLibraryList list;
    GPPortLibraryOperations operations;
};

/**
 * \brief Get a null-terminated list of built-in port libraries.
 *
 * Applications should not use this function directly.
 *
 * \return Null-terminated list of port library descriptor pointers.
 */
GPPortLibrary** gp_port_libraries_list();

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* GPHOTO2_PORT_LIBRARY_H */
