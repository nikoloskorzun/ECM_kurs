#include "integers.h"
void add8_reg_signed(int _size, int8_t* a, int8_t* b)
{
    /// <summary>
    /// add func for int16_t
    /// </summary>
    /// <param name="a">first member</param>
    /// <param name="b">second member</param>

    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
        CYCLE:
            mov al, [esi];
            mov bl, [edi];
            add al, bl;
            add esi, 1
            add edi, 1
        loop CYCLE;
    }
}

void sub8_reg_signed(int _size, int8_t* a, int8_t* b)
{
    /// <summary>
    /// sub func for int8_t
    /// </summary>
    /// <param name="a">first member</param>
    /// <param name="b">second member</param>

    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
        CYCLE:
            mov al, [esi];
            mov bl, [edi];
            sub al, bl;
            add esi, 1
            add edi, 1
        loop CYCLE;
    }
}


void mul8_reg_signed(int _size, int8_t* a, int8_t* b)
{
    /// <summary>
    /// mul func for int8_t
    /// </summary>
    /// <param name="a">first member</param>
    /// <param name="b">second member</param>

    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
        CYCLE:
            mov al, [esi];
            mov bl, [edi];
            imul al, bl;
            add esi, 1
            add edi, 1
        loop CYCLE;
    }
}

void div8_reg_signed(int _size, int8_t* a, int8_t* b)
{
    /// <summary>
    /// div func for int8_t
    /// </summary>
    /// <param name="a">first member</param>
    /// <param name="b">second member</param>

    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
        CYCLE:
            mov al, [esi];
            mov bl, [edi];
            cbw;
            idiv bl;
            add esi, 1
            add edi, 1
        loop CYCLE;
    }
}



void neg8_reg_signed(int _size, int8_t* a)
{
    __asm
    {
        mov ecx, _size;
        mov esi, a;
        CYCLE:
            mov al, [esi]
            NEG al
            add esi, 1
        loop CYCLE;
    }


}

void NOT8_reg_signed(int _size, int8_t* a)
{
    __asm
    {
        mov ecx, _size;
        mov esi, a;
        CYCLE:
            mov al, [esi]
            NOT al
            add esi, 1
        loop CYCLE;
    }
}

void XOR8_reg_signed(int _size, int8_t* a, int8_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
        CYCLE:
            mov al, [esi];
            mov bl, [edi];
            xor al, bl;
            add esi, 1
            add edi, 1
        loop CYCLE;
    }


}

void OR8_reg_signed(int _size, int8_t* a, int8_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
        CYCLE:
            mov al, [esi];
            mov bl, [edi];
            or al, bl;
            add esi, 1
            add edi, 1
        loop CYCLE;
    }
}

void AND8_reg_signed(int _size, int8_t* a, int8_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
        CYCLE:
            mov al, [esi];
            mov bl, [edi];
            and al, bl;
            add esi, 1
            add edi, 1
        loop CYCLE;
    }
}
