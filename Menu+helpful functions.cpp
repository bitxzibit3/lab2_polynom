//
// Created by Timur on 29.05.2021.
//

#include "Menu+helpful functions.h"
#include <time.h>

int stoi (char *str)
{
    int ans = 0, i = 0;
    int sign = (str[0] == '-') ? -1: (((str[0] >= '0') && (str[0] <= '9')) ? 1: 0);
    if (sign == 0)
        return -1;
    while (str[i] != '\0')
    {
        if ((str[i] <= '9') && (str[i] >= '0'))
            ans = 10 * ans + str[i] - '0';
        else
            return -1;
        i++;
    }
    return sign * ans;
}

int variable_choise()
{
    while (1)
    {
        std::cout << "What type of data do you wanna use?" << std::endl << "1. Integer" << std::endl << "2. Float" << std::endl << "3. Complex" << std::endl;
        char *c = new char (100);
        std::cin >> c;
        int ans = stoi (c);
        delete c;
        if ((ans > 0) && (ans < 4))
            return ans;
        else
            std::cout << "You entered a wrong number, plaese, try again!" << std::endl;
    }
}

int choise_()
{
    while (1) {
        char *ch = new char (100);
        std::cout << "What do you wanna do?" << std::endl;
        for (size_t i = 0; i < MSGS_SIZE; i++)
            std::cout << MSGS[i] << std::endl;
        std::cin >> ch;
        int choise = stoi(ch);
        delete ch;
        if ((choise >= 0) && (choise < MSGS_SIZE))
            return choise;
        else
            std::cout << "You entered a wrong number, plaese, try again!" << std::endl;
        }
}


template <class T>
int dialog(int seq)
{
    Library<T> *lib = new Library<T> (seq);
    int choise = choise_();
    while (1)
    switch (choise)
    {
        case(0):
        {
            lib->Delete();
            std::cout << "Good Bye!" << std::endl;
            return 0;
        }
        case(1):
        {
            Polynom<T> *first = GetPolynom(lib, seq);
            Polynom<T> *second = GetPolynom(lib, seq);
            std::cout << "You entered P(x): ";
            first->Print();
            std::cout << "You entered S(x): ";
            second->Print();
            std::cout << "Sum of polynoms (P(x) + S(x)): ";
            Polynom<T> *ans = PolynomSum(first, second);
            ans->Print();
            SavePolynom(lib, first);
            SavePolynom(lib, second);
            SavePolynom(lib, ans);
            choise = choise_();
            break;
        }
        case(2):
        {
            Polynom<T> *first = GetPolynom(lib, seq);
            Polynom<T> *second = GetPolynom(lib, seq);
            std::cout << "You entered P(x): ";
            first->Print();
            std::cout << "You entered S(x): ";
            second->Print();
            std::cout << "Multiplication of polynoms (P(x) * S(x)): ";
            Polynom<T> *ans = PolynomMult(first, second);
            ans->Print();
            SavePolynom(lib, first);
            SavePolynom(lib, second);
            SavePolynom(lib, ans);
            choise = choise_();
            break;
        }
        case(3):
        {
            Polynom<T> *first = GetPolynom(lib, seq);
            std::cout << "Enter degree q: ";
            size_t coef;
            std::cin >> coef;
            std::cout << "You entered P(x): ";
            first->Print();
            std::cout << "Polynom's power (P(x) ^ " << coef << "): ";
            Polynom<T> *ans = PolynomDegree(first, coef);
            ans->Print();
            SavePolynom(lib, first);
            SavePolynom(lib, ans);
            choise = choise_();
            break;
        }
        case(4):
        {
            Polynom<T> *first = GetPolynom(lib, seq);
            Polynom<T> *second = GetPolynom(lib, seq);
            std::cout << "You entered P(x): ";
            first->Print();
            std::cout << "You entered S(x): ";
            second->Print();
            std::cout << "Composition of polynoms (P(S(X))): ";
            Polynom<T> *ans = PolynomComp(first, second);
            ans->Print();
            SavePolynom(lib, first);
            SavePolynom(lib, second);
            SavePolynom(lib, ans);
            choise = choise_();
            break;
        }
        case(5):
        {
            Polynom<T> *first = GetPolynom(lib, seq);
            T x;
            std::cout << "Enter value (x) :";
            std::cin >> x;
            std::cout << "You entered P(x): ";
            first->Print();
            std::cout << "P(" << x << ") = " << first->CountValue(x) << std::endl;
            SavePolynom(lib, first);
            choise = choise_();
            break;
        }
        case(6):
        {
            Polynom<T> *first = GetPolynom(lib, seq);
            std::cout << "You entered P(x): ";
            first->Print();
            Polynom<T> *ans = first->Derriativte();
            std::cout << "P'(x) = ";
            ans->Print();
            SavePolynom(lib, first);
            SavePolynom(lib, ans);
            choise = choise_();
            break;
        }
        case(7):
        {
            Polynom<T> *first = GetPolynom(lib, seq);
            Polynom<T> *second = GetPolynom(lib, seq);
            std::cout << "You entered P(x): ";
            first->Print();
            std::cout << "You entered S(x): ";
            second->Print();
            Sequence<T> *ans = first->GetData()->Concat(second->GetData());
            Polynom<T> *answer = new_Polynom(ans, seq);
            std::cout << "Result of concatanation :";
            answer->Print();
            SavePolynom(lib, first);
            SavePolynom(lib, second);
            SavePolynom(lib, answer);
            delete ans;
            choise = choise_();
            break;
        }
        case(8):
        {
            size_t checker = 0;
            Polynom<T> *first = GetPolynom(lib, seq);
            size_t begin, end;
            std::cout << "Enter exact scopes of result polynom (from 0 to " << first->Size() - 1 << "): ";
            while (1)
            {
                std::cin >> begin >> end;
                if ((end < begin) || (begin < 0) || (begin >= first->Size()) || (end >= first->Size())) {
                    std::cout << "Wrong scopes! Please, try again!" << std::endl;
                }
                else {
                    break;
                }
            }
            std::cout << "You entered P(x): ";
            first->Print();
            Sequence<T> *ans = first->GetData()->GetSubSeq(begin, end, &checker);
            for (size_t i = 0; i < begin; i++)
                ans->Prepend((T)0.);
            Polynom<T> *answer = new_Polynom(ans, seq);
            answer->Print();
            SavePolynom(lib, first);
            SavePolynom(lib, answer);
            delete ans;
            choise = choise_();
            break;
        }
        case (9):
        {
            lib->Delete();
            return variable_choise();
        }
        case (10):
        {
            lib->Display();
            choise = choise_();
            break;
        }
    }
}

