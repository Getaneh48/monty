#include "monty.h"

/**
* count_array - returns the number of elements
* in the array.
* @arr: array
* Return: number of elements.
*/
int count_array(char **arr)
{
	size_t i = 0;

	while (arr[i] != NULL)
	{
		i++;
	}

	return (i);
}

/**
* interprate - interprates the byte code of a monty file.
* @stack: head of the stack
* @tokens: array of strings.
* @line_no: integer value.
*/
void interprate(stack_t **stack, char **tokens, size_t line_no)
{
	void (*f)(stack_t **stack, unsigned int line_number);
	char *token = tokens[0];

	if (token == NULL || token[0] == '#')
		return;
	if (strlen(token) > 1 || (strlen(token) == 1 &&
		(int)token[strlen(token) - 1] != 10))
	{
		f = get_operations(tokens[0]);
		if (f == NULL)
		{
			fprintf(stderr, "L%ld: Invalid instruction\n", line_no);
			exit(EXIT_FAILURE);
		}

		if (count_array(tokens) > 1)
		{
			stack_value = tokens[1];
			f(stack, line_no);
		}
		else
		{
			f(stack, line_no);
		}
	}
}

char *stack_value = NULL;

/**
* main - entry point of the application.
* @argc: no of arguments.
* @argv: array of arguments.
* Return: 1 on failure, 0 on success.
*/
int main(int argc, char *argv[])
{
	char *line_buf = NULL;
	size_t line_buf_size = 0;
	size_t line_no = 0;
	char **tokens;
	FILE *fp;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	/* Loop through until we are done with the file. */
	while (getline(&line_buf, &line_buf_size, fp) != EOF)
	{
		/* Increment our line count */
		line_no++;
		tokens = tokenize(line_buf, " ");
		interprate(&stack, tokens, line_no);
		free(tokens);
	}

	/* Free the allocated line buffer */
	free(line_buf);
	line_buf = NULL;

	/* Close the file */
	fclose(fp);

	return (EXIT_SUCCESS);
}
