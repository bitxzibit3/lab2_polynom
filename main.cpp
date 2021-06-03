#include "Sequence.cpp"
#include "Polynom.cpp"
#include "complex.cpp"
#include "Menu+helpful functions.cpp"
#include "Library.cpp"

int VAR = variable_choise();

const int SEQTYPE = 2; // Используем динамический массив (1 - односвязный список), так как с массивом быстрее.

int main()
{
    while (1) {
        switch (VAR) {
            case(0):
            {
                return 0;
            }
            case (1): {
                VAR = dialog<int>(SEQTYPE);
                break;
            }
            case (2): {
                VAR = dialog<float>(SEQTYPE);
                break;
            }
            case (3): {
                VAR = dialog<complex>(SEQTYPE);
                break;
            }
        }
    }
}
