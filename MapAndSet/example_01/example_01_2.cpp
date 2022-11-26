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

/*
 * Fix removal of object in map.
 * see also example_01
 */

// In include order "internal include" go ahead
#include "MyBeautifulObject.h"
#include "common/Utils.h"

// Last element are "standard"
#include <map>
#include <iostream>

int main() {
    const int maxElements = 10;
    const std::string elementPrefix = "Hello_";
    std::map<std::string, MyBeautifulObject*> myBeautifulMap;
    for(int i=0;i<maxElements;++i) {
        std::string id = buildAnId(elementPrefix, i);
        std::cout<<"I'm adding:"<<id<<std::endl;
        myBeautifulMap[id] = new MyBeautifulObject();
    }


    std::map<std::string, MyBeautifulObject*>::iterator it = myBeautifulMap.begin();
    std::map<std::string, MyBeautifulObject*>::iterator end = myBeautifulMap.end();
    for(;it != end; ++it) {
        delete it->second; it->second = 0;
    }
    myBeautifulMap.clear();

    return (0);
}