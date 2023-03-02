/*
 * A basic UNIX shell implementation.
 */
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

#define PROMPT      "kathsh $ "
#define GOODBYE     "Goodbye. Thanks for using kathsh."
#define MAX_ARGS    10

void sig_handler(int sig) {
    write(STDOUT_FILENO, "\n", 1);
    write(STDOUT_FILENO, GOODBYE, strlen(GOODBYE));
    write(STDOUT_FILENO, "\n", 1);
    _exit(EXIT_SUCCESS);
}

void exec_command(char *command) {
    int     index = 0;
    char    *token = NULL;
    char    *args_list[MAX_ARGS];

    token = strtok(command, " ");
    while (token != NULL) {
        args_list[index++] = token;
        token = strtok(NULL, " ");
    }
    args_list[index] = NULL;

    if(execvp(args_list[0], args_list) == -1) {
        perror("kathsh (execve failed)");
    }
    fflush(stdout);

}

int main(int argc, char *argv[]) {
    char            *command = NULL;
    size_t          MAX_COMMAND_LENGTH = 100;
    size_t          num_chars_read = 0;
    pid_t           pid;
    int             status = 0;

    /* Allocate memory for command buffer */
    command = (char *) malloc(MAX_COMMAND_LENGTH * sizeof(char));
    if (command == NULL) {
        perror("kathsh (malloc failed)");
        exit (EXIT_FAILURE);
    }

    /* Register for SIGINT */
    signal(SIGINT, sig_handler);

    while(1) {
        /* Print the prompt */
        printf("%s", PROMPT);

        /* Read the command from stdin */
        num_chars_read = getline(&command, &MAX_COMMAND_LENGTH, stdin);

        if (num_chars_read == -1) {
            /* EOF like Cltr + D */
            printf("\n%s\n", GOODBYE);
            exit (EXIT_SUCCESS);
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

        pid = fork();
        if (pid == -1) {
            perror("kathsh (fork failure)");
            continue;
        }

        if(pid) {
            /* parent process. just wait on the child. */
            while(wait(&status) > 0);
        } else {
            /* Child process. Execute the command.*/
            exec_command(command);
        }
    }
    return 0;
}
