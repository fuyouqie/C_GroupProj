#include <stdio.h>
#include <string.h>
#include "encryp.h"

int main() {
	char a[20];
	char encrypted[50];
	printf("Enter Password\n");
	scanf("%s", a);
	encrypt(a, &encrypted);
	printf("After encryption:  %s\n", encrypted);

	return 0;
}


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


int encrypt(const char *input, char* cipher)
{
	char inputBuff[50];
	char cipherBuff[50];
	int len = 0;
	int i = 0;
	int asc = 0;
	char ch = 0;
	int x = 0;

	memset(inputBuff, 0, sizeof(inputBuff));
	memset(cipherBuff, 0, sizeof(cipherBuff));
	strcpy(inputBuff, input);
	len = strlen(inputBuff);
	for (i = 0; i < len; i++)
	{
		ch = inputBuff[i];
		asc = chartoasc(ch);
		x = xor (asc);
		cipherBuff[i] = asctochar(x);
	}
	strcpy(cipher, cipherBuff);

	return 0;
}