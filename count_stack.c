#include "monty.h"

/**
* count_stack - count the nodes of the stack.
* @stack: head of the stack.
* Return: the number of nodes.
*/
int count_stack(stack_t *stack)
{
	int count = 0;

	while (stack != NULL)
	{
		count++;
		stack = stack->next;
	}

	return (count);
}
