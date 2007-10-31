/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8 -*-
 *
 * Copyright (C) 2007 Richard Hughes <richard@hughsie.com>
 *
 * Licensed under the GNU General Public License Version 2
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifndef __PK_COMMON_H
#define __PK_COMMON_H

#include <glib-object.h>

G_BEGIN_DECLS

#define	PK_DBUS_SERVICE			"org.freedesktop.PackageKit"
#define	PK_DBUS_PATH			"/org/freedesktop/PackageKit"
#define	PK_DBUS_INTERFACE		"org.freedesktop.PackageKit"

guint		 pk_strlen				(gchar		*text,
							 guint		 max_length);
gboolean	 pk_strzero				(const gchar	*text);
gboolean	 pk_strvalidate				(const gchar	*text);
gboolean	 pk_strequal				(const gchar	*id1,
							 const gchar	*id2);
gchar		*pk_strsafe				(const gchar	*text);
gchar		**pk_strsplit				(const gchar	*id,
							 guint		 parts);
gboolean	 pk_strcmp_sections			(const gchar	*id1,
							 const gchar	*id2,
							 guint		 parts,
							 guint		 match);
gboolean	 pk_filter_check			(const gchar	*filter);

G_END_DECLS

#endif /* __PK_COMMON_H */
