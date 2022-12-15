#include "monty.h"

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

