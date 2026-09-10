#ifndef TOKENIZER_H
#define TOKENIZER_H

char **tokenize(const char *line);

void free_tokens(char **tokens);

#endif 
