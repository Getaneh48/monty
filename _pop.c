#include "monty.h"

/**
* stack_pop - print all the values of the stack.
* @stack: head of the stack.
* @line_number: integer value.
*/
void stack_pop(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
	if (*stack != NULL)
	{
		stack_t *node = *stack;
		*stack = (*stack)->next;
		free(node);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack", line_number);
		exit(EXIT_FAILURE);
	}
}
