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
    int pipe_index = -1;
    for (int i = 0; cmd->args[i] != NULL; i++) {
        if (strcmp(cmd->args[i], "|") == 0) {
            pipe_index = i;
            break;
        }
    }

    if (pipe_index != -1) {
        if (pipe_index == 0 || cmd->args[pipe_index + 1] == NULL) {
            fprintf(stderr, "Invalid pipe\n");
            return;
        }

        cmd->args[pipe_index] = NULL;
        char **args2 = &cmd->args[pipe_index + 1];

        int pipefd[2];
        if (pipe(pipefd) == -1) {
            perror("Error creating pipe");
            return;
        }

        pid_t pid1 = fork();
        if (pid1 < 0) {
            perror("Error in creating process");
            return;
        }
        if (pid1 == 0) {
            dup2(pipefd[1], STDOUT_FILENO);
            close(pipefd[0]);
            close(pipefd[1]);
            execvp(cmd->args[0], cmd->args);
            perror("No command exists");
            exit(EXIT_FAILURE);
        }

        pid_t pid2 = fork();
        if (pid2 < 0) {
            perror("Error in creating process");
            return;
        }
        if (pid2 == 0) {
            dup2(pipefd[0], STDIN_FILENO);
            close(pipefd[0]);
            close(pipefd[1]);
            execvp(args2[0], args2);
            perror("No command exists");
            exit(EXIT_FAILURE);
        }

        close(pipefd[0]);
        close(pipefd[1]);
        waitpid(pid1, NULL, 0);
        waitpid(pid2, NULL, 0);
    } else {
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
}