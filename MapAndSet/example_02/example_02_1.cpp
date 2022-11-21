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