#include "integers.h"
void add16_reg_signed(int _size, int16_t* a, int16_t* b)
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
            mov ax, [esi];
            mov bx, [edi];
            add ax, bx;
            add esi, 2
            add edi, 2
        loop CYCLE;
    }
}

void sub16_reg_signed(int _size, int16_t* a, int16_t* b)
{
    /// <summary>
    /// sub func for int16_t
    /// </summary>
    /// <param name="a">first member</param>
    /// <param name="b">second member</param>

    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
        CYCLE:
            mov ax, [esi];
            mov bx, [edi];
            sub ax, bx;
            add esi, 2
            add edi, 2
        loop CYCLE;
    }
}


void mul16_reg_signed(int _size, int16_t* a, int16_t* b)
{
    /// <summary>
    /// mul func for int16_t
    /// </summary>
    /// <param name="a">first member</param>
    /// <param name="b">second member</param>

    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
        CYCLE:
            mov ax, [esi];
            mov bx, [edi];
            imul ax, bx;
            add esi, 2
            add edi, 2
        loop CYCLE;
    }
}

void div16_reg_signed(int _size, int16_t* a, int16_t* b)
{
    /// <summary>
    /// div func for int16_t
    /// </summary>
    /// <param name="a">first member</param>
    /// <param name="b">second member</param>

    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
        CYCLE:
            mov ax, [esi];
            mov bx, [edi];
            cwd;
            idiv bx;
            add esi, 2
            add edi, 2
        loop CYCLE;
    }
}



void neg16_reg_signed(int _size, int16_t* a)
{
    __asm
    {
        mov ecx, _size;
        mov esi, a;
        CYCLE:
            mov ax, [esi]
            NEG ax
            add esi, 2
        loop CYCLE;
    }


}

void NOT16_reg_signed(int _size, int16_t* a)
{
    __asm
    {
        mov ecx, _size;
        mov esi, a;
        CYCLE:
            mov ax, [esi]
            NOT ax
            add esi, 2
        loop CYCLE;
    }
}

void XOR16_reg_signed(int _size, int16_t* a, int16_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
        CYCLE:
            mov ax, [esi];
            mov bx, [edi];
            xor ax, bx;
            add esi, 2
            add edi, 2
        loop CYCLE;
    }


}

void OR16_reg_signed(int _size, int16_t* a, int16_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
        CYCLE:
            mov ax, [esi];
            mov bx, [edi];
            or ax, bx;
            add esi, 2
            add edi, 2
        loop CYCLE;
    }
}

void AND16_reg_signed(int _size, int16_t* a, int16_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
        CYCLE:
            mov ax, [esi];
            mov bx, [edi];
            and ax, bx;
            add esi, 2
            add edi, 2
        loop CYCLE;
    }
}











void add16_mem_signed_left(int _size, int16_t* a, int16_t* b)
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
        mov bx, [edi];
        add[esi], bx;
        add esi, 2
            add edi, 2
            loop CYCLE;
    }
}

void add16_mem_signed_right(int _size, int16_t* a, int16_t* b)
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
        mov ax, [esi]
            add ax, [edi];
        add esi, 2
            add edi, 2
            loop CYCLE;
    }
}


void sub16_mem_signed_left(int _size, int16_t* a, int16_t* b)
{
    /// <summary>
    /// sub func for int16_t
    /// </summary>
    /// <param name="a">first member</param>
    /// <param name="b">second member</param>

    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
    CYCLE:
        mov bx, [edi];
        sub[esi], bx;
        add esi, 2
            add edi, 2
            loop CYCLE;
    }
}

void sub16_mem_signed_right(int _size, int16_t* a, int16_t* b)
{
    /// <summary>
    /// sub func for int16_t
    /// </summary>
    /// <param name="a">first member</param>
    /// <param name="b">second member</param>

    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
    CYCLE:
        mov ax, [esi];
        sub ax, [edi];
        add esi, 2
            add edi, 2
            loop CYCLE;
    }
}




void mul16_mem_signed(int _size, int16_t* a, int16_t* b)
{
    /// <summary>
    /// mul func for int16_t
    /// </summary>
    /// <param name="a">first member</param>
    /// <param name="b">second member</param>

    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
    CYCLE:
        mov ax, [esi];
        imul ax, [edi];
        add esi, 2
            add edi, 2
            loop CYCLE;
    }
}




void div16_mem_signed(int _size, int16_t* a, int16_t* b)
{
    /// <summary>
    /// div func for int16_t
    /// </summary>
    /// <param name="a">first member</param>
    /// <param name="b">second member</param>

    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
    CYCLE:
        mov ax, [esi];
        
        cwd;
        idiv word ptr[edi];
        add esi, 2
            add edi, 2
            loop CYCLE;
    }
}



void neg16_mem_signed(int _size, int16_t* a)
{
    __asm
    {
        mov ecx, _size;
        mov esi, a;
    CYCLE:
        NEG[esi]
            add esi, 2
            loop CYCLE;
    }


}

void NOT16_mem_signed(int _size, int16_t* a)
{
    __asm
    {
        mov ecx, _size;
        mov esi, a;
    CYCLE:
        NOT[esi]
            add esi, 2
            loop CYCLE;
    }
}

void XOR16_mem_signed_left(int _size, int16_t* a, int16_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
    CYCLE:
        mov bx, [edi];
        xor [esi], bx;
        add esi, 2
            add edi, 2
            loop CYCLE;
    }
}

void XOR16_mem_signed_right(int _size, int16_t* a, int16_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
    CYCLE:
        mov ax, [esi];
        xor ax, [edi];
        add esi, 2
            add edi, 2
            loop CYCLE;
    }
}

void OR16_mem_signed_left(int _size, int16_t* a, int16_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
    CYCLE:
        mov bx, [edi];
        or [esi], bx;
        add esi, 2
            add edi, 2
            loop CYCLE;
    }
}

void OR16_mem_signed_right(int _size, int16_t* a, int16_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
    CYCLE:
        mov ax, [esi];
        or ax, [edi];
        add esi, 2
            add edi, 2
            loop CYCLE;
    }
}

void AND16_mem_signed_left(int _size, int16_t* a, int16_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
    CYCLE:
        mov bx, [edi];
        and [esi], bx;
        add esi, 2
            add edi, 2
            loop CYCLE;
    }
}


void AND16_mem_signed_right(int _size, int16_t* a, int16_t* b)
{
    __asm
    {
        mov ecx, _size;
        mov edi, a;
        mov esi, b;
    CYCLE:
        mov ax, [esi];
        and ax, [edi];
        add esi, 2
            add edi, 2
            loop CYCLE;
    }
}

