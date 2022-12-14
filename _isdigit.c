#include "monty.h"

int _isdigit(char *str)
{
	int i = 0;
	int digit = 1;

	while ((int)str[i] != 10)
	{
		if ((int)str[i] == 0)
			break;
		
		if ((int)str[i] < 48 || (int)str[i] > 57)
		{
			digit = 0;
			break;
		}
		i++;
	}

	return (digit);
}
