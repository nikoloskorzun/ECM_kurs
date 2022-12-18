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


    char format1[] = "%i. %s";
    char format2[] = "\n\t\tTIME IS %i\n";

    __asm {
        CMP argcount, 0
        JE ZERO_ARG

        lea esi, argcount;
        
        ; size of stack for call func is argcount * 4
        mov eax, argcount;
        mov ebx, 4
        mul ebx;
        
        mov accum, eax;
        add esi, eax;
        mov ecx, argcount
           
        PushArgs :
            push[esi];
            sub esi, 4; move back
        loop PushArgs;

        ZERO_ARG:

        call clock; get start ticks
        mov startup_ms, eax;
        
        call[func];
        
        add esp, accum;
        
        call clock; get old ticks
        mov end_ms, eax;


        mov eax, text_hint
        push eax
        mov eax, loop_number
        push eax
        lea eax, format1
        push eax

        call printf
        add esp, 12;

        mov eax, end_ms
        mov ebx, startup_ms
        sub eax, ebx
        push eax
        lea eax, format2
        push eax
        call printf
        add esp, 8;






        inc loop_number
    }
    //printf("%i. %s", loop_number, text_hint);
    //printf("\n\t\tTIME IS %i\n", (end_ms - startup_ms));
}


void perform_integers()
{
    perform_signed_integers();
    perform_unsigned_integers();

}

