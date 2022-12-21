#include "types.h"
#ifndef __INTEGERS__
#define __INTEGERS__
void add8_reg_signed(int _size, int8_t* a, int8_t* b);
void add16_reg_signed(int _size, int16_t* a, int16_t* b);
void add32_reg_signed(int _size, int32_t* a, int32_t* b);

void sub8_reg_signed(int _size, int8_t* a, int8_t* b);
void sub16_reg_signed(int _size, int16_t* a, int16_t* b);
void sub32_reg_signed(int _size, int32_t* a, int32_t* b);

void mul8_reg_signed(int _size, int8_t* a, int8_t* b);
void mul16_reg_signed(int _size, int16_t* a, int16_t* b);
void mul32_reg_signed(int _size, int32_t* a, int32_t* b);

void div8_reg_signed(int _size, int8_t* a, int8_t* b);
void div16_reg_signed(int _size, int16_t* a, int16_t* b);
void div32_reg_signed(int _size, int32_t* a, int32_t* b);


void neg8_reg_signed(int _size, int8_t* a);
void neg16_reg_signed(int _size, int16_t* a);
void neg32_reg_signed(int _size, int32_t* a);

void NOT8_reg_signed(int _size, int8_t* a);
void NOT16_reg_signed(int _size, int16_t* a);
void NOT32_reg_signed(int _size, int32_t* a);



void XOR8_reg_signed(int _size, int8_t* a, int8_t* b);
void XOR16_reg_signed(int _size, int16_t* a, int16_t* b);
void XOR32_reg_signed(int _size, int32_t* a, int32_t* b);

void OR8_reg_signed(int _size, int8_t* a, int8_t* b);
void OR16_reg_signed(int _size, int16_t* a, int16_t* b);
void OR32_reg_signed(int _size, int32_t* a, int32_t* b);

void AND8_reg_signed(int _size, int8_t* a, int8_t* b);
void AND16_reg_signed(int _size, int16_t* a, int16_t* b);
void AND32_reg_signed(int _size, int32_t* a, int32_t* b);






void add8_reg_unsigned(int _size, int8_t* a, int8_t* b);
void add16_reg_unsigned(int _size, int16_t* a, int16_t* b);
void add32_reg_unsigned(int _size, int32_t* a, int32_t* b);

void sub8_reg_unsigned(int _size, int8_t* a, int8_t* b);
void sub16_reg_unsigned(int _size, int16_t* a, int16_t* b);
void sub32_reg_unsigned(int _size, int32_t* a, int32_t* b);

void mul8_reg_unsigned(int _size, int8_t* a, int8_t* b);
void mul16_reg_unsigned(int _size, int16_t* a, int16_t* b);
void mul32_reg_unsigned(int _size, int32_t* a, int32_t* b);

void div8_reg_unsigned(int _size, int8_t* a, int8_t* b);
void div16_reg_unsigned(int _size, int16_t* a, int16_t* b);
void div32_reg_unsigned(int _size, int32_t* a, int32_t* b);



void NOT8_reg_unsigned(int _size, int8_t* a);
void NOT16_reg_unsigned(int _size, int16_t* a);
void NOT32_reg_unsigned(int _size, int32_t* a);



void XOR8_reg_unsigned(int _size, int8_t* a, int8_t* b);
void XOR16_reg_unsigned(int _size, int16_t* a, int16_t* b);
void XOR32_reg_unsigned(int _size, int32_t* a, int32_t* b);

void OR8_reg_unsigned(int _size, int8_t* a, int8_t* b);
void OR16_reg_unsigned(int _size, int16_t* a, int16_t* b);
void OR32_reg_unsigned(int _size, int32_t* a, int32_t* b);

void AND8_reg_unsigned(int _size, int8_t* a, int8_t* b);
void AND16_reg_unsigned(int _size, int16_t* a, int16_t* b);
void AND32_reg_unsigned(int _size, int32_t* a, int32_t* b);








void neg8_mem_signed(int _size, int8_t* a);
void neg16_mem_signed(int _size, int16_t* a);
void neg32_mem_signed(int _size, int32_t* a);

void NOT8_mem_signed(int _size, int8_t* a);
void NOT16_mem_signed(int _size, int16_t* a);
void NOT32_mem_signed(int _size, int32_t* a);


void NOT8_mem_unsigned(int _size, int8_t* a);
void NOT16_mem_unsigned(int _size, int16_t* a);
void NOT32_mem_unsigned(int _size, int32_t* a);








void add8_mem_signed_left(int _size, int8_t* a, int8_t* b);
void add16_mem_signed_left(int _size, int16_t* a, int16_t* b);
void add32_mem_signed_left(int _size, int32_t* a, int32_t* b);

void sub8_mem_signed_left(int _size, int8_t* a, int8_t* b);
void sub16_mem_signed_left(int _size, int16_t* a, int16_t* b);
void sub32_mem_signed_left(int _size, int32_t* a, int32_t* b);


void add8_mem_signed_right(int _size, int8_t* a, int8_t* b);
void add16_mem_signed_right(int _size, int16_t* a, int16_t* b);
void add32_mem_signed_right(int _size, int32_t* a, int32_t* b);