template<class T>
void SavePolynom(Library<T> *lib, Polynom<T> *pol)
{
    while(true)
    {
        std::cout << "Add polynom ";
        pol->Print();
        std::cout << "to a library?(y/n)";
        char c;
        std::cin >> c;
        if ((c == 'y') || (c == 'Y'))
        {
            lib->Add(pol);
            return;
        }
        else if ((c == 'n') || (c == 'N'))
        {
            delete pol;
            return;
        }
        else
        {
            std::cout << "You entered a wrong symbol, please, try again!" << std::endl;
        }
    }
}

template<class T>
Polynom<T> *GetPolynom(Library<T> *lib, int seq)
{
    size_t checker;
    while(true)
    {
        std::cout << "1. Input polynom from keyboard" << std::endl << "2. Get polynom from library" << std::endl;
        char *ch_ = new char(10);
        std::cin >> ch_;
        int ch = stoi(ch_);
        if ((ch != 1) && (ch != 2))
            std::cout << "You entered wrong number, please, try again!" << std::endl;
        else
        {
            if (ch == 1)
                return PolynomEnter<T>(seq);
            if ((ch == 2) && (lib->Size() > 0))
            {
                lib->Display();
                std::cout << "Enter number of selected polynom:";
                while(1)
                {
                    //delete ch_;
                    std::cin >> ch_;
                    ch = stoi(ch_);
                    if ((ch < 0) || (ch >= lib->Size()))
                        std::cout << "You entered a wrong number, please, try again" << std::endl;
                    else
                        break;
                }
                delete ch_;
                return lib->Get(ch, &checker)->Copy();
            }
            else if (ch == 2)
            {
                std::cout << "No one polynom in library, try again!" << std::endl;
            }
        }
    }
}

template<class T>
Sequence<T> *Where(char sign, T number, bool (*foo)(char, T, T), Sequence<T> *data, int seq_type)
{
    size_t checker = 0;
    Sequence<T> *ans;
    if (seq_type == 1)
        ans = (Sequence<T> *) new ListSeq<T> ();
    else
        ans = (Sequence<T> *) new ArrSeq<T> ();
    size_t rez_size = 0;
    for (size_t i = 0; i < data->GetSize(); i++)
        if (foo(sign, number, data->Get(i, &checker)) == true)
            ans->Append(data->Get(i, &checker));
        else
            ans->Append((T)0.);
    return ans;
}



template<class T>
Polynom<T> *GenPolynom(size_t length, int seq)
{
    size_t checker = 0;
    //srand(time(NULL));
    Polynom<T> *ans = new_Polynom<T>(seq);
    ans->Resize(length);
    for (size_t i = 0; i < length; i++) {
        T value = (T) rand() % 200 - 100;
        ans->Set(i, value, &checker);
    }
    return ans;
}
