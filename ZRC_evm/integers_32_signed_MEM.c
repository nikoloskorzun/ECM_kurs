#include "integers.h"
void add32_mem_signed_left(int _size, int32_t* a, int32_t* b)
{
    /// <summary>
    /// add func for int32_t
    /// </summary>
    /// <param name="a">first member</param>
    /// <param name="b">second member</param>

    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
    CYCLE:
        mov ebx, [edi];
        add[esi], ebx;
        add esi, 4
            add edi, 4
            loop CYCLE;
    }
}

void add32_mem_signed_right(int _size, int32_t* a, int32_t* b)
{
    /// <summary>
    /// add func for int32_t
    /// </summary>
    /// <param name="a">first member</param>
    /// <param name="b">second member</param>

    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
    CYCLE:
        mov eax, [esi]
            add eax, [edi];
        add esi, 4
            add edi, 4
            loop CYCLE;
    }
}


void sub32_mem_signed_left(int _size, int32_t* a, int32_t* b)
{
    /// <summary>
    /// sub func for int32_t
    /// </summary>
    /// <param name="a">first member</param>
    /// <param name="b">second member</param>

    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
    CYCLE:
        mov ebx, [edi];
        sub[esi], ebx;
        add esi, 4
            add edi, 4
            loop CYCLE;
    }
}

void sub32_mem_signed_right(int _size, int32_t* a, int32_t* b)
{
    /// <summary>
    /// sub func for int32_t
    /// </summary>
    /// <param name="a">first member</param>
    /// <param name="b">second member</param>

    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
    CYCLE:
        mov eax, [esi];
        sub eax, [edi];
        add esi, 4
            add edi, 4
            loop CYCLE;
    }
}




void mul32_mem_signed(int _size, int32_t* a, int32_t* b)
{
    /// <summary>
    /// mul func for int32_t
    /// </summary>
    /// <param name="a">first member</param>
    /// <param name="b">second member</param>

    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
    CYCLE:
        mov eax, [esi];
        imul eax, [edi];
        add esi, 4
            add edi, 4
            loop CYCLE;
    }
}




void div32_mem_signed(int _size, int32_t* a, int32_t* b)
{
    /// <summary>
    /// div func for int32_t
    /// </summary>
    /// <param name="a">first member</param>
    /// <param name="b">second member</param>

    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
    CYCLE:
        mov eax, [esi];
        cdq;
        idiv dword ptr[edi];
        add esi, 4
            add edi, 4
            loop CYCLE;
    }
}



void neg32_mem_signed(int _size, int32_t* a)
{
    __asm
    {
        mov ecx, _size;
        mov esi, a;
    CYCLE:
        NEG[esi]
            add esi, 4
            loop CYCLE;
    }


}

void NOT32_mem_signed(int _size, int32_t* a)
{
    __asm
    {
        mov ecx, _size;
        mov esi, a;
    CYCLE:
        NOT[esi]
            add esi, 4
            loop CYCLE;
    }
}

void XOR32_mem_signed_left(int _size, int32_t* a, int32_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
    CYCLE:
        mov ebx, [edi];
        xor [esi], ebx;
        add esi, 4
            add edi, 4
            loop CYCLE;
    }
}

void XOR32_mem_signed_right(int _size, int32_t* a, int32_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
    CYCLE:
        mov eax, [esi];
        xor eax, [edi];
        add esi, 4
            add edi, 4
            loop CYCLE;
    }
}

void OR32_mem_signed_left(int _size, int32_t* a, int32_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
    CYCLE:
        mov ebx, [edi];
        or [esi], ebx;
        add esi, 4
            add edi, 4
            loop CYCLE;
    }
}

void OR32_mem_signed_right(int _size, int32_t* a, int32_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
    CYCLE:
        mov eax, [esi];
        or eax, [edi];
        add esi, 4
            add edi, 4
            loop CYCLE;
    }
}

void AND32_mem_signed_left(int _size, int32_t* a, int32_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
    CYCLE:
        mov ebx, [edi];
        and [esi], ebx;
        add esi, 4
            add edi, 4
            loop CYCLE;
    }
}


void AND32_mem_signed_right(int _size, int32_t* a, int32_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
    CYCLE:
        mov eax, [esi];
        and eax, [edi];
        add esi, 4
            add edi, 4
            loop CYCLE;
    }
}
