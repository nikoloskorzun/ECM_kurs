#ifndef __FLOATING__
#define __FLOATING__

//	FPU LOADS DATA INTO STACK-TABLE
//	OF REGISTERS AS STACK
//	SO FPU SHOULD BE INITIALIZED ON START OF FUNCTION

// INFO: http://www.softcraft.ru/edu/comparch/practice/asm86/05-fpu/fpu.pdf
#include "types.h"
// arithmetics
void add_floating(int _size, float32_t* a, float32_t* b);
void sub_floating(int _size, float32_t* a, float32_t* b);
void mul_floating(int _size, float32_t* a, float32_t* b);
void div_floating(int _size, float32_t* a, float32_t* b);
// complex arithmetics
void sqrt_floating(int _size, float32_t* a);
void l2_floating(int _size, float32_t* a);
void ln_floating(int _size, float32_t* a);
// trigan
void sin_floating(int _size, float32_t* a);
void tan_floating(int _size, float32_t* a);
void atan_floating(int _size, float32_t* a);

// double arithmetics
void add_double(int size, double64_t* a, double64_t b);
void sub_double(int _size, double64_t* a, double64_t* b);
void mul_double(int _size, double64_t* a, double64_t* b);
void div_double(int _size, double64_t* a, double64_t* b);
// complex arithmetics
void sqrt_double(int _size, double64_t* a);
void l2_double(int _size, double64_t* a);
void ln_double(int _size, double64_t* a);
// trigan
void sin_double(int _size, double64_t* a);
void tan_double(int _size, double64_t* a);
void atan_double(int _size, double64_t* a);

#endif // !__FLOATING__
