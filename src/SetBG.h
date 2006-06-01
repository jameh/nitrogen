/*

This file is from Nitrogen, an X11 background setter.  
Copyright (C) 2006  Dave Foster & Javeed Shaikh

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

*/

#ifndef _SETBG_H_
#define _SETBG_H_

#include "main.h"
#include <gdk/gdkx.h>
#include <math.h>

/**
 * Utility class for setting the background image.
 *
 * @author	Dave Foster <daf@minuslab.net>
 * @date	30 Aug 2005
 */
class SetBG {
	public:
			
		enum SetMode { 
			SET_SCALE,
			SET_TILE,
			SET_CENTER,
			SET_BEST
		};
		
		static bool set_bg(	Glib::ustring disp,
							Glib::ustring file,
							SetMode mode,
							Gdk::Color bgcolor
							);

		static Glib::ustring mode_to_string( const SetMode mode );
		static SetMode string_to_mode( const Glib::ustring str );

	private:
		static Glib::RefPtr<Gdk::Display> _display;
		static bool _opened;

		static Glib::RefPtr<Gdk::Pixbuf> make_scale(const Glib::RefPtr<Gdk::Pixbuf>, const gint, const gint, Gdk::Color);
		static Glib::RefPtr<Gdk::Pixbuf> make_tile(const Glib::RefPtr<Gdk::Pixbuf>, const gint, const gint, Gdk::Color);
		static Glib::RefPtr<Gdk::Pixbuf> make_center(const Glib::RefPtr<Gdk::Pixbuf>, const gint, const gint, Gdk::Color);
		static Glib::RefPtr<Gdk::Pixbuf> make_best(const Glib::RefPtr<Gdk::Pixbuf>, const gint, const gint, Gdk::Color);

		static guint32 GdkColorToUint32(const Gdk::Color);
	
};

#endif