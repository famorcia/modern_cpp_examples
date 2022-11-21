/*
 * Effect of using pointer in map instead of object.
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

    myBeautifulMap.clear();
    // Is all ok?
    // try run executable with valgrind ;-)
    return (0);
}