#include "monty.h"

int count_array(char **arr)
{
	size_t i = 0;

	while (arr[i] != NULL)
	{
		i++;
	}

	return (i);
}

void interprate(stack_t **stack, char **tokens, size_t line_no)
{
	void (*f)(stack_t **stack, unsigned int line_number);
	char *token = tokens[0];

			printf("no val - %s\n", token);
	
	if (strlen(token) > 1 || (strlen(token) == 1 &&(int)token[strlen(token) - 1] != 10))
	{
		f = get_operations(tokens[0]);
		if (f == NULL)
		{
			fprintf(stderr, "L%ld: Invalid instruction\n", line_no);
			exit(EXIT_FAILURE);
		}
	
		if (count_array(tokens) > 1) 
		{
			if (_isdigit(tokens[1]))
			{
				stack_value = atoi(tokens[1]);
				f(stack, line_no);
			}
			else
			{
				fprintf(stderr, "L%ld: IInvalid instruction\n", line_no);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			f(stack, line_no);
		}
	}
}

int stack_value = 0;

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
		return EXIT_FAILURE;
	}
  
	fp = fopen(argv[1], "r");
	if (!fp)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return EXIT_FAILURE;
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

	return EXIT_SUCCESS;
}
