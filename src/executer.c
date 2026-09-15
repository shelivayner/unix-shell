#include "executer.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void execute_command(struct Command *cmd) {
    if (cmd->args[0] == NULL) {
        return;
    }
    if (strcmp(cmd->args[0], "exit") == 0) {
        exit(0);
    } else if (strcmp(cmd->args[0], "cd") == 0) {
        if (chdir(cmd->args[1]) != 0) {
            perror("Error in changing directory");
        }
        return;
    }
    pid_t pid = fork();
    if (pid < 0) {
        perror("Error in creating process");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        execvp(cmd->args[0], cmd->args);
        perror("No command exists");
        exit(EXIT_FAILURE);
    } else {
        waitpid(pid, NULL, 0);
    }
}