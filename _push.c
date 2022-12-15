#include "monty.h"

/**
* stack_push - push a value on top of the stack.
* @stack: head of the stack.
* @line_number: integer value.
*/
void stack_push(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (stack_value == NULL || !_isdigit(stack_value))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node->n = atoi(stack_value);
	if (*stack == NULL)
	{
		new_node->prev = NULL;
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
		new_node->prev = NULL;
		*stack = new_node;
	}
	stack_value = NULL;
}
