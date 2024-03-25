#include <stdio.h>
#include <stdint.h>

uint8_t get_first_param(uint64_t *);
uint8_t get_second_param(uint64_t *);
uint8_t get_third_param(uint64_t *);
uint8_t reflect_bits(uint8_t , uint8_t );

int main(int argc, char **argv)
{
	
	uint64_t val = 0x5FABFF01;
	uint8_t param1 = 0, param2 = 0, param3 = 0;
	printf("Initial value: %x\n", (int)val);
	param1 = get_first_param(&val);
	param2 = get_second_param(&val);
	param3 = get_third_param(&val);
	printf("param1 = %x\nparam2 = %b\nparam3 = %x\n", param1, param2, param3);
	return 0;
}

uint8_t get_first_param(uint64_t *val)
{
	//second byte of input value
	int8_t mask = 0b11111111, res = 0;
	res = (*val >> 8)&mask;
	return res;
}

uint8_t get_second_param(uint64_t *val)
{
	//inverse of 7th bit
	uint8_t mask = 0b1, res = 0;
	res = !((*val >> 7)&mask);
	return res;
}

uint8_t get_third_param(uint64_t *val)
{
	//mirror of 17th-20th bits
	uint8_t mask = 0b1111, res = 0;
	res = reflect_bits((*val>>17)&mask, 4);
	return res;
}

uint8_t reflect_bits(uint8_t bits, uint8_t len)
{
	uint8_t reflected_bits = 0;
	for(uint8_t i = 0; i<len; i++)
	{
		reflected_bits |= (bits&1);
		bits = bits>>1;
		reflected_bits=reflected_bits<<1;
	}
	return reflected_bits>>1;
}
