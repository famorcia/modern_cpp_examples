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

struct A1 {
	virtual const char* fn() const = 0;
};

struct A2 : public A1{
	virtual const char* fn() const { return  "A2";};
};

struct A3 : public A2{
	constexpr virtual const char* fn() const { return  "A3";};
};

int main()
{
	A2 a2;
	constexpr A3 a3;
	std::cout << a2.fn() << std::endl;
	std::cout << a3.fn() << std::endl;
}
