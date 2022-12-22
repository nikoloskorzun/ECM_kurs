#include "exec.h"


inline void timeit(FunctionPtr* func, char* text_hint, const int argcount, ...) {
    /// <ADDmary>
    /// ... is char*, zero point is argcount
    /// </ADDmary>
    /// <param name="func">function</param>
    /// <param name="argcount">count of arguments</param>
    /// <param name="">FUNCTION UNNECESSORY-ARGUMENTS</param>
    /// loop number is a counter of usages of timeit function
    static int loop_number = 1;
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


int8_t get_random_int8_t()
{
    return (int8_t)(rand());
    /*
    return rrrr rrrr
    */
}
int16_t get_random_int16_t()
{
    return (int16_t)(((rand()) << 15) | rand());
    /*
    * 
    *   r - random bit
    * 
    1 rand return            0000 0000  0000 0000  0rrr rrrr  rrrr rrrr
    2 rand() << 15 return    00rr rrrr  rrrr rrrr  r000 0000  0000 0000
    3 | rand() return        00rr rrrr  rrrr rrrr  rrrr rrrr  rrrr rrrr    
    4 (int16_t) return       rrrr rrrr  rrrr rrrr
    */
}

int32_t get_random_int32_t()
{
    return (int32_t)((rand() << 17) | ((rand() % 4) << 15) | rand());
    /*
    *
    *   r - random bit
    *
    1 rand return            0000 0000  0000 0000  0rrr rrrr  rrrr rrrr
    2 rand() << 17 return    rrrr rrrr  rrrr rrr0  0000 0000  0000 0000
    3 rand() % 4 return      0000 0000  0000 0000  0000 0000  0000 00rr
    4 <<15 return            0000 0000  0000 000r  r000 0000  0000 0000
    5 2 | 4 return           rrrr rrrr  rrrr rrrr  r000 0000  0000 0000
    6 5 | rand() return      rrrr rrrr  rrrr rrrr  rrrr rrrr  rrrr rrrr
    7 (int32_t) return       rrrr rrrr  rrrr rrrr  rrrr rrrr  rrrr rrrr
    */
}


uint8_t get_random_uint8_t()
{
    return (uint8_t)(rand());
    /*
        return rrrr rrrr
    */
}
uint16_t get_random_uint16_t()
{
    return (uint16_t)(((rand()) << 15) | rand());
    
    /*
    *
    *   r - random bit
    *
    1 rand return            0000 0000  0000 0000  0rrr rrrr  rrrr rrrr
    2 rand() << 15 return    00rr rrrr  rrrr rrrr  r000 0000  0000 0000
    3 | rand() return        00rr rrrr  rrrr rrrr  rrrr rrrr  rrrr rrrr
    4 (uint16_t) return      rrrr rrrr  rrrr rrrr
    */
}
uint32_t get_random_uint32_t()
{
    return (uint32_t)((rand() << 17) | ((rand() % 4) << 15) | rand());
    /*
    *
    *   r - random bit
    *
    1 rand return            0000 0000  0000 0000  0rrr rrrr  rrrr rrrr
    2 rand() << 17 return    rrrr rrrr  rrrr rrr0  0000 0000  0000 0000
    3 rand() % 4 return      0000 0000  0000 0000  0000 0000  0000 00rr
    4 <<15 return            0000 0000  0000 000r  r000 0000  0000 0000
    5 2 | 4 return           rrrr rrrr  rrrr rrrr  r000 0000  0000 0000
    6 5 | rand() return      rrrr rrrr  rrrr rrrr  rrrr rrrr  rrrr rrrr
    7 (uint32_t) return      rrrr rrrr  rrrr rrrr  rrrr rrrr  rrrr rrrr
    */
}

void performance_comparison()
{

    char format[] = "Max memory usage is %u + %u Mbyte\nAmount of elements = %u\n\n\n";
    char format2[] = "EMPTY CYCLE FUNCTION";
    unsigned s = NumberOfElementsArray;
    __asm {
        push s
        mov eax, 1024
        mul eax
        mov ebx, eax
        mov eax, s
        mov ecx, 8
        mul ecx
        div ebx
        push eax
        push eax
        lea eax, format
        push eax
        call printf

        add esp, 16


        push s

        push 1
        lea eax, format2

        push eax

        lea eax, empty_function
        push eax

        call timeit

        add esp, 16


        call perform_integers

        call perform_floats

    }
    //printf("", (NumberOfElementsArray * 8) / (1024 * 1024), (NumberOfElementsArray * 8) / (1024 * 1024));

    //zero time test
    //timeit(empty_function, "EMPTY CYCLE FUNCTION", 1, NumberOfElementsArray);

    //perform_integers();

    //perform_floats();

}

void perform_integers()
{
    perform_signed_integers();
    perform_unsigned_integers();
}

void perform_signed_int8_reg()
{
    printf(DelimString);
    printf("\tSIGNED INT 8 bit\n");

    int8_t* x_8, * y_8, * x_for_div_8, *y_for_div_8;
    x_8 = (int8_t*)malloc(NumberOfElementsArray * sizeof(int8_t));
    y_8 = (int8_t*)malloc(NumberOfElementsArray * sizeof(int8_t));

    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_8[i] = get_random_int8_t();
        y_8[i] = get_random_int8_t();

    }

    //unar
    printf(UnarOperationString);
    timeit(NOT8_reg_signed, "NOT REG", 2, NumberOfElementsArray, x_8);
    timeit(neg8_reg_signed, "NEG REG", 2, NumberOfElementsArray, x_8);

    //bin
    printf(BinaryOperationString);

    timeit(XOR8_reg_signed, "XOR REG, REG", 3, NumberOfElementsArray, x_8, y_8);
    timeit(AND8_reg_signed, "AND REG, REG", 3, NumberOfElementsArray, x_8, y_8);
    timeit(OR8_reg_signed, "OR REG, REG", 3, NumberOfElementsArray, x_8, y_8);

    timeit(add8_reg_signed, "ADD REG, REG", 3, NumberOfElementsArray, x_8, y_8);
    timeit(sub8_reg_signed, "SUB REG, REG", 3, NumberOfElementsArray, x_8, y_8);
    timeit(mul8_reg_signed, "IMUL REG, REG", 3, NumberOfElementsArray, x_8, y_8);
    
    free(x_8);
    free(y_8);

    x_for_div_8 = (int8_t*)malloc(NumberOfElementsArray * sizeof(int8_t));
    y_for_div_8 = (int8_t*)malloc(NumberOfElementsArray * sizeof(int8_t));

    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        do
        {
            x_for_div_8[i] = get_random_int8_t();
        } while (!x_for_div_8[i]);//eliminate division by zero error

        do
        {
            y_for_div_8[i] = get_random_int8_t();
        } while (y_for_div_8[i] == (-128));//eliminate integer overflow -2^7
    }

    timeit(div8_reg_signed, "IDIV REG, REG", 3, NumberOfElementsArray, x_for_div_8, y_for_div_8);//y/x

    free(x_for_div_8);
    free(y_for_div_8);
}


