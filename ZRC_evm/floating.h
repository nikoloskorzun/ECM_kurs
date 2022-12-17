#pragma once
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


#endif // !__FLOATING__
