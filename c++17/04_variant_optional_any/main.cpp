/*
 *  cpp11 examples
 *  Copyright (C) 2022  Fabrizio Morciano
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
#include <variant>
#include <optional>
#include <any>


std::optional<std::string> optional_result(bool b) {
  if (b) {
    return "Good work";
  } else {
    return {};
  }
}


int main()
{
	std::variant<double,int> v_x {12.5};
	std::cout << "variant double -> " << std::get<double>(v_x) << "variant int -> " << std::get<int>(v_x) << std::endl;
	std::cout << "variant 0 -> " << std::get<0>(v_x) << "variant 1 -> " << std::get<1>(v_x) << std::endl;

	std::cout << "optional well created: " << optional_result(true).value() << std::endl;
	std::cout << "optional not well created and returned default: " << optional_result(false).value_or("default") << std::endl; 
	std::cout << "Optional has value? " << (optional_result(true).has_value()?"true":"false") << std::endl;
	std::cout << "Optional has value? " << (optional_result(false).has_value()?"true":"false") << std::endl;
}
