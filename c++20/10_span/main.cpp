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
#include <span>
#include <vector>
#include <array>
#include <list>

int sum_collection(std::span<const int> int_collection){
	int result = 0;
	for (const auto& elem : int_collection){
		result += elem;
	}
	return result;
}

int main()
{
	std::cout << "Sum of Vector: " << sum_collection(std::vector<int> { 1, 2, 3 }) << std::endl;
	std::cout << "Sum of Array: " << sum_collection(std::array<int, 5>{ 1, 2, 3}) << std::endl;
	// std::cout << "Sum of List: " << sum_collection(std::list<int>{ 1, 2, 3}) << std::endl;	Not allowed because not contiguos memory

	return 0;
}
