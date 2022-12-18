#include "integers.h"




void NOT32_reg_unsigned(int _size, int32_t* a)
{
    __asm
    {
        mov ecx, _size;
        mov esi, a;
        CYCLE:
            mov eax, [esi]
            NOT eax
            add esi, 4
        loop CYCLE;
    }
}

void XOR32_reg_unsigned(int _size, int32_t* a, int32_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
        CYCLE:
            mov eax, [esi];
            mov ebx, [edi];
            xor eax, ebx;
            add esi, 4
            add edi, 4
        loop CYCLE;
    }
}

void OR32_reg_unsigned(int _size, int32_t* a, int32_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
        CYCLE:
            mov eax, [esi];
            mov ebx, [edi];
            or eax, ebx;
            add esi, 4
            add edi, 4
        loop CYCLE;
    }
}

void AND32_reg_unsigned(int _size, int32_t* a, int32_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
        CYCLE:
            mov eax, [esi];
            mov ebx, [edi];
            and eax, ebx;
            add esi, 4
            add edi, 4
        loop CYCLE;
    }
}


void add32_reg_unsigned(int _size, int32_t* a, int32_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
        CYCLE:
            mov eax, [esi];
            mov ebx, [edi];
            add eax, ebx;
            add esi, 4
            add edi, 4
        loop CYCLE;
    }
}


void sub32_reg_unsigned(int _size, int32_t* a, int32_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
        CYCLE:
            mov eax, [esi];
            mov ebx, [edi];
            sub eax, ebx;
            add esi, 4
            add edi, 4
        loop CYCLE;
    }
}

void mul32_reg_unsigned(int _size, int32_t* a, int32_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
        CYCLE:
            mov eax, [esi];
            mov ebx, [edi];
            mul ebx;
            add esi, 4
            add edi, 4
        loop CYCLE;
    }

}

void div32_reg_unsigned(int _size, int32_t* a, int32_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
        CYCLE:
            mov eax, [esi];
            mov ebx, [edi];
            mov edx, 0
            //cdq;
            div ebx;
            add esi, 4
            add edi, 4
        loop CYCLE;
    }
}




