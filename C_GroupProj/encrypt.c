#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "encrypt.h"

int chartoasc(char c)
{
	int i = 0;
	i = c;
	return i;
}

int xor(int i)
{
	int m = 27;
	int result = 0;
	if (59 == i || 100 == i)
	{
		return i;
	}
	result = i ^ m;
	return result;
}

char asctochar(int a)
{
	char c;
	c = a;
	return c;
}


unsigned long encrypt(const char* input, const unsigned int input_len, const unsigned int HASH_SIZE)
{
	char inputBuff[50];
	char cipherBuff[50];
	unsigned int i = 0;
	int asc = 0;
	char ch = 0;
	int x = 0;

	memset(inputBuff, 0, sizeof(inputBuff));
	memset(cipherBuff, 0, sizeof(cipherBuff));
	strcpy(inputBuff, input);
	for (i = 0; i < input_len; i++)
	{
		ch = inputBuff[i];
		asc = chartoasc(ch);
		x = xor (asc);
		cipherBuff[i] = asctochar(x);
	}
	cipherBuff[i] = '\0';

	char* hash = cipherBuff;

	unsigned long hash_value;
	for (hash_value = 0; *hash != '\0'; ++hash)
		hash_value = *hash + 31 * hash_value;

	double size = pow(16, HASH_SIZE);
	char size_str[30];
	sprintf(size_str, "%f", size);

	
	return hash_value % atol(size_str);
}