#include "floating.h"


void add_mem_floating(int _size, float32_t* a, float32_t* b) {
	__asm {
		finit; init co - processor
		lea eax, a;
		lea ebx, b;
		mov ecx, _size;
	Addition:
		// place floating into floating register
		fld	[ebx]; load b[i] into co - proc
		fadd [eax]; sum in ST
		FSTP	st(0);
		add eax, 4;
		add ebx, 4;
	loop Addition;
	}
}

void sub_mem_floating(int _size, float32_t* a, float32_t* b)
{
	__asm {
		finit; init co - processor
		lea eax, a;
		lea ebx, b;
		mov ecx, _size;
	Subtraction:
		// place floating into floating register
		fld[ebx]; load b[i] into co - proc
		fsub [eax]; sum in ST
		FSTP	st(0);
		add eax, 4;
		add ebx, 4;
	loop Subtraction;
	}
}


void mul_mem_floating(int _size, float32_t* a, float32_t* b)
{
	__asm {
		finit; init co - proc
		lea eax, a;
		lea ebx, b;
		mov ecx, _size;
	Multiplication:
		// place floating into floating register
		fld[ebx]; load b[i] into co - proc
		fmul [eax]; multiply
		FSTP	st(0);
		add eax, 4;
		add ebx, 4;
		loop Multiplication;
	}
}

void div_mem_floating(int _size, float32_t* a, float32_t* b) 
{
	__asm {
		finit; init co - proc
		lea eax, a;
		lea ebx, b;
		mov ecx, _size;
	Division:
		// place floating into floating register
		fld	[ebx]; load b[i] into co - proc
		fdiv [eax]; division
		FSTP	st(0);
		add eax, 4;
		add ebx, 4;
	loop Division;
	}
}
