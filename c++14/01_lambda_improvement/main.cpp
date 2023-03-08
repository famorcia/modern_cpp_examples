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

int x10(int i) 
{ 
	return i * 10; 
};


int main()
{
	//Auto specifier for polimorphic lambda expressions
	auto fn_identity = [](auto x) { return x; };

	double d = fn_identity(32.5);
	std::cout << "d value = "  << d <<  std::endl;
	std::string s = fn_identity("Test Identity");
	std::cout << "s value = "  << s << std::endl;


	//lambda capture initializer

	
	auto f = [x = x10(5)] { return x; }; 

	std::cout << "f() -> " << f() << std::endl;

	auto increment = [i = 3] () mutable {
  	// this would not compile without 'mutable' as we are modifying x on each call
  	return i++;
	};
	
	for (auto x = 0; x < 10; ++x){
		std::cout << "increment call #" << x << " --> " << increment() << std::endl; 
	}
	return 0;
}
