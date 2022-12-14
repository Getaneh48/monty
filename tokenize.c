#include "monty.h"
/**
* tokenize - break down a string with a delimeter.
* @str: string to be tokenized.
* @delim: delimeter used to break the string.
* Return: address of the lists of tokens.
*/
char **tokenize(char *str, char *delim)
{
	int totalt = total_tokens(str, ' ');
	char **tokens = (char **) malloc((totalt + 2) * sizeof(char *));
	char *token = NULL;
	size_t i = 1;
	
	token = strtok(str, delim);
	tokens[0] = token;
	while (token != NULL)
	{
		token = strtok(NULL, delim);
		tokens[i] = token;
		i++;
	}
	return (tokens);
}
