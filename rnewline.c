#include "monty.h"

/**
* remove_newline - removes a newline character at the end
* of a string.
* @str: string
* Return: new string.
*/
char *remove_newline(char *str)
{
	char *new_str = malloc(strlen(str) * sizeof(char));
	size_t i = 0;

	for (; i < strlen(str); i++)
	{
		new_str[i] = str[i];
	}
	new_str[strlen(str) - 1] = '\0';
	return (new_str);
}

