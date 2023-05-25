#include "monty.h"
/**
 * opcode_push - Pushes an element onto the stack.
 * @stack: Double pointer to the head of the stack
 * @n: value to be pushed
 */

void opcode_push(stack_t **stack, unsigned int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->prev = NULL;

	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	else
	{
		new->next = NULL;
	}

	*stack = new;
}

/**
 * opcode_pall - Prints all the values on the stack, starting from the top of the stack.
 * @stack: Double pointer to the head of the stack
 */
void opcode_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
