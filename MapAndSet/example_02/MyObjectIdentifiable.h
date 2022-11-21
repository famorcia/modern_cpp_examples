//
// Created by Fabrizio Morciano on 29/10/22.
//

#ifndef MAPANDSET_MYOBJECTIDENTIFIABLE_H
#define MAPANDSET_MYOBJECTIDENTIFIABLE_H

#include <string>

class MyObjectIdentifiable {

    std::string id;
public:
    MyObjectIdentifiable(const std::string& anId);

    // Why const at the end?
    const std::string& getId() const;

};


#endif //MAPANDSET_MYOBJECTIDENTIFIABLE_H
