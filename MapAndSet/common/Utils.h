//
// Created by Fabrizio Morciano on 29/10/22.
//

#ifndef MAPANDSET_UTILS_H
#define MAPANDSET_UTILS_H

#include <string>
#include <sstream>

inline
std::string buildAnId(const std::string& prefix,
                      int id) {
    std::ostringstream oss;
    oss<<prefix;
    oss<<id;
    return (oss.str());
}


template <typename T>
void freeMap(T &t) {
    typedef typename T::iterator MapIterator;
    MapIterator it = t.begin();
    MapIterator end = t.end();
    for(;it!=end;++it) {
        delete it->second; it->second = 0;
    }
    t.clear();
}

template <typename T>
void freeSet(T &t) {
    typedef typename T::iterator MapIterator;
    MapIterator it = t.begin();
    MapIterator end = t.end();
    for(;it!=end;++it) {
        delete *it;
    }
    t.clear();
}


#endif //MAPANDSET_UTILS_H
