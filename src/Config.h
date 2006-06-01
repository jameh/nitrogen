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

#ifndef _CONFIG_H_
#define _CONFIG_H_

#include <glib.h>
#include "SetBG.h"
#include <vector>

/**
 * Static class that interfaces with the configuration. 
 * 
 * @author	Dave Foster <daf@minuslab.net>
 * @date	6 Sept 2005
 */
class Config {
	private:
		
		bool check_dir();		
			
		bool recurse;
		
		Glib::ustring color_to_string(Gdk::Color color);

	public:
		
		// instance getter
		static Config* get_instance();

		Config();
		// get/set for bgs
		bool get_bg(const Glib::ustring disp, Glib::ustring &file, SetBG::SetMode &mode, Gdk::Color &bgcolor);
		bool set_bg(const Glib::ustring disp, const Glib::ustring file, const SetBG::SetMode mode, Gdk::Color bgcolor);

		// get all groups
		bool get_bg_groups(std::vector<Glib::ustring> &groups);

		bool get_recurse() { return Config::recurse; }
		void set_recurse(bool n) { Config::recurse = n; }
						
};

#endif