#include "stdio.h"
#include "time.h"

#define N 3

typedef void(*FunctionPtr)();
typedef signed short int16_t;
typedef char int8_t;



inline void timeit(FunctionPtr* func, const int argcount, ...) {
    /// <summary>
    /// ... is char*, zero point is argcount
    /// </summary>
    /// <param name="func">function</param>
    /// <param name="argcount">count of arguments</param>
    /// <param name="">FUNCTION UNNECESSORY-ARGUMENTS</param>
    int accum = 0;
    int startup_ms, end_ms;
    double time_spent = 0.0;

    __asm {
        lea esi, argcount;

        //
        ; size of stack for call func is argcount * 4

            mov eax, argcount;
        mov ebx, 4
            mul ebx;
        mov accum, eax;
        add esi, eax;
        mov ecx, argcount
            //
            PushArgs :
        push[esi];
        sub esi, 4; move back
            loop PushArgs;
        call clock; get start ticks
            mov startup_ms, eax;
        call[func];
        add esp, accum;
        call clock; get old ticks
            mov end_ms, eax;

    }
    printf("END TIME IS %i", (end_ms - startup_ms));
}


void add16_reg(int size_, int16_t* a, int16_t* b) {
    /// <summary>
    /// add func for int16_t
    /// </summary>
    /// <param name="a">first member</param>
    /// <param name="b">second member</param>
    printf("adr in add16 1, 2: %u %u\n", a, b);
    printf("adr in add16 1, 2: %i %i\n", a, b);

    __asm {
        mov ecx, size_;
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


int main() {
    srand(0);

    int16_t* x, * y;
    x = (int16_t*)malloc(N * sizeof(int16_t));
    y = (int16_t*)malloc(N * sizeof(int16_t));

    printf("adr in main  1, 2: %u %u\n", x, y);
    printf("adr in main  1, 2: %i %i\n", x, y);

    for (int i = 0; i < N; i++) {
        x[i] = (int16_t)rand();
        y[i] = (int16_t)rand();
    }

    timeit(add16_reg, 3, N, x, y);


    free(x);
    free(y);

}