void perform_signed_integers()
{


    //zero time test
    timeit(empty_function, "EMPTY FUNCTION", 0);


    int8_t* x_8, * y_8, * x_for_div_8;
    x_8 = (int8_t*)malloc(NumberOfElementsArray * sizeof(int8_t));
    y_8 = (int8_t*)malloc(NumberOfElementsArray * sizeof(int8_t));
    x_for_div_8 = (int8_t*)malloc(NumberOfElementsArray * sizeof(int8_t));


    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_8[i] = (int8_t)(((rand()) % (UINT8_MAX)) + INT8_MIN + 1);
        y_8[i] = (int8_t)(((rand()) % (UINT8_MAX)) + INT8_MIN + 1); 

        do
        {
            x_for_div_8[i] = (int8_t)(((rand()) % (UINT8_MAX)) + INT8_MIN + 1);
        } while (!x_for_div_8[i]);

    }

    //bin

    printf("signed int8\n");

    timeit(add8_reg_signed, "SUM OF INTEGERS[8 bit]", 3, NumberOfElementsArray, x_8, y_8);
    timeit(sub8_reg_signed, "SUB OF INTEGERS[8 bit]", 3, NumberOfElementsArray, x_8, y_8);
    timeit(mul8_reg_signed, "MUL OF INTEGERS[8 bit]", 3, NumberOfElementsArray, x_8, y_8);
    timeit(div8_reg_signed, "DIV OF INTEGERS[8 bit]", 3, NumberOfElementsArray, x_for_div_8, y_8);//y/x

    timeit(XOR8_reg_signed, "XOR OF INTEGERS[8 bit]", 3, NumberOfElementsArray, x_8, y_8);
    timeit(AND8_reg_signed, "AND OF INTEGERS[8 bit]", 3, NumberOfElementsArray, x_8, y_8);
    timeit(OR8_reg_signed, "OR OF INTEGERS[8 bit]", 3, NumberOfElementsArray, x_8, y_8);


    //unar
    timeit(NOT8_reg_signed, "NOT OF INTEGERS[8 bit]", 2, NumberOfElementsArray, x_8);
    timeit(neg8_reg_signed, "NEG OF INTEGERS[8 bit]", 2, NumberOfElementsArray, x_8);



    free(x_8);
    free(y_8);
    free(x_for_div_8);





    int16_t *x_16, *y_16, *x_for_div_16;
    x_16 = (int16_t*)malloc(NumberOfElementsArray * sizeof(int16_t));
    y_16 = (int16_t*)malloc(NumberOfElementsArray * sizeof(int16_t));
    x_for_div_16 = (int16_t*)malloc(NumberOfElementsArray * sizeof(int16_t));


    for (int i = 0; i < NumberOfElementsArray; i++) 
    {
        x_16[i] = (int16_t)(((((rand() % 2) << 15) + rand()) % (UINT16_MAX )) + INT16_MIN + 1);
        y_16[i] = (int16_t)(((((rand() % 2) << 15) + rand()) % (UINT16_MAX )) + INT16_MIN + 1);

        do
        {
            x_for_div_16[i] = (int16_t)(((((rand()%2) << 15) + rand()) % (UINT16_MAX)) + INT16_MIN + 1);
        } while (!x_for_div_16[i]);
        
    }

    //bin

    printf("signed int16\n");

    timeit(add16_reg_signed, "SUM OF INTEGERS[16 bit]", 3, NumberOfElementsArray, x_16, y_16);
    timeit(sub16_reg_signed, "SUB OF INTEGERS[16 bit]", 3, NumberOfElementsArray, x_16, y_16);
    timeit(mul16_reg_signed, "MUL OF INTEGERS[16 bit]", 3, NumberOfElementsArray, x_16, y_16);
    timeit(div16_reg_signed, "DIV OF INTEGERS[16 bit]", 3, NumberOfElementsArray, x_for_div_16, y_16);//y/x

    timeit(XOR16_reg_signed, "XOR OF INTEGERS[16 bit]", 3, NumberOfElementsArray, x_16, y_16);
    timeit(AND16_reg_signed, "AND OF INTEGERS[16 bit]", 3, NumberOfElementsArray, x_16, y_16);
    timeit(OR16_reg_signed, "OR OF INTEGERS[16 bit]", 3, NumberOfElementsArray, x_16, y_16);


    //unar
    timeit(NOT16_reg_signed, "NOT OF INTEGERS[16 bit]", 2, NumberOfElementsArray, x_16);
    timeit(neg16_reg_signed, "NEG OF INTEGERS[16 bit]", 2, NumberOfElementsArray, x_16);



    free(x_16);
    free(y_16);
    free(x_for_div_16);

    int32_t* x_32, * y_32, * x_for_div_32;
    x_32 = (int32_t*)malloc(NumberOfElementsArray * sizeof(int32_t));
    y_32 = (int32_t*)malloc(NumberOfElementsArray * sizeof(int32_t));
    x_for_div_32 = (int32_t*)malloc(NumberOfElementsArray * sizeof(int32_t));


    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_32[i] = (int32_t)((((rand() << 17) + ((rand() % 4) << 15) + rand()) % (UINT32_MAX)) + INT32_MIN + 1);
        y_32[i] = (int32_t)((((rand() << 17) + ((rand() % 4) << 15) + rand()) % (UINT32_MAX)) + INT32_MIN + 1);
        
        do
        {
            x_for_div_32[i] = (int32_t)((((rand() << 17) + ((rand() % 4) << 15) + rand()) % (UINT32_MAX)) + INT32_MIN + 1);
        } while (!x_for_div_32[i]);

    }


    printf("signed int32\n");
    //bin
    timeit(add32_reg_signed, "SUM OF INTEGERS[32 bit]", 3, NumberOfElementsArray, x_32, y_32);
    timeit(sub32_reg_signed, "SUB OF INTEGERS[32 bit]", 3, NumberOfElementsArray, x_32, y_32);
    timeit(mul32_reg_signed, "MUL OF INTEGERS[32 bit]", 3, NumberOfElementsArray, x_32, y_32);
    timeit(div32_reg_signed, "DIV OF INTEGERS[32 bit]", 3, NumberOfElementsArray, x_for_div_32, y_32); //y/x

    timeit(XOR32_reg_signed, "XOR OF INTEGERS[32 bit]", 3, NumberOfElementsArray, x_32, y_32);
    timeit(AND32_reg_signed, "AND OF INTEGERS[32 bit]", 3, NumberOfElementsArray, x_32, y_32);
    timeit(OR32_reg_signed, "OR OF INTEGERS[32 bit]", 3, NumberOfElementsArray, x_32, y_32);

    //unar
    timeit(NOT32_reg_signed, "NOT OF INTEGERS[32 bit]", 2, NumberOfElementsArray, x_32);
    timeit(neg32_reg_signed, "NEG OF INTEGERS[32 bit]", 2, NumberOfElementsArray, x_32);



    free(x_32);
    free(y_32);
    free(x_for_div_32);


}



