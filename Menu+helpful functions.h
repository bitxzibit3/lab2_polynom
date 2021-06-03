//
// Created by Timur on 29.05.2021.
//

#ifndef LAB2_VECTOR_MENU_HELPFUL_FUNCTIONS_H
#define LAB2_VECTOR_MENU_HELPFUL_FUNCTIONS_H
#include <iostream>
#include <stdlib.h>
#include "Library.h"

int variable_choise();


const char *MSGS[] = {"0. Quit", "1. Sum polynoms", "2. Multiply polynoms", "3. Raise a polynom to a power", "4. Polynoms composotion",
                      "5. Count a value for entered x", "6. Take a derriative", "7. Concat polynoms", "8. Get SubSeq",
                      "9. Change type of variables", "10. Show a library"};
const size_t MSGS_SIZE = (sizeof(MSGS) / sizeof(MSGS[0]));

int stoi (char *);

int choise();

void dialog (int);

template <class T>
Polynom<T> *GetPolynom (Library<T> *);

template <class T>
Polynom<T> *Copy (Polynom<T> *);

template<class T>
void SavePolynom (Library<T> *, Polynom<T> *);

template <class T>
Sequence<T> *Where(char, T, bool (*)(char, T, T), Polynom<T> *, int);


template<class T>
Polynom<T> *GenPolynom (size_t, int);
#endif //LAB2_VECTOR_MENU_HELPFUL_FUNCTIONS_H
