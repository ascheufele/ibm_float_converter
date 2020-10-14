#include "stdio.h"
#include "stdlib.h"
#include "math.h"

void assn_bits(int* nums);
void get_input(int* nums);
double ibm_to_decimal();
void clear_keyboard_buffer();

union ibm_f
{
	unsigned value;
	struct components
	{
		unsigned mantissa : 24;
		unsigned exponent : 7;
		unsigned sign : 1;
	}components;
	struct bits
	{
		unsigned b0 : 1;
		unsigned b1 : 1;
		unsigned b2 : 1;
		unsigned b3 : 1;
		unsigned b4 : 1;
		unsigned b5 : 1;
		unsigned b6 : 1;
		unsigned b7 : 1;
		unsigned b8 : 1;
		unsigned b9 : 1;
		unsigned b10 : 1;
		unsigned b11 : 1;
		unsigned b12 : 1;
		unsigned b13 : 1;
		unsigned b14 : 1;
		unsigned b15 : 1;
		unsigned b16 : 1;
		unsigned b17 : 1;
		unsigned b18 : 1;
		unsigned b19 : 1;
		unsigned b20 : 1;
		unsigned b21 : 1;
		unsigned b22 : 1;
		unsigned b23 : 1;
		unsigned b24 : 1;
		unsigned b25 : 1;
		unsigned b26 : 1;
		unsigned b27 : 1;
		unsigned b28 : 1;
		unsigned b29 : 1;
		unsigned b30 : 1;
		unsigned b31 : 1;
	}bits;
}ibm_f;

int main(int argc, char* argv[])
{
	char user_wishes_to_continue = 'y';
	int input[32];
	printf("This program takes an input of 32 bits representing an IBM floating point number and converts it to base ten.\n");
	while (user_wishes_to_continue != 'n')
	{
		printf("Enter 32 bits representing an IBM Floating point number.\n");
		printf("(Sign : 1, Exponent : 7, Mantissa : 24)\n");
		printf("input: ");
		get_input(input);
		assn_bits(input);
		printf("%g\n", ibm_to_decimal());

		printf("\nWould you like to convert another number? (y/n): ");
		scanf_s("%c", &user_wishes_to_continue);
		clear_keyboard_buffer();
	}
	printf("Thank you for using my tool.\n-Alex Scheufele\n");
	return 0;
}

void get_input(int* nums)
{
	int count = 0;
	char c;
	scanf_s("%c", &c);
	while (c != '\n')
	{
		nums[count] = atoi(&c);
		++count;
		scanf_s("%c", &c);
	}
}

void assn_bits(int* nums)
{
	ibm_f.bits.b0 = nums[31];
	ibm_f.bits.b1 = nums[30];
	ibm_f.bits.b2 = nums[29];
	ibm_f.bits.b3 = nums[28];
	ibm_f.bits.b4 = nums[27];
	ibm_f.bits.b5 = nums[26];
	ibm_f.bits.b6 = nums[25];
	ibm_f.bits.b7 = nums[24];
	ibm_f.bits.b8 = nums[23];
	ibm_f.bits.b9 = nums[22];
	ibm_f.bits.b10 = nums[21];
	ibm_f.bits.b11 = nums[20];
	ibm_f.bits.b12 = nums[19];
	ibm_f.bits.b13 = nums[18];
	ibm_f.bits.b14 = nums[17];
	ibm_f.bits.b15 = nums[16];
	ibm_f.bits.b16 = nums[15];
	ibm_f.bits.b17 = nums[14];
	ibm_f.bits.b18 = nums[13];
	ibm_f.bits.b19 = nums[12];
	ibm_f.bits.b20 = nums[11];
	ibm_f.bits.b21 = nums[10];
	ibm_f.bits.b22 = nums[9];
	ibm_f.bits.b23 = nums[8];
	ibm_f.bits.b24 = nums[7];
	ibm_f.bits.b25 = nums[6];
	ibm_f.bits.b26 = nums[5];
	ibm_f.bits.b27 = nums[4];
	ibm_f.bits.b28 = nums[3];
	ibm_f.bits.b29 = nums[2];
	ibm_f.bits.b30 = nums[1];
	ibm_f.bits.b31 = nums[0];
}

double ibm_to_decimal()
{
	double result = 0;
	int excess = abs(64 - (int)ibm_f.components.exponent);
	int sixteen = pow(16, excess);
	double _mant = 0;
	for (int i = 24; i >= 0; --i)
	{
		if (ibm_f.components.mantissa & 1 << i)
		{
			//printf("%d bit on\n", 24-i);
			_mant += pow(2, -(24-i));
		}
	}
	//printf("exponent: %d\n", ibm_f.components.exponent);
	//printf("adjusted exponent: %d\n", excess);
	//printf("sixteen: %d\n", sixteen);
	return result = sixteen * _mant;
}

void clear_keyboard_buffer()
{
	char c = ' ';
	while (c != '\n')
		scanf_s("%c", &c);
}