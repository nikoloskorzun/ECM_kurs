#include "exec.h"


inline void timeit(FunctionPtr* func, char* text_hint, const int argcount, ...) {
    /// <summary>
    /// ... is char*, zero point is argcount
    /// </summary>
    /// <param name="func">function</param>
    /// <param name="argcount">count of arguments</param>
    /// <param name="">FUNCTION UNNECESSORY-ARGUMENTS</param>
    /// loop number is a counter of usages of timeit function
    static int loop_number = 0;
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
    loop_number++;
    printf("%i. %s", loop_number, text_hint);
    printf("\n\t\tTIME IS %i\n", (end_ms - startup_ms));
}

void perform_integers() {

    int16_t *x, *y;
    x = (int16_t*)malloc(NumberOfElementsArray * sizeof(int16_t));
    y = (int16_t*)malloc(NumberOfElementsArray * sizeof(int16_t));



    timeit(add16_reg, "SUM OF INTEGERS", 3, NumberOfElementsArray, x, y);
    free(x);
    free(y);
}

void perform_floats() {
    float *x_f, *y_f;
    x_f = (float32_t*)malloc(NumberOfElementsArray * sizeof(float32_t));
    y_f = (float32_t*)malloc(NumberOfElementsArray * sizeof(float32_t));
    for (int i = 0; i < NumberOfElementsArray; i++) {
        x_f[i] = (float32_t)rand();
        x_f[i] += (float32_t)(rand() % 100) / 100;
        y_f[i] = (float32_t)rand();
        y_f[i] += (float32_t)(rand() % 100) / 100;
    }
    // binar
    timeit(add_floating, "SUM OF FLOATING POINT", 3, NumberOfElementsArray, x_f, y_f);
    timeit(sub_floating, "SUB OF FLOATING POINT", 3, NumberOfElementsArray, x_f, y_f);
    timeit(mul_floating, "MUL OF FLOATING POINT", 3, NumberOfElementsArray, x_f, y_f);
    timeit(div_floating, "DIV OF FLOATING POINT", 3, NumberOfElementsArray, x_f, y_f);
    // unar
    timeit(sqrt_floating, "SQRT OF FLOATING POINT", 2, NumberOfElementsArray, x_f);
    timeit(l2_floating, "LOG2 OF FLOATING POINT", 2, NumberOfElementsArray, x_f);
    timeit(ln_floating, "LN OF FLOATING POINT", 2, NumberOfElementsArray, x_f);
    
    free(x_f);
    free(y_f);
}