void perform_signed_int16_reg()
{
    printf(DelimString);
    printf("\tSIGNED INT 16 bit\n");

    int16_t* x_16, * y_16, * x_for_div_16, *y_for_div_16;
    x_16 = (int16_t*)malloc(NumberOfElementsArray * sizeof(int16_t));
    y_16 = (int16_t*)malloc(NumberOfElementsArray * sizeof(int16_t));
    
    for (int i = 0; i < NumberOfElementsArray; i++)
    {   
        x_16[i] = get_random_int16_t();
        y_16[i] = get_random_int16_t();
    }

    //unar
    printf(UnarOperationString);

    timeit(NOT16_reg_signed, "NOT REG", 2, NumberOfElementsArray, x_16);
    timeit(neg16_reg_signed, "NEG REG", 2, NumberOfElementsArray, x_16);
    
    //bin
    printf(BinaryOperationString);
    timeit(XOR16_reg_signed, "XOR REG, REG", 3, NumberOfElementsArray, x_16, y_16);
    timeit(AND16_reg_signed, "AND REG, REG", 3, NumberOfElementsArray, x_16, y_16);
    timeit(OR16_reg_signed, "OR REG, REG", 3, NumberOfElementsArray, x_16, y_16);

    timeit(add16_reg_signed, "ADD REG, REG", 3, NumberOfElementsArray, x_16, y_16);
    timeit(sub16_reg_signed, "SUB REG, REG", 3, NumberOfElementsArray, x_16, y_16);
    timeit(mul16_reg_signed, "IMUL REG, REG", 3, NumberOfElementsArray, x_16, y_16);

    free(x_16);
    free(y_16);

    x_for_div_16 = (int16_t*)malloc(NumberOfElementsArray * sizeof(int16_t));
    y_for_div_16 = (int16_t*)malloc(NumberOfElementsArray * sizeof(int16_t));


    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        do
        {
            x_for_div_16[i] = get_random_int16_t();
        } while (!x_for_div_16[i]);//eliminate division by zero error

        do
        {
            y_for_div_16[i] = get_random_int16_t();
        } while (y_for_div_16[i] == (-32768));//eliminate integer overflow -2^15
    }

    timeit(div16_reg_signed, "IDIV REG, REG", 3, NumberOfElementsArray, x_for_div_16, y_for_div_16);//y/x

    free(x_for_div_16);
    free(y_for_div_16);
}


void perform_signed_int32_reg()
{
    printf(DelimString);

    printf("\tSIGNED INT 32 bit\n");

    int32_t* x_32, * y_32, * x_for_div_32, * y_for_div_32;
    x_32 = (int32_t*)malloc(NumberOfElementsArray * sizeof(int32_t));
    y_32 = (int32_t*)malloc(NumberOfElementsArray * sizeof(int32_t));

    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_32[i] = get_random_int32_t;
        y_32[i] = get_random_int32_t();
    }

    //unar
    printf(UnarOperationString);

    timeit(NOT32_reg_signed, "NOT REG", 2, NumberOfElementsArray, x_32);
    timeit(neg32_reg_signed, "NEG REG", 2, NumberOfElementsArray, x_32);
        
    //bin
    printf(BinaryOperationString);

    timeit(XOR32_reg_signed, "XOR REG, REG", 3, NumberOfElementsArray, x_32, y_32);
    timeit(AND32_reg_signed, "AND REG, REG", 3, NumberOfElementsArray, x_32, y_32);
    timeit(OR32_reg_signed, "OR REG, REG", 3, NumberOfElementsArray, x_32, y_32);

    timeit(add32_reg_signed, "ADD REG, REG", 3, NumberOfElementsArray, x_32, y_32);
    timeit(sub32_reg_signed, "SUB REG, REG", 3, NumberOfElementsArray, x_32, y_32);
    timeit(mul32_reg_signed, "IMUL REG, REG", 3, NumberOfElementsArray, x_32, y_32);
    
    free(x_32);
    free(y_32);
    
    x_for_div_32 = (int32_t*)malloc(NumberOfElementsArray * sizeof(int32_t));
    y_for_div_32 = (int32_t*)malloc(NumberOfElementsArray * sizeof(int32_t));

    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        do
        {
            x_for_div_32[i] = get_random_int32_t();
        } while (!x_for_div_32[i]);//eliminate division by zero error
        
        do
        {
            y_for_div_32[i] = get_random_int32_t();
        } while (y_for_div_32[i] == (((int)1)<<31));//eliminate integer overflow -2^15
    }

    timeit(div32_reg_signed, "IDIV REG, REG", 3, NumberOfElementsArray, x_for_div_32, y_for_div_32); //y/x

    free(x_for_div_32);
    free(y_for_div_32);
}





