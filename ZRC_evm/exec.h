#ifndef __EXECUTOR__

#define __EXECUTOR__

#ifndef NumberOfElementsArray
	#define NumberOfElementsArray 1000000i32
#endif

#ifndef DelimString
	#define DelimString "========================================================================\n"
#endif

#ifndef UnarOperationString
	#define UnarOperationString "\nUnary operations:\n\n"
#endif

#ifndef BinaryOperationString
	#define BinaryOperationString "\nBinary operations:\n\n"
#endif

#ifndef TriganometricOperationString
	#define TriganometricOperationString "\nTriganometric operations:\n\n"
#endif 



#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "malloc.h"

#include "windows.h"//ha-ha The best way to calculate time...

#include "types.h"
#include "floating.h"
#include "integers.h"



inline void timeit(FunctionPtr* func, char* text_hint, const int argcount, ...);

void performance_comparison();

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


int8_t get_random_int8_t();
uint8_t get_random_uint8_t();

int16_t get_random_int16_t();
uint16_t get_random_uint16_t();

int32_t get_random_int32_t();
uint32_t get_random_uint32_t();

void empty_function(int size_);
#endif
