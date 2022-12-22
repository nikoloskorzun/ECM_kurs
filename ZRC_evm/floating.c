#include "floating.h"


void add_floating(int _size, float32_t* a, float32_t* b) {
	__asm {
		finit				; init co-processor
		lea eax, a;
		lea ebx, b;
		mov ecx, _size;
		Addition:
			// place floating into floating register
			fld		[eax]	; load a[i] into co-proc
			fld		[ebx]	; load b[i] into co-proc
			fadd			; sum in ST
			FSTP	st(0)	;
			
			add eax, 4		;
			add ebx, 4		;

		loop Addition;
	}
}

void sub_floating(int _size, float32_t* a, float32_t* b)
{
	__asm {
		finit				; init co - processor
		lea eax, a			;
		lea ebx, b			;
		mov ecx, _size		;
		Subtraction:
		// place floating into floating register
			fld[eax]		; load a[i] into co - proc
			fld[ebx]		; load b[i] into co - proc
			fsub			; sum in ST
			FSTP	st(0)	;
			add eax, 4		;
			add ebx, 4		;
		loop Subtraction;
	}
}

void mul_floating(int _size, float32_t* a, float32_t* b)
{
	__asm {
		finit			; init co-proc
		lea eax, a		;
		lea ebx, b		;
		mov ecx, _size	;
		Multiplication:
			// place floating into floating register
			fld		[eax]	; load a[i] into co - proc
			fld		[ebx]	; load b[i] into co - proc
			fmul			; multiply
			FSTP	st(0)	;
			add eax, 4		;
			add ebx, 4		;
		loop Multiplication;
	}
}

void div_floating(int _size, float32_t* a, float32_t* b) {
	__asm {
		finit; init co - proc
		lea eax, a;
		lea ebx, b;
		mov ecx, _size;
	Division:
		// place floating into floating register
		fld		[eax]; load a[i] into co - proc
		fld		[ebx]; load b[i] into co - proc
		fdiv		 ; division
		FSTP	st(0);
		add eax, 4;
		add ebx, 4;
	loop Division;
	}
}

void sqrt_floating(int _size, float32_t* a)
{
	/// <summary>
	/// SOMETIMES THERE IS NEGATIVE a[i]
	/// HANDLE EXCEPTION?
	/// </summary>
	/// <param name="_size"></param>
	/// <param name="a"></param>
	__asm {
		finit			; init co - proc
		lea eax, a		;
		mov ecx, _size	;

	SQRT:
		// place floating into floating register
		fld	[eax]		; load a[i] into co - proc
		fsqrt			; get sqrt and replace st(i) on stack pos with result
		FSTP st(0)		;
		add eax, 4		;
	loop SQRT;
	}
}

void l2_floating(int _size, float32_t* a)
{
	/// <summary>
	/// ST(1) = ST(1) * log2(ST(0))
	/// </summary>
	/// <param name="_size">size of a</param>
	/// <param name="a">array of values</param>
	__asm {
		finit; init co - proc
		lea eax, a;
		mov ecx, _size;

	LOG2:
		// place floating into floating register
		fld1;
		fld		[eax]	; load a[i] into co - proc
		FYL2X			; get sqrtand replace st(i) on stack pos with result
		FSTP st(7)		;
		FSTP st(1)		;
		FSTP st(0)		;
		add eax, 4		;
	loop LOG2;
	}
}

void ln_floating(int _size, float32_t* a)
{
	__asm {
		finit; init co - proc
		lea eax, a;
		mov ecx, _size;
	Ln:
		// place floating into floating register
		// ln(x) = log2(x) / log2e 
		fldl2e		; st: log2(e)
		fld [eax]	; st: log2(e)*a[i]
		fyl2x		; st: ln(a[i])
		FSTP st(1)	;
		FSTP st(0)	;
		add eax, 4	;
	loop Ln;
	}
}

void pow2_floating(int _size, double64_t* a)
{
	__asm {
		finit; init co - proc
		lea eax, a;
		mov ecx, _size;
	POW2:
		// place floating into floating register
		FLD1; // place 1 to st(1)
		fld[eax]; // a[i] in st(0)
		F2XM1;	//2^X-1: st(0)<-2^st(0)-1
		fadd;
		FSTP st(1);
		FSTP st(0);
		add eax, 8;
		loop POW2;
	}
}

void sin_floating(int _size, float32_t* a) 
{
	__asm {
		finit; init co - proc
		lea eax, a;
		mov ecx, _size;
	SIN:
		// sin of a[i] 
		fld[eax]
		FSIN; sin
		// drop from stack
		FSTP st;
		add eax, 4;
	loop SIN;
	}
}

void tan_floating(int _size, float32_t* a)
{
	__asm {
		finit; init co - proc
		lea eax, a;
		mov ecx, _size;
	TAN:
		// tan of a[i] 
		fld[eax]
		FPTAN; partual tangens
		// drop from stack
		FSTP st;
		add eax, 4;
	loop TAN;
	}
}

void atan_floating(int _size, float32_t* a)
{
	__asm {
		finit; init co - proc
		lea eax, a;
		mov ecx, _size;
	ATAN:
		// tan of a[i] 
		fld1;
		fld		[eax];
		FPATAN; partual arctangens
		// drop from stack
		FSTP st(0);
		add eax, 4;
	loop ATAN;
	}
}