void perform_unsigned_int8_reg()
{
    printf(DelimString);
    printf("\tUNSIGNED INT 8 bit\n");

    uint8_t* x_8, * y_8, * x_for_div_8;
    x_8 = (uint8_t*)malloc(NumberOfElementsArray * sizeof(uint8_t));
    y_8 = (uint8_t*)malloc(NumberOfElementsArray * sizeof(uint8_t));

    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_8[i] = get_random_uint8_t();
        y_8[i] = get_random_uint8_t();

    }

    //unar
    printf(UnarOperationString);
    timeit(NOT8_reg_unsigned, "NOT REG", 2, NumberOfElementsArray, x_8);

    //bin
    printf(BinaryOperationString);
    timeit(XOR8_reg_unsigned, "XOR REG, REG", 3, NumberOfElementsArray, x_8, y_8);
    timeit(AND8_reg_unsigned, "AND REG, REG", 3, NumberOfElementsArray, x_8, y_8);
    timeit(OR8_reg_unsigned, "OR REG, REG", 3, NumberOfElementsArray, x_8, y_8);

    timeit(add8_reg_unsigned, "ADD REG, REG", 3, NumberOfElementsArray, x_8, y_8);
    timeit(sub8_reg_unsigned, "SUB REG, REG", 3, NumberOfElementsArray, x_8, y_8);
    timeit(mul8_reg_unsigned, "MUL REG, REG", 3, NumberOfElementsArray, x_8, y_8);

    free(x_8);
    
    x_for_div_8 = (uint8_t*)malloc(NumberOfElementsArray * sizeof(uint8_t));

    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        do
        {
            x_for_div_8[i] = get_random_uint8_t();
        } while (!x_for_div_8[i]);//eliminate division by zero error
    }

    timeit(div8_reg_unsigned, "DIV REG, REG", 3, NumberOfElementsArray, x_for_div_8, y_8);//y/x

    free(x_for_div_8);
    free(y_8);
}


void perform_unsigned_int16_reg()
{
    printf(DelimString);
    printf("\tUNSIGNED INT 16 bit\n");

    uint16_t* x_16, * y_16, * x_for_div_16;
    x_16 = (uint16_t*)malloc(NumberOfElementsArray * sizeof(uint16_t));
    y_16 = (uint16_t*)malloc(NumberOfElementsArray * sizeof(uint16_t));

    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_16[i] = get_random_uint16_t();
        y_16[i] = get_random_uint16_t();
    }

    //unar
    printf(UnarOperationString);
    timeit(NOT16_reg_unsigned, "NOT REG", 2, NumberOfElementsArray, x_16);

    //bin
    printf(BinaryOperationString);
    timeit(XOR16_reg_unsigned, "XOR REG, REG", 3, NumberOfElementsArray, x_16, y_16);
    timeit(AND16_reg_unsigned, "AND REG, REG", 3, NumberOfElementsArray, x_16, y_16);
    timeit(OR16_reg_unsigned, "OR REG, REG", 3, NumberOfElementsArray, x_16, y_16);

    timeit(add16_reg_unsigned, "ADD REG, REG", 3, NumberOfElementsArray, x_16, y_16);
    timeit(sub16_reg_unsigned, "SUB REG, REG", 3, NumberOfElementsArray, x_16, y_16);
    timeit(mul16_reg_unsigned, "MUL REG, REG", 3, NumberOfElementsArray, x_16, y_16);

    free(x_16);
    
    x_for_div_16 = (uint16_t*)malloc(NumberOfElementsArray * sizeof(uint16_t));


    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        do
        {
            x_for_div_16[i] = get_random_uint16_t();
        } while (!x_for_div_16[i]);//eliminate division by zero error
    }

    timeit(div16_reg_unsigned, "DIV REG, REG", 3, NumberOfElementsArray, x_for_div_16, y_16);//y/x

    free(x_for_div_16);
    free(y_16);
}


void perform_unsigned_int32_reg()
{
    printf(DelimString);
    printf("\tUNSIGNED INT 32 bit\n");

    uint32_t* x_32, * y_32, * x_for_div_32;
    x_32 = (uint32_t*)malloc(NumberOfElementsArray * sizeof(uint32_t));
    y_32 = (uint32_t*)malloc(NumberOfElementsArray * sizeof(uint32_t));

    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_32[i] = get_random_uint32_t();
        y_32[i] = get_random_uint32_t();
    }

    //unar
    printf(UnarOperationString);
    timeit(NOT32_reg_unsigned, "NOT REG", 2, NumberOfElementsArray, x_32);

    //bin
    printf(BinaryOperationString);
    timeit(XOR32_reg_unsigned, "XOR REG, REG", 3, NumberOfElementsArray, x_32, y_32);
    timeit(AND32_reg_unsigned, "AND REG, REG", 3, NumberOfElementsArray, x_32, y_32);
    timeit(OR32_reg_unsigned, "OR REG, REG", 3, NumberOfElementsArray, x_32, y_32);

    timeit(add32_reg_unsigned, "ADD REG, REG", 3, NumberOfElementsArray, x_32, y_32);
    timeit(sub32_reg_unsigned, "SUB REG, REG", 3, NumberOfElementsArray, x_32, y_32);
    timeit(mul32_reg_unsigned, "MUL REG, REG", 3, NumberOfElementsArray, x_32, y_32);

    free(x_32);
    

    x_for_div_32 = (uint32_t*)malloc(NumberOfElementsArray * sizeof(uint32_t));

    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        do
        {
            x_for_div_32[i] = get_random_uint32_t();
        } while (!x_for_div_32[i]);//eliminate division by zero error
    }

    timeit(div32_reg_unsigned, "DIV REG, REG", 3, NumberOfElementsArray, x_for_div_32, y_32); //y/x

    free(x_for_div_32);
    free(y_32);
}



