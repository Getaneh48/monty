#include "monty.h"

/**
* stack_rotl - rotates the stack to the top.The top element of the stack
* becomes the last one, and the second top element of the stack becomes
* the first one
* @stack: head of the stack.
* @line_number: integer value.
*/
void stack_rotl(__attribute__((unused)) stack_t **stack,
__attribute__((unused)) unsigned int line_number)
{
	if (*stack != NULL)
	{
		int n;
		stack_t *new_node = NULL, *head = *stack, *temp;

		n = (*stack)->n;
		temp = *stack;
		while (head != NULL)
		{
			if (head->next == NULL)
			{
				new_node = malloc(sizeof(stack_t));
				if (new_node == NULL)
				{
					fprintf(stderr, "Error: malloc failed\n");
					exit(EXIT_FAILURE);
				}

				new_node->n = n;
				head->next = new_node;
				new_node->prev = head;
				new_node->next = NULL;
				break;
			}
			head = head->next;
		}

		*stack = (*stack)->next;
		free(temp); /* remove the first node */

	}
	else
	{
		exit(EXIT_FAILURE);
	}
}
