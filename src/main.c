#include "tokenizer.h"
#include "parser.h"
#include "executer.h"
#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 256
int main(void)
{
    char input[MAX_INPUT_LENGTH];

    printf("Enter a command: ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 0;
    }
    input[strcspn(input, "\n")] = '\0';
    char **tokens = tokenize(input);

    struct Command *cmd = parse(tokens);
    execute_command(cmd);

    // printf("[");
    // for (int i = 0; tokens[i] != NULL; i++) {
    //     printf("\"%s\"", tokens[i]);
    //     if (tokens[i+1] != NULL) {
    //         printf(", ");
    //     }
    // }
    // printf("]\n");
    // fflush(stdout);
    free_tokens(tokens);
    return 0;
}

