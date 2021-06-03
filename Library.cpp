//
// Created by Timur on 30.05.2021.
//

#include "Library.h"

template<class T>
Library<T>::Library(int seq)
{
    this->capacity = 0;
    if (seq == 1)
        this->lib = (Sequence<Polynom<T> *> *) new ListSeq<Polynom<T> *> (new LinkedList<Polynom<T> *> ());
    else
        this->lib = (Sequence<Polynom<T> *> *) new ArrSeq<Polynom<T> *> (new DArray<Polynom<T> *> ());
}

template<class T>
Polynom<T> *Library<T>::Get(size_t index, size_t *checker)
{
    if ((index >= 0) && (index < capacity))
        return this->lib->Get(index, checker);
    else
        throw -1;
}

template<class T>
void Library<T>::Add(Polynom<T> *pol)
{
    this->lib->Append(pol);
    capacity++;
}

template<class T>
void Library<T>::Display()
{
    size_t checker = 0;
    if (capacity == 0)
    {
        std::cout << "No one polynom in library" << std::endl;
        return;
    }
    else
        std::cout << "NOW IN LIBRARY: " << std::endl;
    for (size_t i = 0; i < capacity; i++)
    {
        std::cout << i << ". ";
        (this->lib->Get(i, &checker))->Print();
    }
}

template<class T>
size_t Library<T>::Size() {
    return this->capacity;
}

template<class T>
void Library<T>::Delete()
{
    size_t check = 0;
    for (size_t i = 0; i < this->capacity; i++)
        this->Get(i, &check)->Delete();
    delete this;
}


