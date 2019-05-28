#ifndef _CIPHER_H
#define _CIPHER_H


#include<stdio.h>
#include<string.h>
void decryption(char x[10], int key)
{
	int i = 0, j, m = 0, n = 0;
	char temp[10];
	int temp2[10];
	for (i = 0; i < 10; i++)
		temp[i] = i + 1;
	i = 0;
	int t[10] = { 1,1,1,1,1,1,1,1,1,1 };
	while (1)
	{
		m += t[i];
		if (m == key)
		{
			t[i] = 0;
			m = 0;
			//printf("%c", x[i]);
			temp2[n] = temp[i];
			n++;
		}
		if (n == 10)
			break;
		i++;
		if (i == 10)
			i = 0;
	}
	for (i = 0; i < 10; i++)
	{
		for (j = 0; j < 10; j++)
		{
			if (temp2[j] == i + 1)
				temp[i] = x[j];
		}
	}
	for (i = 0; i < 10; i++)
	{
		x[i] = temp[i];
	}
}

#endif // !cipher
