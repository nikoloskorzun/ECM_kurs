#include "stdlib.h"


#include "exec.h"


int main()
{
    unsigned a = 64;
    unsigned b = 64;

    int i = 64;
    int j = 64;
    int* z = &i;
    printf("%i, %i \n", i, j);
    __asm
    {
        
        mov eax, j
        add i, eax
        
        //mov j, eax
    }
    printf("%i, %i\n", i, j);
    return 0;
}


int main_()
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
