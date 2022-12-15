#include "monty.h"

void stack_push(__attribute__((unused)) stack_t **stack, __attribute__((unused)) unsigned int line_number)
{
	if (stack_value != NULL)
		printf("pushing on to the stack... %d\n", atoi(stack_value));
	stack_value = NULL;
}
