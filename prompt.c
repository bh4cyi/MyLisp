#include <stdio.h>
#include <stdlib.h>

#include <editline/readline.h>

/* Declare a buffer for user input of size 2048 */
static char input[2048];

int main(int argc, char** argv)
{
	/* Print Version and Exit Information */
    puts("QLisp Version 0.0.0.0.1");
    puts("Press Ctrl+c to Exit\n");

    /* In a never ending loop */
    while (1)
    {
        /* Output our prompt */
        // fputs("Qlisp> ", stdout);
        char* input = readline("QLisp> ");
        /* Read a line of user input of maxium size 2048 */
        //fgets(input, 2048, stdin);
        /* Add input to history */
        add_history(input);
        /* Echo input back to user */
        printf("You have just input %s\n", input);

        /* Free retrieved input */
        free(input);
     }

    return 0;
}

