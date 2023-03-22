/*
 *  cpp11 examples
 *  Copyright (C) 2023  Matteo Botticci
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.

 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.

 *  You should have received a copy of the GNU General Public License along
 *  with this program; if not, write to the Free Software Foundation, Inc.,
 *  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#include <iostream>
#include <string>
#include <regex>

int main()
{
	std::string std_str = "    this is a standard string! ";
	std::cout << "Original String \"" << std_str << "\"" << std::endl;
	//assign to string view 
	std::string_view std_str_vw {std_str};
	std::cout << "Original String View \"" << std_str_vw << "\"" << std::endl;
	//remove blanks at start 
	std_str_vw.remove_prefix(std::min(std_str_vw.find_first_not_of(" "), std_str_vw.size()));
	std::cout << "Trim begin of String View \"" << std_str_vw << "\"" << std::endl;
	//Recast to string
	std_str = std::string(std_str_vw);
	std::cout << "Recasted String \"" << std_str << "\"" << std::endl;

	

}
