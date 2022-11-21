/*
 * Is a map required?
 */


// In include order "internal include" go ahead
#include "MyObjectIdentifiable.h"
#include "common/Utils.h"

// Last element are "standard"
#include <map>
#include <iostream>

int main() {
    const int maxElements = 10;
    const std::string elementPrefix = "Hello_";
    std::map<std::string, MyObjectIdentifiable*> myBeautifulMap;
    for(int i=0;i<maxElements;++i) {
        std::string id = buildAnId(elementPrefix, i);
        std::cout<<"I'm adding:"<<id<<std::endl;

        MyObjectIdentifiable* myObject = new MyObjectIdentifiable(id);
        myBeautifulMap[id] = myObject;
    }

    freeMap(myBeautifulMap);

    return (0);
}