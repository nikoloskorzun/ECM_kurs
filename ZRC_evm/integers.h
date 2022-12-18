#include "types.h"
#ifndef __INTEGERS__
#define __INTEGERS__
void add8_reg(int _size, int8_t* a, int8_t* b);
void add16_reg(int _size, int16_t* a, int16_t* b);
void add32_reg(int _size, int32_t* a, int32_t* b);

void sub8_reg(int _size, int8_t* a, int8_t* b);
void sub16_reg(int _size, int16_t* a, int16_t* b);
void sub32_reg(int _size, int32_t* a, int32_t* b);

void mul8_reg(int _size, int8_t* a, int8_t* b);
void mul16_reg(int _size, int16_t* a, int16_t* b);
void mul32_reg(int _size, int32_t* a, int32_t* b);

void div8_reg(int _size, int8_t* a, int8_t* b);
void div16_reg(int _size, int16_t* a, int16_t* b);
void div32_reg(int _size, int32_t* a, int32_t* b);


void neg8_reg(int _size, int8_t* a);
void neg16_reg(int _size, int16_t* a);
void neg32_reg(int _size, int32_t* a);

void NOT8_reg(int _size, int8_t* a);
void NOT16_reg(int _size, int8_t* a);
void NOT32_reg(int _size, int32_t* a);



void XOR8_reg(int _size, int16_t* a, int16_t* b);
void XOR16_reg(int _size, int16_t* a, int16_t* b);
void XOR32_reg(int _size, int32_t* a, int32_t* b);

void OR8_reg(int _size, int8_t* a, int8_t* b);
void OR16_reg(int _size, int16_t* a, int16_t* b);
void OR32_reg(int _size, int32_t* a, int32_t* b);

void AND8_reg(int _size, int8_t* a, int8_t* b);
void AND16_reg(int _size, int16_t* a, int16_t* b);
void AND32_reg(int _size, int32_t* a, int32_t* b);





#endif // !__INTEGERS__
