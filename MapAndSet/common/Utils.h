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
