#include "monty.h"

/**
* _isdigit - check if a string is a digit or not.
* @str: string value.
* Return: 1 on success 0 on failure.
*/
int _isdigit(char *str)
{
	int i = 0;
	int digit = 1;

	while ((int)str[i] != 10)
	{
		if ((int)str[i] == 0)
			break;
		 /* check for negative sign. */
		if ((int)str[i] == 45 && isnumber((int)str[i + 1]))
		{
			i++;
			continue;
		}

		if (isnumber((int)str[i]) == 0)
		{
			digit = 0;
			break;
		}
		i++;
	}

	return (digit);
}

/**
* isnumber - check if an aschii value is a number.
* @n: aschii value
* Return: 1 success 0 failure.
*/
int isnumber(int n)
{
	int result = 1;

	if (n < 48 || n > 57)
		result = 0;
	return (result);
}
