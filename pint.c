#include "monty.h"

/**
 * opcode_pint - prints the value at the top of the stack
 * @stack: double pointer to tge stack
 * @line_number: line number
 */
void opcode_pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}
