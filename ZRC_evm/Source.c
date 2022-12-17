#include "stdlib.h"
#include "exec.h"

#define NumberOfElementsArray 21474836


int main() {
    __asm {
        mov eax, 0;
        push eax;
        call srand;
        add esp, 4;
        call perform_integers;
        call perform_floats;
    }
}
