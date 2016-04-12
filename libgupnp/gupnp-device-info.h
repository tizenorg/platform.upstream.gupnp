/*
 * Copyright (C) 2006, 2007 OpenedHand Ltd.
 *
 * Author: Jorn Baayen <jorn@openedhand.com>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifndef __GUPNP_DEVICE_INFO_H__
#define __GUPNP_DEVICE_INFO_H__

#include <glib-object.h>
#include <libxml/tree.h>
#include <libsoup/soup-uri.h>

#include "gupnp-context.h"
#include "gupnp-service-info.h"
#include "gupnp-resource-factory.h"

G_BEGIN_DECLS

EXPORT_API GType
gupnp_device_info_get_type (void) G_GNUC_CONST;

#define GUPNP_TYPE_DEVICE_INFO \
                (gupnp_device_info_get_type ())
#define GUPNP_DEVICE_INFO(obj) \
                (G_TYPE_CHECK_INSTANCE_CAST ((obj), \
                 GUPNP_TYPE_DEVICE_INFO, \
                 GUPnPDeviceInfo))
#define GUPNP_DEVICE_INFO_CLASS(obj) \
                (G_TYPE_CHECK_CLASS_CAST ((obj), \
                 GUPNP_TYPE_DEVICE_INFO, \
                 GUPnPDeviceInfoClass))
#define GUPNP_IS_DEVICE_INFO(obj) \
                (G_TYPE_CHECK_INSTANCE_TYPE ((obj), \
                 GUPNP_TYPE_DEVICE_INFO))
#define GUPNP_IS_DEVICE_INFO_CLASS(obj) \
                (G_TYPE_CHECK_CLASS_TYPE ((obj), \
                 GUPNP_TYPE_DEVICE_INFO))
#define GUPNP_DEVICE_INFO_GET_CLASS(obj) \
                (G_TYPE_INSTANCE_GET_CLASS ((obj), \
                 GUPNP_TYPE_DEVICE_INFO, \
                 GUPnPDeviceInfoClass))

                 #ifndef EXPORT_API
                 #define EXPORT_API
                 #endif // EXPORT_API


typedef struct _GUPnPDeviceInfoPrivate GUPnPDeviceInfoPrivate;
typedef struct _GUPnPDeviceInfo GUPnPDeviceInfo;
typedef struct _GUPnPDeviceInfoClass GUPnPDeviceInfoClass;

/**
 * GUPnPDeviceInfo:
 *
 * This struct contains private data only, and should be accessed using the
 * functions below.
 */
struct _GUPnPDeviceInfo {
        GObject parent;

        GUPnPDeviceInfoPrivate *priv;
};

struct _GUPnPDeviceInfoClass {
        GObjectClass parent_class;

        /* vtable */
        xmlNode          * (* get_element) (GUPnPDeviceInfo *info);

        /* FIXME: Once we can break API/ABI, clean-up and rename the
         * _get_device/_get_service functions */
#ifndef GOBJECT_INTROSPECTION_SKIP
        GUPnPDeviceInfo  * (* get_device)  (GUPnPDeviceInfo *info,
                                            xmlNode         *element);
        GUPnPServiceInfo * (* get_service) (GUPnPDeviceInfo *info,
                                            xmlNode         *element);
#endif
        /* future padding */
        void (* _gupnp_reserved1) (void);
        void (* _gupnp_reserved2) (void);
        void (* _gupnp_reserved3) (void);
        void (* _gupnp_reserved4) (void);
};


EXPORT_API GUPnPContext *
gupnp_device_info_get_context            (GUPnPDeviceInfo *info);

EXPORT_API const char *
gupnp_device_info_get_location           (GUPnPDeviceInfo *info);

EXPORT_API const SoupURI *
gupnp_device_info_get_url_base           (GUPnPDeviceInfo *info);

EXPORT_API const char *
gupnp_device_info_get_udn                (GUPnPDeviceInfo *info);

EXPORT_API const char *
gupnp_device_info_get_device_type        (GUPnPDeviceInfo *info);

EXPORT_API char *
gupnp_device_info_get_friendly_name      (GUPnPDeviceInfo *info);

EXPORT_API char *
gupnp_device_info_get_manufacturer       (GUPnPDeviceInfo *info);

EXPORT_API char *
gupnp_device_info_get_manufacturer_url   (GUPnPDeviceInfo *info);

EXPORT_API char *
gupnp_device_info_get_model_description  (GUPnPDeviceInfo *info);

EXPORT_API char *
gupnp_device_info_get_model_name         (GUPnPDeviceInfo *info);

EXPORT_API char *
gupnp_device_info_get_model_number       (GUPnPDeviceInfo *info);

EXPORT_API char *
gupnp_device_info_get_model_url          (GUPnPDeviceInfo *info);

EXPORT_API char *
gupnp_device_info_get_serial_number      (GUPnPDeviceInfo *info);

EXPORT_API char *
gupnp_device_info_get_upc                (GUPnPDeviceInfo *info);

EXPORT_API char *
gupnp_device_info_get_icon_url           (GUPnPDeviceInfo *info,
                                          const char      *requested_mime_type,
                                          int              requested_depth,
                                          int              requested_width,
                                          int              requested_height,
                                          gboolean         prefer_bigger,
                                          char           **mime_type,
                                          int             *depth,
                                          int             *width,
                                          int             *height);

EXPORT_API char *
gupnp_device_info_get_presentation_url   (GUPnPDeviceInfo *info);

EXPORT_API GList *
gupnp_device_info_list_dlna_device_class_identifier (GUPnPDeviceInfo *info);

EXPORT_API GList *
gupnp_device_info_list_dlna_capabilities (GUPnPDeviceInfo *info);

EXPORT_API char *
gupnp_device_info_get_description_value  (GUPnPDeviceInfo *info,
                                          const char      *element);
EXPORT_API GList *
gupnp_device_info_list_devices           (GUPnPDeviceInfo *info);

EXPORT_API GList *
gupnp_device_info_list_device_types      (GUPnPDeviceInfo *info);

EXPORT_API GUPnPDeviceInfo *
gupnp_device_info_get_device             (GUPnPDeviceInfo *info,
                                          const char      *type);

EXPORT_API GList *
gupnp_device_info_list_services          (GUPnPDeviceInfo *info);

EXPORT_API GList *
gupnp_device_info_list_service_types     (GUPnPDeviceInfo *info);

EXPORT_API GUPnPServiceInfo *
gupnp_device_info_get_service            (GUPnPDeviceInfo *info,
                                          const char      *type);

EXPORT_API GUPnPResourceFactory *
gupnp_device_info_get_resource_factory   (GUPnPDeviceInfo *device_info);

G_END_DECLS

#endif /* __GUPNP_DEVICE_INFO_H__ */
