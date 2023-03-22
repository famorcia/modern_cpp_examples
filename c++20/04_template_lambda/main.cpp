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
#include <vector>

std::vector<int> v1 = {2,3,4,5,6};
std::vector<std::string> v2 = {"Tom","Jerry","cartoon"};

int main()
{
	auto fn_print_array = []<typename T>(std::vector<T> v){
		for(auto it : v){
			std::cout << it << ";;" ;
		}
		std::cout << std::endl;
	};



	fn_print_array(v1);
	fn_print_array(v2);
	
	return 0;

}
