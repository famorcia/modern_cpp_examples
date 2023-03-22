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
#include <string>
#include <random>
#include <algorithm>
#include <iomanip>
#include <iterator>

int main()
{
	// SAMPLE
	const std::string ALLOWED_CHARS = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	std::string result1;
	std::string result2;
	std::sample(ALLOWED_CHARS.begin(), ALLOWED_CHARS.end(), std::back_inserter(result1), 8, std::mt19937{std::random_device{}()});
	std::sample(ALLOWED_CHARS.begin(), ALLOWED_CHARS.end(), std::back_inserter(result2), 8, std::mt19937{std::random_device{}()});
	std::cout << "Sample Result 1 : " << result1 << std::endl;
	std::cout << "Sample Result 2 : " << result2 << std::endl;

	// CLAMP
	std::cout << "Clamp Table" << std::endl;
	std::vector<int> v_int = {-200, -400, -128, 5, 0, -15, 100, 127, 256, 300};
	std::cout
		<< std::setw(04) << "Real Int"
		<< std::setw(16) << "Int8"
		<< std::setw(21) << "uInt8" << '\n';
	for (const int v : v_int)
	{
		std::cout
			<< std::setw(04) << v
			<< std::setw(20) << std::clamp(v, INT8_MIN, INT8_MAX)
			<< std::setw(21) << std::clamp(v, 0, UINT8_MAX) << '\n';
	}

	// REDUCE
	std::cout << "Reduced Vector ( with sum ) " << std::reduce(v_int.begin(), v_int.end()) << std::endl;
	std::cout << "Reduced Vector ( with Multiplications ) " << std::reduce(v_int.begin(), v_int.end(), 0, std::multiplies<>{}) << std::endl;
	const auto multiply2 = [](const auto &a)
	{ return a * 2; };
	std::cout << "Reduced Vector ( with sum and trasformation) " << std::transform_reduce(v_int.begin(), v_int.end(), 0, std::plus<>{}, multiply2) << std::endl;

	// SCAN
	std::cout << "Inclusive scan " << std::endl;
	std::inclusive_scan(std::cbegin(v_int), std::cend(v_int),
						std::ostream_iterator<int>{std::cout, " "}, std::plus<>{}); 
	std::cout << std::endl;
	std::cout << "Exclusive scan " << std::endl;
	std::exclusive_scan(std::cbegin(v_int), std::cend(v_int),
						std::ostream_iterator<int>{std::cout, " "}, 0, std::plus<>{}); 

	std::cout << std::endl;
	std::cout << "Inclusive scan and trasform" << std::endl;
	std::transform_inclusive_scan(std::cbegin(v_int), std::cend(v_int),
								  std::ostream_iterator<int>{std::cout, " "}, std::plus<>{}, multiply2);
	std::cout << std::endl;
	std::cout << "Exclusive scan and trasform" << std::endl;
	std::transform_exclusive_scan(std::cbegin(v_int), std::cend(v_int),
								  std::ostream_iterator<int>{std::cout, " "}, 0, std::plus<>{}, multiply2);
	std::cout << std::endl;

	// GCD and LCM
	const int p = 9;
	const int q = 3;
	std::cout << "Greatest Common Divisor (3,9) : " << std::gcd(p, q) << std::endl; 
	std::cout << "Least Common Multiplier (3,9) : " << std::lcm(p, q) << std::endl; 
}