void perform_signed_int8_mem()
{
    printf(DelimString);
    printf("\tSIGNED INT 8 bit\n");

    int8_t* x_8, * y_8, * x_for_div_8, * y_for_div_8;
    x_8 = (int8_t*)malloc(NumberOfElementsArray * sizeof(int8_t));
    y_8 = (int8_t*)malloc(NumberOfElementsArray * sizeof(int8_t));

    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_8[i] = get_random_int8_t();
        y_8[i] = get_random_int8_t();

    }

    //unar
    printf(UnarOperationString);
    timeit(NOT8_mem_signed, "NOT MEM", 2, NumberOfElementsArray, x_8);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_8[i] = get_random_int8_t();
        y_8[i] = get_random_int8_t();

    }
    timeit(neg8_mem_signed, "NEG MEM", 2, NumberOfElementsArray, y_8);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_8[i] = get_random_int8_t();
        y_8[i] = get_random_int8_t();

    }
    printf(BinaryOperationString);
    //printf("mem - left; reg - right\n");
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_8[i] = get_random_int8_t();
        y_8[i] = get_random_int8_t();

    }
    timeit(XOR8_mem_signed_left, "XOR MEM, REG", 3, NumberOfElementsArray, x_8, y_8);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_8[i] = get_random_int8_t();
        y_8[i] = get_random_int8_t();

    }
    timeit(AND8_mem_signed_left, "AND MEM, REG", 3, NumberOfElementsArray, x_8, y_8);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_8[i] = get_random_int8_t();
        y_8[i] = get_random_int8_t();

    }
    timeit(OR8_mem_signed_left, "OR MEM, REG", 3, NumberOfElementsArray, x_8, y_8);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_8[i] = get_random_int8_t();
        y_8[i] = get_random_int8_t();

    }
    timeit(add8_mem_signed_left, "ADD MEM, REG", 3, NumberOfElementsArray, x_8, y_8);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_8[i] = get_random_int8_t();
        y_8[i] = get_random_int8_t();

    }
    timeit(sub8_mem_signed_left, "SUB MEM, REG", 3, NumberOfElementsArray, x_8, y_8);
    
    //printf("mem - right; reg - left\n");
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_8[i] = get_random_int8_t();
        y_8[i] = get_random_int8_t();

    }
    timeit(XOR8_mem_signed_right, "XOR REG, MEM", 3, NumberOfElementsArray, x_8, y_8);
    timeit(AND8_mem_signed_right, "AND REG, MEM", 3, NumberOfElementsArray, x_8, y_8);
    timeit(OR8_mem_signed_right, "OR REG, MEM", 3, NumberOfElementsArray, x_8, y_8);
    timeit(add8_mem_signed_right, "ADD REG, MEM", 3, NumberOfElementsArray, x_8, y_8);
    timeit(sub8_mem_signed_right, "SUB REG, MEM", 3, NumberOfElementsArray, x_8, y_8);
    timeit(mul8_mem_signed, "IMUL REG, MEM", 3, NumberOfElementsArray, x_8, y_8);

    free(x_8);
    free(y_8);

    x_for_div_8 = (int8_t*)malloc(NumberOfElementsArray * sizeof(int8_t));
    y_for_div_8 = (int8_t*)malloc(NumberOfElementsArray * sizeof(int8_t));

    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        do
        {
            x_for_div_8[i] = get_random_int8_t();
        } while (!x_for_div_8[i]);//eliminate division by zero error

        do
        {
            y_for_div_8[i] = get_random_int8_t();
        } while (y_for_div_8[i] == (-128));//eliminate integer overflow -2^7
    }

    timeit(div8_mem_signed, "IDIV REG, MEM", 3, NumberOfElementsArray, x_for_div_8, y_for_div_8);//y/x

    free(x_for_div_8);
    free(y_for_div_8);

}


