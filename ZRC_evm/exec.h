#ifndef __EXECUTOR__

#ifndef NumberOfElementsArray
	//#define NumberOfElementsArray 100000000i32
	#define NumberOfElementsArray 1000000i32
#endif
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "malloc.h"

#include "types.h"
#include "floating.h"
#include "integers.h"


#define __EXECUTOR__
inline void timeit(FunctionPtr* func, char* text_hint, const int argcount, ...);

void perform_numbers();

void perform_integers();


void perform_signed_integers();

void perform_signed_int8_reg();
void perform_signed_int16_reg();
void perform_signed_int32_reg();
void perform_signed_int8_mem();
void perform_signed_int16_mem();
void perform_signed_int32_mem();

void perform_unsigned_integers();

void perform_unsigned_int8_reg();
void perform_unsigned_int16_reg();
void perform_unsigned_int32_reg();
void perform_unsigned_int8_mem();
void perform_unsigned_int16_mem();
void perform_unsigned_int32_mem();


void perform_floats();

void empty_function();
#endif