void sub8_mem_signed_right(int _size, int8_t* a, int8_t* b);
void sub16_mem_signed_right(int _size, int16_t* a, int16_t* b);
void sub32_mem_signed_right(int _size, int32_t* a, int32_t* b);



void XOR8_mem_signed_left(int _size, int8_t* a, int8_t* b);
void XOR16_mem_signed_left(int _size, int16_t* a, int16_t* b);
void XOR32_mem_signed_left(int _size, int32_t* a, int32_t* b);

void OR8_mem_signed_left(int _size, int8_t* a, int8_t* b);
void OR16_mem_signed_left(int _size, int16_t* a, int16_t* b);
void OR32_mem_signed_left(int _size, int32_t* a, int32_t* b);

void AND8_mem_signed_left(int _size, int8_t* a, int8_t* b);
void AND16_mem_signed_left(int _size, int16_t* a, int16_t* b);
void AND32_mem_signed_left(int _size, int32_t* a, int32_t* b);


void XOR8_mem_signed_right(int _size, int8_t* a, int8_t* b);
void XOR16_mem_signed_right(int _size, int16_t* a, int16_t* b);
void XOR32_mem_signed_right(int _size, int32_t* a, int32_t* b);

void OR8_mem_signed_right(int _size, int8_t* a, int8_t* b);
void OR16_mem_signed_right(int _size, int16_t* a, int16_t* b);
void OR32_mem_signed_right(int _size, int32_t* a, int32_t* b);

void AND8_mem_signed_right(int _size, int8_t* a, int8_t* b);
void AND16_mem_signed_right(int _size, int16_t* a, int16_t* b);
void AND32_mem_signed_right(int _size, int32_t* a, int32_t* b);



void add8_mem_unsigned_left(int _size, int8_t* a, int8_t* b);
void add16_mem_unsigned_left(int _size, int16_t* a, int16_t* b);
void add32_mem_unsigned_left(int _size, int32_t* a, int32_t* b);

void sub8_mem_unsigned_left(int _size, int8_t* a, int8_t* b);
void sub16_mem_unsigned_left(int _size, int16_t* a, int16_t* b);
void sub32_mem_unsigned_left(int _size, int32_t* a, int32_t* b);


void add8_mem_unsigned_right(int _size, int8_t* a, int8_t* b);
void add16_mem_unsigned_right(int _size, int16_t* a, int16_t* b);
void add32_mem_unsigned_right(int _size, int32_t* a, int32_t* b);

void sub8_mem_unsigned_right(int _size, int8_t* a, int8_t* b);
void sub16_mem_unsigned_right(int _size, int16_t* a, int16_t* b);
void sub32_mem_unsigned_right(int _size, int32_t* a, int32_t* b);



void XOR8_mem_unsigned_left(int _size, int8_t* a, int8_t* b);
void XOR16_mem_unsigned_left(int _size, int16_t* a, int16_t* b);
void XOR32_mem_unsigned_left(int _size, int32_t* a, int32_t* b);

void OR8_mem_unsigned_left(int _size, int8_t* a, int8_t* b);
void OR16_mem_unsigned_left(int _size, int16_t* a, int16_t* b);
void OR32_mem_unsigned_left(int _size, int32_t* a, int32_t* b);

void AND8_mem_unsigned_left(int _size, int8_t* a, int8_t* b);
void AND16_mem_unsigned_left(int _size, int16_t* a, int16_t* b);
void AND32_mem_unsigned_left(int _size, int32_t* a, int32_t* b);


void XOR8_mem_unsigned_right(int _size, int8_t* a, int8_t* b);
void XOR16_mem_unsigned_right(int _size, int16_t* a, int16_t* b);
void XOR32_mem_unsigned_right(int _size, int32_t* a, int32_t* b);

void OR8_mem_unsigned_right(int _size, int8_t* a, int8_t* b);
void OR16_mem_unsigned_right(int _size, int16_t* a, int16_t* b);
void OR32_mem_unsigned_right(int _size, int32_t* a, int32_t* b);

void AND8_mem_unsigned_right(int _size, int8_t* a, int8_t* b);
void AND16_mem_unsigned_right(int _size, int16_t* a, int16_t* b);
void AND32_mem_unsigned_right(int _size, int32_t* a, int32_t* b);




void mul8_mem_signed(int _size, int8_t* a, int8_t* b);
void mul16_mem_signed(int _size, int16_t* a, int16_t* b);
void mul32_mem_signed(int _size, int32_t* a, int32_t* b);

void div8_mem_signed(int _size, int8_t* a, int8_t* b);
void div16_mem_signed(int _size, int16_t* a, int16_t* b);
void div32_mem_signed(int _size, int32_t* a, int32_t* b);


void mul8_mem_unsigned(int _size, int8_t* a, int8_t* b);
void mul16_mem_unsigned(int _size, int16_t* a, int16_t* b);
void mul32_mem_unsigned(int _size, int32_t* a, int32_t* b);

void div8_mem_unsigned(int _size, int8_t* a, int8_t* b);
void div16_mem_unsigned(int _size, int16_t* a, int16_t* b);
void div32_mem_unsigned(int _size, int32_t* a, int32_t* b);




#endif // !__INTEGERS__
