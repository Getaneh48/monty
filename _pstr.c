#include "monty.h"

/**
* stack_pstr - prints the string starting at the top of the stack.
* @stack: head of the stack.
* @line_number: integer value.
*/
void stack_pstr(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
	stack_t *node = *stack;

	if (*stack != NULL)
	{
		while (node != NULL)
		{
			if (node->n < 0 || node->n > 127 || node->n == 0)
			{
				break;
			}
			printf("%c", node->n);
			node = node->next;
		}

	}
	printf("\n");
}
