#include "monty.h"

void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
    instruction_t opcodes[] = {
        {"push", opcode_push},
        {"pall", opcode_pall},
        {"pint", opcode_pint},
        {"pop", opcode_pop},
        {"swap", opcode_swap},
        {"add", opcode_add},
        {"nop", opcode_nop},
        {NULL, NULL}
    };

    for (int i = 0; opcodes[i].opcode != NULL; i++)
    {
        if (strcmp(opcode, opcodes[i].opcode) == 0)
        {
            opcodes[i].f(stack, line_number);
            return;
        }
    }

    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    /* Open and read the Monty byte code file */

    FILE *file = fopen(argv[1], "r");

    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Parse and execute the Monty byte codes */

    char *line = NULL;
    size_t line_len = 0;
    unsigned int line_number = 0;
    stack_t *stack = NULL;

    while (getline(&line, &line_len, file) != -1)
    {
        line_number++;

        /* Parse the opcode and argument */

        char *opcode = strtok(line, " \t\n");

        if (opcode == NULL || opcode[0] == '#')
            continue;

        /* Execute the opcode */

        execute_opcode(opcode, &stack, line_number);
    }

    free(line);
    fclose(file);

    /* Free the stack */

    while (stack != NULL)
    {
        stack_t *temp = stack;
        stack = stack->next;
        free(temp);
    }

    return EXIT_SUCCESS;
}
