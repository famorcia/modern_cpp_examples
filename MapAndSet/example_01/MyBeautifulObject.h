//
// Created by coflight on 29/10/22.
//

#ifndef MAPANDSET_MYBEAUTIFULOBJECT_H
#define MAPANDSET_MYBEAUTIFULOBJECT_H


class MyBeautifulObject {
    static int counter;
    int id;
public:
    MyBeautifulObject();

    // This is not virtual, what does it imply?
    ~MyBeautifulObject();

    // What effect do we obtain if we had move in private?
    MyBeautifulObject(const MyBeautifulObject& ob);
    MyBeautifulObject& operator=(const MyBeautifulObject& ob);
};

#endif //MAPANDSET_MYBEAUTIFULOBJECT_H
