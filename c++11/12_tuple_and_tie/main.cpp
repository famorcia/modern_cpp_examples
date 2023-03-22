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
  // `tuple` has type `std::tuple<int, const char*, float>`.
  auto tuple = std::make_tuple(10, "test", 2.14);

  //get values
  std::cout << "( " << std::get<0>(tuple) << ", " << std::get<1>(tuple) << ", " << std::get<2>(tuple) << " )" << std::endl;

  std::string tuple_str;
  double tuple_flt;
  //get value with tie
  std::tie(std::ignore, tuple_str, tuple_flt) = tuple;
  std::cout << "Tie Tuple Picking : " <<  tuple_str << " , " << tuple_flt << std::endl;
  //tie works also with pair
  std::tie(tuple_str, tuple_flt) = std::make_pair("test_pair", 3.14);
  std::cout << "Tie Pair Picking : " <<  tuple_str << " , " << tuple_flt << std::endl;

  return 0;
}
