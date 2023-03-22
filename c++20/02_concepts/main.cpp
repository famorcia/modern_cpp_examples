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

template<typename T>
concept integral = std::is_integral_v<T>;

template<typename T>
concept unsigned_integral = std::is_integral_v<T> && !std::is_signed_v<T>;

template<integral T>
T sum(T a, T b){
	return a+b;
}

template<typename T>
requires unsigned_integral<T>
T product(T a, T b){
	return a*b;
}


int main()
{
	auto sum_resutl = sum(-10,20);

	unsigned int a = 10;
	unsigned int b = 20;
	//auto product_result = product(10,20);  Does not compile, deduced type is int and is a signed type
	auto product_result = product(a,b);

	std::cout << "Sum Result: " << sum_resutl << std::endl;
	std::cout << "Product Result: " << product_result << std::endl;
	
	return 0;
}
