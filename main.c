#include "monty.h"

void execute_opcode(char *opcode, stack_t **stack, unsigned int line_number)
{
	size_t i;
	instruction_t opcodes[] = {
        {"push", opcode_push},
        {"pall", opcode_pall},
        {"pop", opcode_pop},
        {"nop", opcode_nop},
	{"add", opcode_add},
        {NULL, NULL}
    };

    for (i = 0; opcodes[i].opcode != NULL; i++)
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
	char *line = NULL;
	char *opcode;
	size_t line_len = 0;
	unsigned int line_number = 0;
	stack_t *stack = NULL;
	FILE *file;
	
    	if (argc != 2)
    	{
        	fprintf(stderr, "USAGE: monty file\n");
        	exit(EXIT_FAILURE);
    	}

    /* Open and read the Monty byte code file */

    	file = fopen(argv[1], "r");

    	if (file == NULL)
    	{
        	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        	exit(EXIT_FAILURE);
    	}

    /* Parse and execute the Monty byte codes */
	while (getline(&line, &line_len, file) != -1)
    	{
        	line_number++;

        /* Parse the opcode and argument */

        	opcode = strtok(line, " \t\n");

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
