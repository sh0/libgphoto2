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

#ifndef GPHOTO2_ABILITIES_H
#define GPHOTO2_ABILITIES_H

#include <gphoto2/gphoto2-port.h>

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/**
 * \brief Camera library descriptor declaration.
 */
struct _CameraLibrary;
typedef struct _CameraLibrary CameraLibrary;

/**
 * Current implementation status of the camera driver.
 */
typedef enum {
    GP_DRIVER_STATUS_PRODUCTION,    /**< Driver is production ready. */
    GP_DRIVER_STATUS_TESTING,       /**< Driver is beta quality. */
    GP_DRIVER_STATUS_EXPERIMENTAL,  /**< Driver is alpha quality and might even not work. */
    GP_DRIVER_STATUS_DEPRECATED     /**< Driver is no longer recommended to use and will be removed. */
} CameraDriverStatus;

/**
 * Type of the device represented. Currently we have Still Cameras
 * and MTP Audio Players.
 */
typedef enum {
    GP_DEVICE_STILL_CAMERA          = 0,     /**< Traditional still camera */
    GP_DEVICE_AUDIO_PLAYER          = 1 << 0 /**< Audio player */
} GphotoDeviceType;

/**
 * A bitmask of remote control related operations of the device.
 * Some drivers might support additional dynamic capabilities (like the PTP driver).
 */
typedef enum {
    GP_OPERATION_NONE               = 0,      /**< No remote control operation supported. */
    GP_OPERATION_CAPTURE_IMAGE      = 1 << 0, /**< Capturing images supported. */
    GP_OPERATION_CAPTURE_VIDEO      = 1 << 1, /**< Capturing videos supported. */
    GP_OPERATION_CAPTURE_AUDIO      = 1 << 2, /**< Capturing audio supported. */
    GP_OPERATION_CAPTURE_PREVIEW    = 1 << 3, /**< Capturing image previews supported. */
    GP_OPERATION_CONFIG             = 1 << 4, /**< Camera and Driver configuration supported. */
    GP_OPERATION_TRIGGER_CAPTURE    = 1 << 5  /**< Camera can trigger capture and wait for events. */
} CameraOperation;

/**
 * A bitmask of image related operations of the device.
 */
typedef enum {
    GP_FILE_OPERATION_NONE          = 0,      /**< No special file operations, just download. */
    GP_FILE_OPERATION_DELETE        = 1 << 1, /**< Deletion of files is possible. */
    GP_FILE_OPERATION_PREVIEW       = 1 << 3, /**< Previewing viewfinder content is possible. */
    GP_FILE_OPERATION_RAW           = 1 << 4, /**< Raw retrieval is possible (used by non-JPEG cameras) */
    GP_FILE_OPERATION_AUDIO         = 1 << 5, /**< Audio retrieval is possible. */
    GP_FILE_OPERATION_EXIF          = 1 << 6  /**< EXIF retrieval is possible. */
} CameraFileOperation;

/**
 * A bitmask of filesystem related operations of the device.
 */
typedef enum {
    GP_FOLDER_OPERATION_NONE        = 0,      /**< No special filesystem operation. */
    GP_FOLDER_OPERATION_DELETE_ALL  = 1 << 0, /**< Deletion of all files on the device. */
    GP_FOLDER_OPERATION_PUT_FILE    = 1 << 1, /**< Upload of files to the device possible. */
    GP_FOLDER_OPERATION_MAKE_DIR    = 1 << 2, /**< Making directories on the device possible. */
    GP_FOLDER_OPERATION_REMOVE_DIR  = 1 << 3  /**< Removing directories from the device possible. */
} CameraFolderOperation;

/**
 * \brief Describes the properties of a specific camera.
 *
 * The internals of this structures are used extensively by the
 * camlibs, but the status regarding use by frontends is questionable.
 */
typedef struct {
    /** \name Camera library. */
    CameraLibrary* library;         /**< \brief Pointer to camera library descriptor. */

    /** \name General information. */
    char model[128];                /**< \brief name of camera model (null-terminated string). */
    CameraDriverStatus status;      /**< \brief driver quality. */
    GphotoDeviceType device_type;   /**< \brief Device type. */

    /** \name Port information. */
    GPPortType port;    /** \brief Supported port types. */
    int speed[64];      /** \brief Supported serial port speeds (null-terminated string). */

    /** \name Supported operations */
    CameraOperation operations;                 /**< \brief Camera operation functions. */
    CameraFileOperation file_operations;        /**< \brief Camera file operation functions. */
    CameraFolderOperation folder_operations;    /**< \brief Camera folder operation functions. */

    /** \name USB-specific information. */
    int usb_vendor;     /**< \brief USB Vendor D */
    int usb_product;    /**< \brief USB Product ID */
    int usb_class;      /**< \brief USB device class */
    int usb_subclass;   /**< \brief USB device subclass */
    int usb_protocol;   /**< \brief USB device protocol */
} CameraAbilities;

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* GPHOTO2_ABILITIES_H */
