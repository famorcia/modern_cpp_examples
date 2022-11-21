//
// Created by coflight on 29/10/22.
//

#include "MyObjectIdentifiable.h"

MyObjectIdentifiable::MyObjectIdentifiable(const std::string& anId):id(anId) {

}

const std::string& MyObjectIdentifiable::getId() const {
    return (id);
}