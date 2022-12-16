

typedef void(*FunctionPtr)();
typedef signed short int16_t;
typedef char int8_t;


int size_of(int data_address) {
	void* in_memory = data_address;
	return sizeof(in_memory);
}


inline void timeit(FunctionPtr* func, int argcount,...) {
	/// <summary>
	/// ... is char*, zero point is argcount
	/// </summary>
	/// <param name="func">function</param>
	/// <param name="argcount">count of arguments</param>
	/// <param name="">FUNCTION UNNECESSORY-ARGUMENTS</param>
	int accum=0;
	
	double time_spent=0.0;
	__asm {
		lea esi, argcount;
		mov ecx, argcount;
		add esi, ecx;
		nop;
		AllocateSize:					; move back to argcount address and count bytes
			push ecx					; to save current ecx
			push esi;
			call size_of;
			add accum, eax				; append eax 
			add esp, 4					; 
			sub esi, 1					;
			pop ecx;
		loop AllocateSize;
		mov ecx, argcount				; add argcount to accumulator
		add esi, ecx					;

		PushArgs:
			push [esi]					;
			sub esi, 1					; move back
		loop PushArgs;

		call	[func];
		add esp, accum;
	}
}


inline void add16_reg(int16_t a, int16_t b) {
	/// <summary>
	/// add func for int16_t
	/// </summary>
	/// <param name="a">first member</param>
	/// <param name="b">second member</param>

	__asm {
		mov ax, a;
		mov bx, b;
		add ax, bx;
	}
}


int main() {
	int16_t x = 10, y = 20;
	timeit(*add16_reg, 2, x, y);
}
