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


template <typename ...Args>
bool fn_or(Args... args) {
  return (false || ... || args );
}

template <typename ...Args>
double fn_product(Args... args) {
  return ( ... * args );
}

template <auto... vs> struct value_list { };

// Retrieve the nth value in a list of values
template <size_t n, auto... vs> struct nth_value;
template <size_t n, auto v1, auto... vs>
struct nth_value<n, v1, vs...>
{
    static constexpr auto value = nth_value<n - 1, vs...>::value;
};

//specializzation of template above
template <auto v1, auto... vs>
struct nth_value<0, v1, vs...>
{
    static constexpr auto value = v1;
};


int main()
{
	bool b1 = false;
	bool b2 = true;
	auto b_res = fn_or(b1,b2);

	std::cout << "b_res -> " << (b_res?"true":"false") << std::endl;

	auto d_pro =  fn_product(2.2,3.5,6.1);

	std::cout << "d_pro -> " << d_pro << std::endl;

	auto val = nth_value<3, 1,2,3,4,5,6,7,8>::value;

	std::cout << "val -> " << val << std::endl;
	
	return 0;
}
