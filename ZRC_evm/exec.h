#ifndef __EXECUTOR__

#ifndef NumberOfElementsArray
	#define NumberOfElementsArray 100000000i32
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

void perform_signed_int8();
void perform_signed_int16();
void perform_signed_int32();

void perform_unsigned_integers();

void perform_unsigned_int8();
void perform_unsigned_int16();
void perform_unsigned_int32();



void perform_floats();

void empty_function();
#endif
