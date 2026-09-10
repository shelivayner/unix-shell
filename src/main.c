#include "tokenizer.h"
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

    for (int i = 0; tokens[i] != NULL; i++) {
        printf("%s\n", tokens[i]);
        fflush(stdout);
    }
    free_tokens(tokens);
    return 0;
}

