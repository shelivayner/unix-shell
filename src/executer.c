#include "executer.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

void execute_command(struct Command *cmd) {
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