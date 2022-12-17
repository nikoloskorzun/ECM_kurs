#include "floating.h"


void add_floating(int _size, float32_t* a, float32_t* b) {
	__asm {
		finit				; init co-processor
		mov eax, a;
		mov ebx, b;
		mov ecx, _size;
		Addition:
			// place floating into floating register
			fld		[eax]	; load a[i] into co-proc
			fld		[ebx]	; load b[i] into co-proc
			fadd			; sum in ST
			FSTP	st(0)	;
			
			add eax, 2		;
			add ebx, 2		;

		loop Addition;
	}
}

void sub_floating(int _size, float32_t* a, float32_t* b)
{
	__asm {
		finit				; init co - processor
		mov eax, a			;
		mov ebx, b			;
		mov ecx, _size		;
		Subtraction:
		// place floating into floating register
			fld[eax]		; load a[i] into co - proc
			fld[ebx]		; load b[i] into co - proc
			fsub			; sum in ST
			FSTP	st(0)	;
			add eax, 2		;
			add ebx, 2		;
		loop Subtraction;
	}
}

void mul_floating(int _size, float32_t* a, float32_t* b)
{
	__asm {
		finit			; init co-proc
		mov eax, a		;
		mov ebx, b		;
		mov ecx, _size	;
		Multiplication:
			// place floating into floating register
			fld		[eax]	; load a[i] into co - proc
			fld		[ebx]	; load b[i] into co - proc
			fmul			; multiply
			FSTP	st(0)	;
			add eax, 2		;
			add ebx, 2		;
		loop Multiplication;
	}
}

void div_floating(int _size, float32_t* a, float32_t* b) {
	__asm {
		finit; init co - proc
		mov eax, a;
		mov ebx, b;
		mov ecx, _size;
	Division:
		// place floating into floating register
		fld		[eax]; load a[i] into co - proc
		fld		[ebx]; load b[i] into co - proc
		fdiv		 ; division
		FSTP	st(0);
		add eax, 2;
		add ebx, 2;
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
		mov eax, a		;
		mov ecx, _size	;

	SQRT:
		// place floating into floating register
		fld	[eax]		; load a[i] into co - proc
		fsqrt			; get sqrt and replace st(i) on stack pos with result
		FSTP st(0)		;
		add eax, 2		;
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
		mov eax, a;
		mov ecx, _size;

	LOG2:
		// place floating into floating register
		fld1;
		fld		[eax]	; load a[i] into co - proc
		FYL2X			; get sqrtand replace st(i) on stack pos with result
		FSTP st(1)		;
		FSTP st(0)		;	
		add eax, 2		;
	loop LOG2;
	}
}

void ln_floating(int _size, float32_t* a)
{
	__asm {
		finit; init co - proc
		mov eax, a;
		mov ecx, _size;
	Ln:
		// place floating into floating register
		// ln(x) = log2(x) / log2e 
		fldl2e		; st: log2(e)
		fld [eax]	; st: log2(e)*a[i]
		fyl2x		; st: ln(a[i])
		FSTP st(1)	;
		FSTP st(0)	;
		add eax, 2	;
	loop Ln;
	}
}
