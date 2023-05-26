#include "monty.h"

/**
 * opcode_add - add the top two value in the stack
 * @stack: double pointer tto stack
 * @line_number: line number
 */
void opcode_add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	opcode_pop(stack, line_number);
}
