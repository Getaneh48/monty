#include "monty.h"

char *remove_newline(char *str)
{
        char *new_str = malloc(strlen(str) * sizeof(char));
        int i = 0;

        while (str[i] != '\n')
        {
                new_str[i] = str[i];
                i++;
        }

        return (new_str);
}

