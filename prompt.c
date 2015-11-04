#include <stdio.h>
#include <stdlib.h>

/* Compiling on Windows */
#ifdef _WIN32
#include <string.h>

static char buffer[2048];

/* Fake readline function */
char* readline(char* prompt)
{
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char* cpy = malloc(strlen(buffer)+1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy) - 1] = '\0';
    return cpy;
}

/* Fake add_history function */
void add_history(char* unused)
{
}

/* Compiling other OSs */
#else
#include <editline/readline.h>
#endif

/* Declare a buffer for user input of size 2048 */
int main(int argc, char** argv)
{
	/* Print Version and Exit Information */
    puts("QLisp Version 0.0.0.0.1");
    puts("Press Ctrl+c to Exit\n");

    /* In a never ending loop */
    while (1)
    {
        /* Output our prompt */
        char* input = readline("QLisp> ");
        /* Add input to history */
        add_history(input);
        /* Echo input back to user */
        printf("You have just input %s\n", input);
        /* Free retrieved input */
        free(input);
     }

    return 0;
}

