#include "tokenizer.h"
#include <assert.h>
#include <stdio.h>
#include <string.h>


void test_basic_tokenize(void)
{
    char **tokens = tokenize("ls -la /tmp");
    assert(strcmp(tokens[0], "ls") == 0);
    assert(strcmp(tokens[1], "-la") == 0);
    assert(strcmp(tokens[2], "/tmp") == 0);
    assert(tokens[3] == NULL);
    free_tokens(tokens);
    printf("basic tokenize worked!\n");
}

void test_empty_line(void)
{
    char **tokens = tokenize("");
    assert(tokens[0] == NULL);
    free_tokens(tokens);
    printf("empty line worked!\n");
}

void test_leading_trailing_spaces(void)
{
    char **tokens = tokenize("  ls -la /tmp  ");
    assert(strcmp(tokens[0], "ls") == 0);
    assert(strcmp(tokens[1], "-la") == 0);
    assert(strcmp(tokens[2], "/tmp") == 0);
    assert(tokens[3] == NULL);
    free_tokens(tokens);
    printf("leading and trailing spaces worked!\n");
}

int main(void) 
{
    test_basic_tokenize();
    test_empty_line();
    test_leading_trailing_spaces();
    return 0;
}