void perform_signed_int16_mem()
{
    printf(DelimString);
    printf("\tSIGNED INT 16 bit\n");

    int16_t* x_16, * y_16, * x_for_div_16, * y_for_div_16;
    x_16 = (int16_t*)malloc(NumberOfElementsArray * sizeof(int16_t));
    y_16 = (int16_t*)malloc(NumberOfElementsArray * sizeof(int16_t));

    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_16[i] = get_random_int16_t();
        y_16[i] = get_random_int16_t();

    }

    //unar
    printf(UnarOperationString);
    timeit(NOT16_mem_signed, "NOT MEM", 2, NumberOfElementsArray, x_16);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_16[i] = get_random_int16_t();
        y_16[i] = get_random_int16_t();

    }
    timeit(neg16_mem_signed, "NEG MEM", 2, NumberOfElementsArray, y_16);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_16[i] = get_random_int16_t();
        y_16[i] = get_random_int16_t();

    }
    printf(BinaryOperationString);
    //printf("mem - left; reg - right\n");
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_16[i] = get_random_int16_t();
        y_16[i] = get_random_int16_t();

    }
    timeit(XOR16_mem_signed_left, "XOR MEM, REG", 3, NumberOfElementsArray, x_16, y_16);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_16[i] = get_random_int16_t();
        y_16[i] = get_random_int16_t();

    }
    timeit(AND16_mem_signed_left, "AND MEM, REG", 3, NumberOfElementsArray, x_16, y_16);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_16[i] = get_random_int16_t();
        y_16[i] = get_random_int16_t();

    }
    timeit(OR16_mem_signed_left, "OR MEM, REG", 3, NumberOfElementsArray, x_16, y_16);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_16[i] = get_random_int16_t();
        y_16[i] = get_random_int16_t();

    }
    timeit(add16_mem_signed_left, "ADD MEM, REG", 3, NumberOfElementsArray, x_16, y_16);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_16[i] = get_random_int16_t();
        y_16[i] = get_random_int16_t();

    }
    timeit(sub16_mem_signed_left, "SUB MEM, REG", 3, NumberOfElementsArray, x_16, y_16);

    //printf("mem - right; reg - left\n");
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_16[i] = get_random_int16_t();
        y_16[i] = get_random_int16_t();

    }
    timeit(XOR16_mem_signed_right, "XOR REG, MEM", 3, NumberOfElementsArray, x_16, y_16);
    timeit(AND16_mem_signed_right, "AND REG, MEM", 3, NumberOfElementsArray, x_16, y_16);
    timeit(OR16_mem_signed_right, "OR REG, MEM", 3, NumberOfElementsArray, x_16, y_16);
    timeit(add16_mem_signed_right, "ADD REG, MEM", 3, NumberOfElementsArray, x_16, y_16);
    timeit(sub16_mem_signed_right, "SUB REG, MEM", 3, NumberOfElementsArray, x_16, y_16);
    timeit(mul16_mem_signed, "IMUL REG, MEM", 3, NumberOfElementsArray, x_16, y_16);

    free(x_16);
    free(y_16);

    x_for_div_16 = (int16_t*)malloc(NumberOfElementsArray * sizeof(int16_t));
    y_for_div_16 = (int16_t*)malloc(NumberOfElementsArray * sizeof(int16_t));

    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        do
        {
            x_for_div_16[i] = get_random_int16_t();
        } while (!x_for_div_16[i]);//eliminate division by zero error

        do
        {
            y_for_div_16[i] = get_random_int16_t();
        } while (y_for_div_16[i] == (-32768));//eliminate integer overflow -2^15
    }

    timeit(div16_mem_signed, "IDIV REG, MEM", 3, NumberOfElementsArray, x_for_div_16, y_for_div_16);//y/x

    free(x_for_div_16);
    free(y_for_div_16);

}

void perform_signed_int32_mem()
{
    printf(DelimString);
    printf("\tSIGNED INT 32 bit\n");

    int32_t* x_32, * y_32, * x_for_div_32, * y_for_div_32;
    x_32 = (int32_t*)malloc(NumberOfElementsArray * sizeof(int32_t));
    y_32 = (int32_t*)malloc(NumberOfElementsArray * sizeof(int32_t));

    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_32[i] = get_random_int32_t();
        y_32[i] = get_random_int32_t();

    }

    //unar
    printf(UnarOperationString);

    timeit(NOT32_mem_signed, "NOT MEM", 2, NumberOfElementsArray, x_32);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_32[i] = get_random_int32_t();
        y_32[i] = get_random_int32_t();

    }
    timeit(neg32_mem_signed, "NEG MEM", 2, NumberOfElementsArray, y_32);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_32[i] = get_random_int32_t();
        y_32[i] = get_random_int32_t();

    }
    //printf("mem - left; reg - right\n");
    printf(BinaryOperationString);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_32[i] = get_random_int32_t();
        y_32[i] = get_random_int32_t();

    }
    timeit(XOR32_mem_signed_left, "XOR MEM, REG", 3, NumberOfElementsArray, x_32, y_32);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_32[i] = get_random_int32_t();
        y_32[i] = get_random_int32_t();

    }
    timeit(AND32_mem_signed_left, "AND MEM, REG", 3, NumberOfElementsArray, x_32, y_32);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_32[i] = get_random_int32_t();
        y_32[i] = get_random_int32_t();

    }
    timeit(OR32_mem_signed_left, "OR MEM, REG", 3, NumberOfElementsArray, x_32, y_32);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_32[i] = get_random_int32_t();
        y_32[i] = get_random_int32_t();

    }
    timeit(add32_mem_signed_left, "ADD MEM, REG", 3, NumberOfElementsArray, x_32, y_32);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_32[i] = get_random_int32_t();
        y_32[i] = get_random_int32_t();

    }
    timeit(sub32_mem_signed_left, "SUB MEM, REG", 3, NumberOfElementsArray, x_32, y_32);

    //printf("mem - right; reg - left\n");
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_32[i] = get_random_int32_t();
        y_32[i] = get_random_int32_t();

    }
    timeit(XOR32_mem_signed_right, "XOR REG, MEM", 3, NumberOfElementsArray, x_32, y_32);
    timeit(AND32_mem_signed_right, "AND REG, MEM", 3, NumberOfElementsArray, x_32, y_32);
    timeit(OR32_mem_signed_right, "OR REG, MEM", 3, NumberOfElementsArray, x_32, y_32);
    timeit(add32_mem_signed_right, "ADD REG, MEM", 3, NumberOfElementsArray, x_32, y_32);
    timeit(sub32_mem_signed_right, "SUB REG, MEM", 3, NumberOfElementsArray, x_32, y_32);
    timeit(mul32_mem_signed, "IMUL REG, MEM", 3, NumberOfElementsArray, x_32, y_32);

    free(x_32);
    free(y_32);

    x_for_div_32 = (int32_t*)malloc(NumberOfElementsArray * sizeof(int32_t));
    y_for_div_32 = (int32_t*)malloc(NumberOfElementsArray * sizeof(int32_t));

    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        do
        {
            x_for_div_32[i] = get_random_int32_t();
        } while (!x_for_div_32[i]);

        do
        {
            y_for_div_32[i] = get_random_int32_t();
        } while (y_for_div_32[i] == ((int)(1))<<31);//
    }

    timeit(div32_mem_signed, "IDIV REG, MEM", 3, NumberOfElementsArray, x_for_div_32, y_for_div_32);//y/x

    free(x_for_div_32);
    free(y_for_div_32);

}




