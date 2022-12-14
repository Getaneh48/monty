#include "monty.h"
/**
* free_memory - frees the allocated memory in heap.
* @mem: array of memory.
*/
void free_memory(char **mem)
{
	int i = 0;

	if (mem != NULL || mem[0] != NULL)
	{
		while (mem[i] != NULL)
		{
			free(mem[i]);
			i++;
		}
		if (mem)
			free(mem);
	}
}
