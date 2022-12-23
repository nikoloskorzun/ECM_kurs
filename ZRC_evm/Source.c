#include "stdlib.h"


#include "exec.h"

int main()
{
    


    //perform_float_reg();
    //perform_double_reg();
    //return 1;
    __asm
    {
        mov eax, 0;
        push eax;

        call time
            add esp, 4;
        push eax

            call srand;
        add esp, 4;

        call performance_comparison;
    }




    return 0;
}
