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
#include <algorithm>
#include <array>
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <map>

template <typename T>
void printContainer(const T& a){
  for (auto &x : a)
    {
      std::cout << x << "\t";
    }
    std::cout << std::endl;
}

template <typename T>
void printMap(const T& a){
  for (auto &x : a)
    {
      std::cout << x.second << "\t";
    }
    std::cout << std::endl;
}


int main()
{
  // New Array container that support container operations/algorithms
  std::array<std::string, 4> a = {"d", "c", "b", "a"};

  // auto printArray = [](const std::array<std::string, 4> &a)
  // {
  //   for (auto &x : a)
  //   {
  //     std::cout << x << "\t";
  //   }
  //   std::cout << std::endl;
  // };

  std::cout << "*** Before Sorting ***" << std::endl;
  printContainer(a);
  std::sort(a.begin(), a.end());
  std::cout << "*** After Sorting ***" << std::endl;
  printContainer(a);

  //Unordered Containers are more performant and use an hash function to create the entry
  std::map<std::string,std::string> map = {{"a","a"}, {"b","b"}, {"c","c"}, {"d","d"}};
  std::unordered_map<std::string,std::string> u_map = {{"a","a"}, {"b","b"}, {"c","c"}, {"d","d"}}; 
  std::cout << "*** Ordered Map ***" << std::endl;
  printMap(map);
  std::cout << "*** Unordered Map ***" << std::endl;
  printMap(u_map);

  std::set<std::string> set = {"a","b","c","d"};
  std::unordered_set<std::string> u_set = {"a","b","c","d"};
  std::cout << "*** Ordered Set ***" << std::endl;
  printContainer(set);
  std::cout << "*** Unordered Set ***" << std::endl;
  printContainer(u_set);

  std::multimap<std::string,std::string> mmap = {{"a","a1"},{"a","a2"},  {"b","b"}, {"c","c"}, {"d","d"}};
  std::unordered_multimap<std::string,std::string> u_mmap = {{"a","a1"},{"a","a2"}, {"b","b"}, {"c","c"}, {"d","d"}}; 
  std::cout << "*** Ordered MultiMap ***" << std::endl;
  printMap(mmap);
  std::cout << "*** Unordered MultiMap ***" << std::endl;
  printMap(u_mmap);

  std::multiset<std::string> mset = {"a","a","b","c","d"};
  std::unordered_multiset<std::string> u_mset = {"a","a","b","c","d"};
  std::cout << "*** Ordered MultiSet ***" << std::endl;
  printContainer(mset);
  std::cout << "*** Unordered MultiSet ***" << std::endl;
  printContainer(u_mset);

  return 0;
}
