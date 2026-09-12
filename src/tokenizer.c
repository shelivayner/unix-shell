#include "tokenizer.h"
#include <string.h>
#include <stdlib.h>


char **tokenize(const char *line)
{
    char *str = strdup(line);
    const char *delimiters = " \t\r\n\v\f";
    char **tokens = malloc(sizeof(char *));
    char *token = strtok(str, delimiters);
    int count = 0;

    while (token != NULL) {
        tokens = realloc(tokens, (count + 2) * sizeof(char *));
        tokens[count] = malloc(strlen(token) + 1);
        strcpy(tokens[count], token);
        count++;
        token = strtok(NULL, delimiters);
    }

    tokens[count] = NULL;
    free(str);
    return tokens;
}

void free_tokens(char **tokens)
{
    if (tokens == NULL) {
        return;
    }
    for (int i = 0; tokens[i] != NULL; i++) {
        free(tokens[i]);
    }
    free(tokens);
}
