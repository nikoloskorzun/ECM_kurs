#pragma once

#ifndef NumberOfElementsArray
#define NumberOfElementsArray 21474836
#endif // !N



#ifndef __EXECUTOR__

#include "malloc.h"
#include "types.h"
#include "floating.h"
#include "integers.h"
#include "stdio.h"
#include "time.h"

#define __EXECUTOR__
inline void timeit(FunctionPtr* func, char* text_hint, const int argcount, ...);
void perform_integers();
void perform_floats();
#endif
