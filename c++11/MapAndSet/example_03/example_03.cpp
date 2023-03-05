/**************************************************************************\
 * BSD 3-Clause License
 *
 * Copyright (c) 2023, Fabrizio Morciano
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
\**************************************************************************/

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