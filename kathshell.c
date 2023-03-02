/*
 * A basic UNIX shell implementation.
 */
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>

#define PROMPT  "kathsh $ "
#define GOODBYE "Goodbye. Thanks for using kathsh."

int main(int argc, char *argv[]) {
    char             *command = NULL;
    size_t    MAX_COMMAND_LENGTH = 100;
    size_t          num_chars_read = 0;

    /* Allocate memory for command buffer */
    command = (char *) malloc(MAX_COMMAND_LENGTH * sizeof(char));
    if (command == NULL) {
        perror("kathshell (malloc failed)");
        exit (EXIT_FAILURE);
    }

    while(1) {
        /* Print the prompt */
        printf("%s", PROMPT);

        /* Read the command from stdin */
        num_chars_read = getline(&command, &MAX_COMMAND_LENGTH, stdin);

        if (num_chars_read == -1) {
            /* EOF like Cltr + D */
            printf("%s\n", GOODBYE);
            return 0;
        }

        if (num_chars_read == 0) {
            /* Empty command, nothing to do, flush the stdin and take input again */
            continue;
        }

        /* Null terminate the command */
        command[strlen(command) - 1] = '\0';

        if(strcmp(command, "quit") == 0 ||
           strcmp(command, "quit()") == 0 ||
           strcmp(command, "exit") == 0 ||
           strcmp(command, "exit()") == 0 ||
           strcmp(command, "q") == 0) {
            /* Check for common quit inputs */
            printf("%s\n", GOODBYE);
            return 0;
           }
    }
    return 0;
}