void perform_unsigned_int8_mem()
{
    printf("\tUNSIGNED INT 8 bit\n");

    uint8_t* x_8, * y_8, * x_for_div_8, * y_for_div_8;
    x_8 = (uint8_t*)malloc(NumberOfElementsArray * sizeof(uint8_t));
    y_8 = (uint8_t*)malloc(NumberOfElementsArray * sizeof(uint8_t));

    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_8[i] = get_random_uint8_t();
        y_8[i] = get_random_uint8_t();
    }

    //unar
    printf(UnarOperationString);
    timeit(NOT8_mem_unsigned, "NOT MEM", 2, NumberOfElementsArray, x_8);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_8[i] = get_random_uint8_t();
        y_8[i] = get_random_uint8_t();

    }

    printf(BinaryOperationString);
    //printf("mem - left; reg - right\n");
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_8[i] = get_random_uint8_t();
        y_8[i] = get_random_uint8_t();

    }
    timeit(XOR8_mem_unsigned_left, "XOR MEM, REG", 3, NumberOfElementsArray, x_8, y_8);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_8[i] = get_random_uint8_t();
        y_8[i] = get_random_uint8_t();

    }
    timeit(AND8_mem_unsigned_left, "AND MEM, REG", 3, NumberOfElementsArray, x_8, y_8);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_8[i] = get_random_uint8_t();
        y_8[i] = get_random_uint8_t();

    }
    timeit(OR8_mem_unsigned_left, "OR MEM, REG", 3, NumberOfElementsArray, x_8, y_8);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_8[i] = get_random_uint8_t();
        y_8[i] = get_random_uint8_t();

    }
    timeit(add8_mem_unsigned_left, "ADD MEM, REG", 3, NumberOfElementsArray, x_8, y_8);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_8[i] = get_random_uint8_t();
        y_8[i] = get_random_uint8_t();

    }
    timeit(sub8_mem_unsigned_left, "SUB MEM, REG", 3, NumberOfElementsArray, x_8, y_8);

    //printf("mem - right; reg - left\n");
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_8[i] = get_random_uint8_t();
        y_8[i] = get_random_uint8_t();

    }
    timeit(XOR8_mem_unsigned_right, "XOR REG, MEM", 3, NumberOfElementsArray, x_8, y_8);
    timeit(AND8_mem_unsigned_right, "AND REG, MEM", 3, NumberOfElementsArray, x_8, y_8);
    timeit(OR8_mem_unsigned_right, "OR REG, MEM", 3, NumberOfElementsArray, x_8, y_8);
    timeit(add8_mem_unsigned_right, "ADD REG, MEM", 3, NumberOfElementsArray, x_8, y_8);
    timeit(sub8_mem_unsigned_right, "SUB REG, MEM", 3, NumberOfElementsArray, x_8, y_8);
    timeit(mul8_mem_unsigned, "MUL REG, MEM", 3, NumberOfElementsArray, x_8, y_8);

    free(x_8);
    free(y_8);

    x_for_div_8 = (uint8_t*)malloc(NumberOfElementsArray * sizeof(uint8_t));
    y_for_div_8 = (uint8_t*)malloc(NumberOfElementsArray * sizeof(uint8_t));

    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        do
        {
            x_for_div_8[i] = get_random_uint8_t();
        } while (!x_for_div_8[i]);//eliminate division by zero error

        y_for_div_8[i] = get_random_uint8_t();
    }

    timeit(div8_mem_unsigned, "DIV REG, MEM", 3, NumberOfElementsArray, x_for_div_8, y_for_div_8);//y/x

    free(x_for_div_8);
    free(y_for_div_8);

}


void perform_unsigned_int16_mem()
{
    printf(DelimString);
    printf("\tUNSIGNED INT 16 bit\n");

    uint16_t* x_16, * y_16, * x_for_div_16, * y_for_div_16;
    x_16 = (uint16_t*)malloc(NumberOfElementsArray * sizeof(uint16_t));
    y_16 = (uint16_t*)malloc(NumberOfElementsArray * sizeof(uint16_t));

    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_16[i] = get_random_uint16_t();
        y_16[i] = get_random_uint16_t();

    }

    //unar
    printf(UnarOperationString);
    timeit(NOT16_mem_unsigned, "NOT MEM", 2, NumberOfElementsArray, x_16);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_16[i] = get_random_uint16_t();
        y_16[i] = get_random_uint16_t();

    }
    
    printf(BinaryOperationString);
    //printf("mem - left; reg - right\n");
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_16[i] = get_random_uint16_t();
        y_16[i] = get_random_uint16_t();

    }
    timeit(XOR16_mem_unsigned_left, "XOR MEM, REG", 3, NumberOfElementsArray, x_16, y_16);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_16[i] = get_random_uint16_t();
        y_16[i] = get_random_uint16_t();

    }
    timeit(AND16_mem_unsigned_left, "AND MEM, REG", 3, NumberOfElementsArray, x_16, y_16);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_16[i] = get_random_uint16_t();
        y_16[i] = get_random_uint16_t();

    }
    timeit(OR16_mem_unsigned_left, "OR MEM, REG", 3, NumberOfElementsArray, x_16, y_16);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_16[i] = get_random_uint16_t();
        y_16[i] = get_random_uint16_t();

    }
    timeit(add16_mem_unsigned_left, "ADD MEM, REG", 3, NumberOfElementsArray, x_16, y_16);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_16[i] = get_random_uint16_t();
        y_16[i] = get_random_uint16_t();

    }
    timeit(sub16_mem_unsigned_left, "SUB MEM, REG", 3, NumberOfElementsArray, x_16, y_16);

    //printf("mem - right; reg - left\n");
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_16[i] = get_random_uint16_t();
        y_16[i] = get_random_uint16_t();

    }
    timeit(XOR16_mem_unsigned_right, "XOR REG, MEM", 3, NumberOfElementsArray, x_16, y_16);
    timeit(AND16_mem_unsigned_right, "AND REG, MEM", 3, NumberOfElementsArray, x_16, y_16);
    timeit(OR16_mem_unsigned_right, "OR REG, MEM", 3, NumberOfElementsArray, x_16, y_16);
    timeit(add16_mem_unsigned_right, "ADD REG, MEM", 3, NumberOfElementsArray, x_16, y_16);
    timeit(sub16_mem_unsigned_right, "SUB REG, MEM", 3, NumberOfElementsArray, x_16, y_16);
    timeit(mul16_mem_unsigned, "MUL REG, MEM", 3, NumberOfElementsArray, x_16, y_16);

    free(x_16);
    free(y_16);

    x_for_div_16 = (uint16_t*)malloc(NumberOfElementsArray * sizeof(uint16_t));
    y_for_div_16 = (uint16_t*)malloc(NumberOfElementsArray * sizeof(uint16_t));

    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        do
        {
            x_for_div_16[i] = get_random_uint16_t();
        } while (!x_for_div_16[i]);////eliminate division by zero error

        y_for_div_16[i] = get_random_uint16_t();
       
    }

    timeit(div16_mem_unsigned, "DIV REG, MEM", 3, NumberOfElementsArray, x_for_div_16, y_for_div_16);//y/x

    free(x_for_div_16);
    free(y_for_div_16);

}

