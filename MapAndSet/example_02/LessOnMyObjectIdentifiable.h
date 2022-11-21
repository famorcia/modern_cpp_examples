//
// Created by coflight on 29/10/22.
//

#ifndef MAPANDSET_LESSONMYOBJECTIDENTIFIABLE_H
#define MAPANDSET_LESSONMYOBJECTIDENTIFIABLE_H

#include "MyObjectIdentifiable.h"

struct LessOnMyObjectIdentifiable
{
    bool
    operator()( MyObjectIdentifiable* x,
                MyObjectIdentifiable* y) const {
        return x->getId() < y->getId();
    }
};

#endif //MAPANDSET_LESSONMYOBJECTIDENTIFIABLE_H
