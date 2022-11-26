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

#include "MyBeautifulObject.h"

#include <iostream>


int MyBeautifulObject::counter = 0;

MyBeautifulObject::MyBeautifulObject():id(++counter) {
    std::cout<<"["<<id<<"]: MyBeautifulObject()"<<std::endl;
}
MyBeautifulObject::~MyBeautifulObject(){
    std::cout<<"["<<id<<"]: ~MyBeautifulObject()"<<std::endl;
}

MyBeautifulObject::MyBeautifulObject(const MyBeautifulObject& ob) {
    if(this != &ob) {
        id = ob.id;
        std::cout << "[" << id << "]: MyBeautifulObject(const MyBeautifulObject& ob)" << std::endl;
    }
}

MyBeautifulObject& MyBeautifulObject::operator=(const MyBeautifulObject& ob) {
    if(this != &ob) {
        id = ob.id;
        std::cout << "[" << id << "]: operator=(const MyBeautifulObject& ob)" << std::endl;
    }
    return (*this);
}
