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
 * How to remove element while cycling.
 */

#include "common/Utils.h"

#include <map>
#include <iostream>
#include <cassert>

struct MyData {

};

typedef std::map<std::string, MyData> MyDataMap;

const size_t DATA_MAP_SIZE = 10;

void fillMap(MyDataMap& dataMap) {
    for(size_t i=0; i<DATA_MAP_SIZE; ++i) {
        std::ostringstream oss;
        oss<<i;
        dataMap[oss.str()] = MyData();
    }
}

int main() {

    MyDataMap dataMap;
    fillMap(dataMap);
    assert(dataMap.size() ==  DATA_MAP_SIZE);

    MyDataMap::iterator it = dataMap.begin();
    MyDataMap::iterator end = dataMap.end();

    for (; it != end; ) {
        std::cout<<"Data["<<it->first<<"]"<<std::endl;
        if ( it->first == "4" ) {
            std::cout<<it->first<<" removed!"<<std::endl;
            // note postfix
            dataMap.erase(it++);
        }
        else {
            // note prefix
            ++it;
        }
    }

    assert(dataMap.size() == DATA_MAP_SIZE-1);

    std::cout<<"Print again the DataMap."<<std::endl;
    it = dataMap.begin();
    for (; it != end; ++it) {
        std::cout<<"Data["<<it->first<<"]"<<std::endl;
    }

    return (0);
}