void perform_unsigned_integers()
{



    uint8_t* x_8, * y_8, * x_for_div_8;
    x_8 = (uint8_t*)malloc(NumberOfElementsArray * sizeof(uint8_t));
    y_8 = (uint8_t*)malloc(NumberOfElementsArray * sizeof(uint8_t));
    x_for_div_8 = (uint8_t*)malloc(NumberOfElementsArray * sizeof(uint8_t));


    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_8[i] = (uint8_t)(((rand()) % (UINT8_MAX))); 
        y_8[i] = (uint8_t)(((rand()) % (UINT8_MAX)));

        do
        {
            x_for_div_8[i] = (uint8_t)(((rand()) % (UINT8_MAX)));
        } while (!x_for_div_8[i]);

    }

    //bin

    printf("unsigned int8\n");

    timeit(add8_reg_unsigned, "SUM OF INTEGERS[8 bit]", 3, NumberOfElementsArray, x_8, y_8);
    timeit(sub8_reg_unsigned, "SUB OF INTEGERS[8 bit]", 3, NumberOfElementsArray, x_8, y_8);
    timeit(mul8_reg_unsigned, "MUL OF INTEGERS[8 bit]", 3, NumberOfElementsArray, x_8, y_8);
    timeit(div8_reg_unsigned, "DIV OF INTEGERS[8 bit]", 3, NumberOfElementsArray, x_for_div_8, y_8);//y/x

    timeit(XOR8_reg_unsigned, "XOR OF INTEGERS[8 bit]", 3, NumberOfElementsArray, x_8, y_8);
    timeit(AND8_reg_unsigned, "AND OF INTEGERS[8 bit]", 3, NumberOfElementsArray, x_8, y_8);
    timeit(OR8_reg_unsigned, "OR OF INTEGERS[8 bit]", 3, NumberOfElementsArray, x_8, y_8);


    //unar
    timeit(NOT8_reg_unsigned, "NOT OF INTEGERS[8 bit]", 2, NumberOfElementsArray, x_8);



    free(x_8);
    free(y_8);
    free(x_for_div_8);





    uint16_t* x_16, * y_16, * x_for_div_16;
    x_16 = (uint16_t*)malloc(NumberOfElementsArray * sizeof(uint16_t));
    y_16 = (uint16_t*)malloc(NumberOfElementsArray * sizeof(uint16_t));
    x_for_div_16 = (uint16_t*)malloc(NumberOfElementsArray * sizeof(uint16_t));


    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_16[i] = (uint16_t)(((((rand() % 2) << 15) + rand()) % (UINT16_MAX)));
        y_16[i] = (uint16_t)(((((rand() % 2) << 15) + rand()) % (UINT16_MAX)));

        do
        {
            x_for_div_16[i] = (uint16_t)(((((rand() % 2) << 15) + rand()) % (UINT16_MAX)) );
        } while (!x_for_div_16[i]);

    }

    //bin

    printf("unsigned int16\n");

    timeit(add16_reg_unsigned, "SUM OF INTEGERS[16 bit]", 3, NumberOfElementsArray, x_16, y_16);
    timeit(sub16_reg_unsigned, "SUB OF INTEGERS[16 bit]", 3, NumberOfElementsArray, x_16, y_16);
    timeit(mul16_reg_unsigned, "MUL OF INTEGERS[16 bit]", 3, NumberOfElementsArray, x_16, y_16);
    timeit(div16_reg_unsigned, "DIV OF INTEGERS[16 bit]", 3, NumberOfElementsArray, x_for_div_16, y_16);//y/x

    timeit(XOR16_reg_unsigned, "XOR OF INTEGERS[16 bit]", 3, NumberOfElementsArray, x_16, y_16);
    timeit(AND16_reg_unsigned, "AND OF INTEGERS[16 bit]", 3, NumberOfElementsArray, x_16, y_16);
    timeit(OR16_reg_unsigned, "OR OF INTEGERS[16 bit]", 3, NumberOfElementsArray, x_16, y_16);


    //unar
    timeit(NOT16_reg_unsigned, "NOT OF INTEGERS[16 bit]", 2, NumberOfElementsArray, x_16);



    free(x_16);
    free(y_16);
    free(x_for_div_16);

    uint32_t* x_32, * y_32, * x_for_div_32;
    x_32 = (uint32_t*)malloc(NumberOfElementsArray * sizeof(uint32_t));
    y_32 = (uint32_t*)malloc(NumberOfElementsArray * sizeof(uint32_t));
    x_for_div_32 = (uint32_t*)malloc(NumberOfElementsArray * sizeof(uint32_t));


    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_32[i] = (uint32_t)((((rand() << 17) + ((rand() % 4) << 15) + rand()) % (UINT32_MAX)));
        y_32[i] = (uint32_t)((((rand() << 17) + ((rand() % 4) << 15) + rand()) % (UINT32_MAX)));

        do
        {
            x_for_div_32[i] = (uint32_t)((((rand() << 17) + ((rand() % 4) << 15) + rand()) % (UINT32_MAX)));
        } while (!x_for_div_32[i]);

    }


    printf("unsigned int32\n");
    //bin
    timeit(add32_reg_unsigned, "SUM OF INTEGERS[32 bit]", 3, NumberOfElementsArray, x_32, y_32);
    timeit(sub32_reg_unsigned, "SUB OF INTEGERS[32 bit]", 3, NumberOfElementsArray, x_32, y_32);
    timeit(mul32_reg_unsigned, "MUL OF INTEGERS[32 bit]", 3, NumberOfElementsArray, x_32, y_32);
    timeit(div32_reg_unsigned, "DIV OF INTEGERS[32 bit]", 3, NumberOfElementsArray, x_for_div_32, y_32); //y/x

    timeit(XOR32_reg_unsigned, "XOR OF INTEGERS[32 bit]", 3, NumberOfElementsArray, x_32, y_32);
    timeit(AND32_reg_unsigned, "AND OF INTEGERS[32 bit]", 3, NumberOfElementsArray, x_32, y_32);
    timeit(OR32_reg_unsigned, "OR OF INTEGERS[32 bit]", 3, NumberOfElementsArray, x_32, y_32);

    //unar
    timeit(NOT32_reg_unsigned, "NOT OF INTEGERS[32 bit]", 2, NumberOfElementsArray, x_32);



    free(x_32);
    free(y_32);
    free(x_for_div_32);


}


void perform_floats() {
    float *x_f, *y_f;
    x_f = (float32_t*)malloc(NumberOfElementsArray * sizeof(float32_t));
    y_f = (float32_t*)malloc(NumberOfElementsArray * sizeof(float32_t));
    
    for (int i = 0; i < NumberOfElementsArray; i++) 
    {
        
        
        
        x_f[i] = (float)(((double)((rand() << 17) + ((rand() % 4) << 15) + rand()) / (double)(UINT32_MAX)) * (((double)(FLT_MAX)) + (double)(FLT_MAX)) + (double)(-FLT_MIN));
        y_f[i] = (float)(((double)((rand() << 17) + ((rand() % 4) << 15) + rand()) / (double)(UINT32_MAX)) * (((double)(FLT_MAX)) + (double)(FLT_MAX)) + (double)(-FLT_MIN));



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


void empty_function(){}
