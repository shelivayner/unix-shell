#ifndef PARSER_H
#define PARSER_H

struct Command {
    char **args;
};

struct Command *parse(char **tokens);

#endif 