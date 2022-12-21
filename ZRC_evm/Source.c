#include "stdlib.h"


#include "exec.h"



int main_()
{

    char a[] = { 4, 5 ,6 };

    __asm
    {
        lea esi, a
        NEG[esi]

    }
    return 0;
}


int main()
{

    __asm
    {
        mov eax, 0;
        push eax;

        call time
        add esp, 4;
        push eax

        call srand;
        add esp, 4;

        call perform_numbers;
    }

    return 0;
}
