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
 * Is a map required?
 */

// In include order "internal include" go ahead
#include "MyObjectIdentifiable.h"
#include "LessOnMyObjectIdentifiable.h"
#include "common/Utils.h"

// Last element are "standard"
#include <set>
#include <iostream>
#include <cassert>

int main() {
    const int maxElements = 10;
    const std::string elementPrefix = "Hello_";
    typedef std::set<MyObjectIdentifiable*, LessOnMyObjectIdentifiable> MySet ;
    MySet myBeautifulSet;
    for(int i=0;i<maxElements;++i) {
        std::string id = buildAnId(elementPrefix, i);
        MyObjectIdentifiable* myObject = new MyObjectIdentifiable(id);
        std::cout<<"I'm adding:"<<id<<std::endl;
        myBeautifulSet.insert(myObject);
    }

    // does element exists?
    const std::string id5 = "Hello_5";
    MyObjectIdentifiable ob5(id5);
    MySet::iterator it = myBeautifulSet.find(&ob5);
    assert( it != myBeautifulSet.end() ) ;

    std::cout<<"Id for:"<<id5<<" is:"<< (*it)->getId() << std::endl;

    freeSet(myBeautifulSet);
    return (0);
}