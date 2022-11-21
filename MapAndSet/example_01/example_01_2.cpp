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