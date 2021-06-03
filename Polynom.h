//
// Created by Timur on 15.05.2021.
//

#ifndef LAB2_VECTOR_POLYNOM_H
#define LAB2_VECTOR_POLYNOM_H

#include "./List/ListSeq.h"
#include "./Array/ArrSeq.h"
#include "./Array/ArrSeq.cpp"
#include"./List/ListSeq.cpp"
#include <stdlib.h>

template <class T>
class Polynom
{
protected:
    Sequence<T> *data;
    int seqtype;
public:
    Polynom (ArrSeq<T> *);
    Polynom (ListSeq<T> *);
    Polynom (T *, int);
    int GetType ();
    size_t Size ();
    void Resize(size_t);
    void Print ();
    T CountValue (T);
    Sequence<T> *GetData();
    T Get (size_t, size_t *);
    void Set (size_t, T, size_t *);
    void Delete();
    void Insert (T, size_t, size_t *);
    Polynom<T> *Copy ();
    Polynom<T> *Derriativte ();
};

template<class T>
void Delete (Polynom<T> *);

template <class T>
Polynom<T> *PolynomEnter (int);

template<class T>
Polynom<T> *new_Polynom (Polynom<T> *);

template<class T>
Polynom<T> *new_Polynom (int);

template<class T>
Polynom<T> *new_Polynom (Sequence<T> *, int);

template <class T>
T Power (T, size_t);

template <class T>
Polynom<T> *PolynomSum(Polynom<T> *, Polynom<T> *);

template <class T>
Polynom<T> *PolynomMult (Polynom<T> *, Polynom<T> *);

template <class T, class P>
Polynom<T> *PolynomScalarMult (Polynom<T> *, P);

template<class T>
Polynom<T> *PolynomDegree (Polynom<T> *, size_t);

template <class T>
Polynom<T> *PolynomComp (Polynom<T> *, Polynom<T> *);

#endif //LAB2_VECTOR_POLYNOM_H
