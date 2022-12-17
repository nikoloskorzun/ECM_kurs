#include "integers.h"
void add16_reg(int _size, int16_t* a, int16_t* b) {
    /// <summary>
    /// add func for int16_t
    /// </summary>
    /// <param name="a">first member</param>
    /// <param name="b">second member</param>

    __asm {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
    Addition:
        mov ax, [esi];
        mov bx, [edi];
        add ax, bx;
        add esi, 2
        add edi, 2
    loop Addition;
    }
}


inline void add64_reg(long long a, long long b) {
    a + b;
}