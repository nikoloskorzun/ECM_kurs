#include "stdlib.h"


#include "exec.h"


#define NumberOfElementsArray 21474836


int main() {


    __asm {
        mov eax, 0; поменять на time(NULL) 0 стоит чтобы всегда одинаковое поведение было
        push eax;
        call srand;
        add esp, 4;
        call perform_integers;
        call perform_floats;
    }

    return 0;
}
