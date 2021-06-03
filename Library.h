//
// Created by Timur on 30.05.2021.
//

#ifndef LAB2_VECTOR_LIBRARY_H
#define LAB2_VECTOR_LIBRARY_H

#include "Polynom.h"

template<class T>
class Library
{
private:
    Sequence<Polynom<T> *> *lib;
    size_t capacity;
public:
    Library(int);
    size_t Size();
    Polynom<T> *Get(size_t, size_t *);
    void Add (Polynom<T> *);
    void Display ();
    void Delete();
};

#endif //LAB2_VECTOR_LIBRARY_H
