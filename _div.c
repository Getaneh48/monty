#include "monty.h"

/**
* stack_div - divides the top 2 value of the stack.
* @stack: head of the stack.
* @line_number: integer value.
*/
void stack_div(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
	if (*stack != NULL)
	{
		int n;
		stack_t *node = *stack;

		if (count_stack(*stack) < 2)
		{
			fprintf(stderr, "L%d: can't div, stack too short", line_number);
			exit(EXIT_FAILURE);
		}
		if ((*stack)->n == 0)
		{
			fprintf(stderr, "L%d: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		n = (*stack)->next->n / (*stack)->n;
		(*stack)->next->n = n;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(node);
	}
}
