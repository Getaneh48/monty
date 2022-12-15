#include "monty.h"

/**
* stack_pint - print all the values of the stack.
* @stack: head of the stack.
* @line_number: integer value.
*/
void stack_pint(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
	if (*stack != NULL)
	{
		stack_t *node = *stack;

		printf("%d\n", node->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
}
