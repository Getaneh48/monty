#include "monty.h"

/**
* get_operations - returns a function for the given opcode.
* @opcode: operation code
* Return: a function
*/
void (*get_operations(char *opcode))(stack_t **stack, unsigned int line_number)
{
	instruction_t inst[] = {
		{"push", stack_push},
		{"pall", stack_pall},
		{"pint", stack_pint},
		{"pop", stack_pop},
		{"swap", stack_swap},
		{"add", stack_add},
		{"sub", stack_sub},
		{"div", stack_div},
		{"mul", stack_mul},
		{"mod", stack_mod}
	};

	int count = 10, i = 0, tr = 0;

	if (opcode[strlen(opcode) - 1] == '\n')
	{
		tr = 1;
		opcode = remove_newline(opcode);
	}
	while (i < count)
	{

		if (strcmp(inst[i].opcode, opcode) == 0)
		{
			if (tr)
				free(opcode);
			return (inst[i].f);
		}
		i++;
	}

		if (tr)
			free(opcode);

	return (NULL);
}
