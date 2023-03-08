/*
 *  cpp11 examples
 *  Copyright (C) 2022  Fabrizio Morciano
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
#include <list>
#include <functional>

int main ()
{
  int value_1 = 1;
  int value_2 = 2;
  int value_3 = 3;
  int value_4 = 4;

  //std::vector<int&> vec; does not compile
  std::vector<std::reference_wrapper<int>> vec;
  //vec.push_back(&value_1); does not compile
  vec.push_back(std::ref(value_1));
  vec.push_back(std::ref(value_2));
  vec.push_back(std::ref(value_3));
  vec.push_back(std::ref(value_4));

  std::vector<std::reference_wrapper<const int>> vec_const;

  vec_const.push_back(std::cref(value_1));
  vec_const.push_back(std::cref(value_2));
  vec_const.push_back(std::cref(value_3));
  vec_const.push_back(std::cref(value_4));

  auto value_1_ref = std::ref(value_1);
  std::cout <<"Before Increment Value: " << value_1_ref << std::endl;
  value_1_ref++;
  std::cout <<"After Increment Value: " << value_1_ref << std::endl;

  auto value_1_const_ref = std::cref(value_1);
  std::cout <<"Const Value: " << value_1_const_ref << std::endl;
  //value_1_const_ref++; does not compile 
  
  return 0;
}
