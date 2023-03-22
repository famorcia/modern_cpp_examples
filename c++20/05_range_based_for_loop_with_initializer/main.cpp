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
int main()
{
	for(auto v = std::vector{1,2,4,5}; auto& elem : v){
		std::cout << elem << ";;";
	}
	std::cout << std::endl;

	for(auto v = std::vector{"Tom","Jerry","Cartoon"}; auto& elem : v){
		std::cout << elem << ";;";
	}
	std::cout << std::endl;

	return 0;
}
