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
#include <list>

template <typename T>
void sayHello( const T& container) {
  for(auto elem = std::begin(container); elem !=std::end(container); ++elem){
    auto sayHelloLambda = [](const std::string& name){std::cout << "Hello " << name << std::endl;};
    sayHelloLambda(*elem);
  }
}

int main ()
{
  std::vector<std::string> vec = {"Marc", "Oliver", "Anna", "Carl"};
  //std::begin and std::end wors also with arrays which don't have begin and end member functions
  std::string arr[4] = {"Marc", "Oliver", "Anna", "Carl"};
  std::list<std::string> list = {"Marc", "Oliver", "Anna", "Carl"};
  std::cout << "*** Say Hello Vector ***"<< std::endl;
  sayHello(vec);
  std::cout << "*** Say Hello Array ***"<< std::endl;
  sayHello(arr);
  std::cout << "*** Say Hello List ***"<< std::endl;
  sayHello(list);
  return 0;
}
