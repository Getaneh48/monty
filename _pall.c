#include "monty.h"

/**
* stack_pall - print all the values of the stack.
* @stack: head of the stack.
* @line_number: integer value.
*/
void stack_pall(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
	if (*stack != NULL)
	{
		stack_t *node = *stack;

		while (node != NULL)
		{
			printf("%d\n", node->n);
			node = node->next;
		}
	}

}
