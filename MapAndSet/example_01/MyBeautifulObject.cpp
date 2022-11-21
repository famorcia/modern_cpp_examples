//
// Created by coflight on 29/10/22.
//

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