void perform_unsigned_int32_mem()
{
    printf(DelimString);
    printf("\tUNSIGNED INT 32 bit\n");

    uint32_t* x_32, * y_32, * x_for_div_32, * y_for_div_32;
    x_32 = (uint32_t*)malloc(NumberOfElementsArray * sizeof(uint32_t));
    y_32 = (uint32_t*)malloc(NumberOfElementsArray * sizeof(uint32_t));

    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_32[i] = get_random_uint32_t();
        y_32[i] = get_random_uint32_t();

    }

    //unar
    printf(UnarOperationString);
    timeit(NOT32_mem_unsigned, "NOT MEM", 2, NumberOfElementsArray, x_32);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_32[i] = get_random_uint32_t();
        y_32[i] = get_random_uint32_t();

    }
    printf(BinaryOperationString);
    //printf("mem - left; reg - right\n");
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_32[i] = get_random_uint32_t();
        y_32[i] = get_random_uint32_t();

    }
    timeit(XOR32_mem_unsigned_left, "XOR MEM, REG", 3, NumberOfElementsArray, x_32, y_32);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_32[i] = get_random_uint32_t();
        y_32[i] = get_random_uint32_t();

    }
    timeit(AND32_mem_unsigned_left, "AND MEM, REG", 3, NumberOfElementsArray, x_32, y_32);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_32[i] = get_random_uint32_t();
        y_32[i] = get_random_uint32_t();

    }
    timeit(OR32_mem_unsigned_left, "OR MEM, REG", 3, NumberOfElementsArray, x_32, y_32);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_32[i] = get_random_uint32_t();
        y_32[i] = get_random_uint32_t();

    }
    timeit(add32_mem_unsigned_left, "ADD MEM, REG", 3, NumberOfElementsArray, x_32, y_32);
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_32[i] = get_random_uint32_t();
        y_32[i] = get_random_uint32_t();

    }
    timeit(sub32_mem_unsigned_left, "SUB MEM, REG", 3, NumberOfElementsArray, x_32, y_32);

    //printf("mem - right; reg - left\n");
    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_32[i] = get_random_uint32_t();
        y_32[i] = get_random_uint32_t();

    }
    timeit(XOR32_mem_unsigned_right, "XOR REG, MEM", 3, NumberOfElementsArray, x_32, y_32);
    timeit(AND32_mem_unsigned_right, "AND REG, MEM", 3, NumberOfElementsArray, x_32, y_32);
    timeit(OR32_mem_unsigned_right, "OR REG, MEM", 3, NumberOfElementsArray, x_32, y_32);
    timeit(add32_mem_unsigned_right, "ADD REG, MEM", 3, NumberOfElementsArray, x_32, y_32);
    timeit(sub32_mem_unsigned_right, "SUB REG, MEM", 3, NumberOfElementsArray, x_32, y_32);
    timeit(mul32_mem_unsigned, "MUL REG, MEM", 3, NumberOfElementsArray, x_32, y_32);

    free(x_32);
    free(y_32);

    x_for_div_32 = (uint32_t*)malloc(NumberOfElementsArray * sizeof(uint32_t));
    y_for_div_32 = (uint32_t*)malloc(NumberOfElementsArray * sizeof(uint32_t));

    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        do
        {
            x_for_div_32[i] = get_random_uint32_t();
        } while (!x_for_div_32[i]);//eliminate division by zero error

        y_for_div_32[i] = get_random_uint32_t();
        
    }

    timeit(div32_mem_unsigned, "DIV REG, MEM", 3, NumberOfElementsArray, x_for_div_32, y_for_div_32);//y/x

    free(x_for_div_32);
    free(y_for_div_32);

}






void perform_signed_integers()
{
    perform_signed_int8_reg();
    perform_signed_int16_reg();
    perform_signed_int32_reg();

    perform_signed_int8_mem();
    perform_signed_int16_mem();
    perform_signed_int32_mem();


}



