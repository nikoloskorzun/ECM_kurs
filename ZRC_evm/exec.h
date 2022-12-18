#ifndef NumberOfElementsArray
#define NumberOfElementsArray 21474836
#endif // !N



#ifndef __EXECUTOR__


#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "malloc.h"

#include "types.h"
#include "floating.h"
#include "integers.h"


#define __EXECUTOR__
inline void timeit(FunctionPtr* func, char* text_hint, const int argcount, ...);
void perform_integers();
void perform_signed_integers();
void perform_unsigned_integers();
void perform_floats();

void empty_function();
#endif
