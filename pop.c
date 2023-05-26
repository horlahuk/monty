#include "monty.h"

/**
 * opcode_pop - deletes an item from the top of tge stack
 * @stack: double pointer to the stack
 * @line_number: line number
 */

void opcode_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
