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


// Now we can declarate this kind of funtion  or function template

template <typename T>
auto& fn_identity_ref(T& t) {
  return t;
}

// this function return a reference to the deduced return type

int main()
{
	int a = 10;
	std::string string_test = "test";
	auto x = fn_identity_ref<int>(a); // x of type int&
	std::string s = fn_identity_ref<std::string>(string_test); // s of type std::string&
	std::cout << "x : " << x  << " of type: " << typeid(x).name() << std::endl;
	std::cout << "s : " << s << " of type: " << typeid(s).name() << std::endl;



	return 0;
}
