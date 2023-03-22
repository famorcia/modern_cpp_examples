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

consteval int sum(int a, int b){
	return a+b;
}

constexpr int fn_int(){
	return 1;
}

int fn_int2(){
	return 2;
}

constinit int myInt = fn_int();
//constinit int myInt = fn_int2(); Not allowed because fn_int2 is not constexpr, so cannot be evaluated at compile time

int main()
{
	constexpr int mySum = sum(10,20);
	//int x = 10;
	//int y = 20;
	//int mySum = sum(x,y); Not Allowed because x and y cannot be used in constant expression

	std::cout << "mySum: " << mySum << std::endl;
	std::cout << "myInt: " << myInt << std::endl;
	
}