void perform_unsigned_integers()
{
    perform_unsigned_int8_reg();
    perform_unsigned_int16_reg();
    perform_unsigned_int32_reg();

    perform_unsigned_int8_mem();
    perform_unsigned_int16_mem();
    perform_unsigned_int32_mem();
}


void perform_float_reg()
{
    float32_t* x_f, * y_f;

    x_f = (float32_t*)malloc(NumberOfElementsArray * sizeof(float32_t));
    y_f = (float32_t*)malloc(NumberOfElementsArray * sizeof(float32_t));

    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_f[i] = (float32_t)(get_random_uint32_t());
        y_f[i] = (float32_t)(get_random_uint32_t());
    }

    // binar
    printf(BinaryOperationString);
    timeit(add_floating, "FADD REG, REG", 3, NumberOfElementsArray, x_f, y_f);
    timeit(sub_floating, "FSUB REG, REG", 3, NumberOfElementsArray, x_f, y_f);
    timeit(mul_floating, "FMUL REG, REG", 3, NumberOfElementsArray, x_f, y_f);
    timeit(div_floating, "FDIV REG, REG", 3, NumberOfElementsArray, x_f, y_f);

    // unar
    printf(UnarOperationString);
    timeit(sqrt_floating, "FSQRT REG", 2, NumberOfElementsArray, x_f);
    timeit(l2_floating, "FYL2X REG", 2, NumberOfElementsArray, x_f);
    timeit(ln_floating, "LN REG", 2, NumberOfElementsArray, x_f);

    // trigan
    printf(TriganometricOperationString);
    timeit(sin_floating, "FSIN REG", 2, NumberOfElementsArray, x_f);
    timeit(tan_floating, "FPTAN REG", 2, NumberOfElementsArray, x_f);
    timeit(atan_floating, "FPATAN REG", 2, NumberOfElementsArray, x_f);
    free(x_f);
    free(y_f);
}

void perform_float_mem() 
{
    float32_t* x_f, * y_f;

    x_f = (float32_t*)malloc(NumberOfElementsArray * sizeof(float32_t));
    y_f = (float32_t*)malloc(NumberOfElementsArray * sizeof(float32_t));

    for (int i = 0; i < NumberOfElementsArray; i++)
    {
        x_f[i] = (float32_t)(get_random_uint32_t());
        y_f[i] = (float32_t)(get_random_uint32_t());
    }
    printf(BinaryOperationString);
    timeit(add_mem_floating, "FSUM REG, MEM", 3, NumberOfElementsArray, x_f, y_f);
    timeit(sub_mem_floating, "FSUB REG, MEM", 3, NumberOfElementsArray, x_f, y_f);
    timeit(mul_mem_floating, "FMUL REG, MEM", 3, NumberOfElementsArray, x_f, y_f);
    timeit(mul_mem_floating, "FDIV REG, MEM", 3, NumberOfElementsArray, x_f, y_f);
    free(x_f);
    free(y_f);
}

void perform_double_reg()
{
    double64_t* x_d, * y_d;
    x_d = (double64_t*)malloc(NumberOfElementsArray * sizeof(double64_t));
    y_d = (double64_t*)malloc(NumberOfElementsArray * sizeof(double64_t));

    for (int i = 0; i < NumberOfElementsArray; i++) {
        x_d[i] = rand();
        y_d[i] = rand();
    }

    // binar

    printf(BinaryOperationString);
    timeit(add_double, "ADD REG, REG", 3, NumberOfElementsArray, x_d, y_d);
    timeit(sub_double, "SUB REG, REG", 3, NumberOfElementsArray, x_d, y_d);
    timeit(mul_double, "MUL REG, REG", 3, NumberOfElementsArray, x_d, y_d);
    timeit(div_double, "DIV REG, REG", 3, NumberOfElementsArray, x_d, y_d);

    // unar

    printf(UnarOperationString);
    timeit(sqrt_double, "FSQRT REG, REG", 2, NumberOfElementsArray, x_d);
    timeit(l2_double, "FYL2X REG", 2, NumberOfElementsArray, x_d);
    timeit(ln_double, "LN REG, REG", 2, NumberOfElementsArray, x_d);
    // trigan

    printf(TriganometricOperationString);
    timeit(sin_double, "FSIN REG", 2, NumberOfElementsArray, x_d);
    timeit(tan_double, "FPTAN REG", 2, NumberOfElementsArray, x_d);
    timeit(atan_double, "FPATAN REG", 2, NumberOfElementsArray, x_d);

    free(x_d);
    free(y_d);
}


void perform_double_mem()
{
    double64_t* x_d, * y_d;
    x_d = (double64_t*)malloc(NumberOfElementsArray * sizeof(double64_t));
    y_d = (double64_t*)malloc(NumberOfElementsArray * sizeof(double64_t));

    for (int i = 0; i < NumberOfElementsArray; i++) {
        x_d[i] = rand();
        y_d[i] = rand();
    }
    timeit(add_mem_double, "ADD REG, MEM", 3, NumberOfElementsArray, x_d, y_d);
    timeit(sub_mem_double, "SUB REG, MEM", 3, NumberOfElementsArray, x_d, y_d);
    timeit(mul_mem_double, "MUL REG, MEM", 3, NumberOfElementsArray, x_d, y_d);
    timeit(div_mem_double, "DIV REG, MEM", 3, NumberOfElementsArray, x_d, y_d);

    free(x_d);
    free(y_d);
}


void perform_floats() {
    printf(DelimString);
    printf("\tFLOAT POINT 32 bit\n");
    perform_float_reg();
    perform_float_mem();
    printf(DelimString);
    printf("\tDOUBLE 64 bit\n");
    perform_double_reg();
    perform_double_mem();
}


void empty_function(int size_)
{
    __asm
    {
        mov ecx, size_;

        CYCLE:
            NOP
        loop CYCLE;
    }
}
