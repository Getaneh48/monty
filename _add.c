#include "monty.h"

/**
* stack_add - adds the top 2 value of the stack.
* @stack: head of the stack.
* @line_number: integer value.
*/
void stack_add(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
	if (*stack != NULL)
	{
		int n;
		stack_t *node = *stack;

		if (count_stack(*stack) < 2)
		{
			fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
			exit(EXIT_FAILURE);
		}
		n = (*stack)->n + (*stack)->next->n;
		(*stack)->next->n = n;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(node);
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
}
