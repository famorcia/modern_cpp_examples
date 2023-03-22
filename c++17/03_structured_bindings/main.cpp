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
#include <tuple>


int main()
{
	const auto [x,y] = std::pair<int,double>(10,23.5);
	std::cout << "x -> " << x << " y -> " << y << std::endl;

	const auto& [a,b,c,d] = std::make_tuple(5, "test", 12.4, true);

	std::cout << "a -> " << a << " b -> " << b << " c -> " << c << " d -> " << (d?"true":"false") << std::endl;
}
