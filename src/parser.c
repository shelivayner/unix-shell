
#include "parser.h"
#include <stdlib.h>
#include <stddef.h>

struct Command *parse(char **tokens)
{
    struct Command *cmd = malloc(sizeof(struct Command));
    if (cmd == NULL) {
        return NULL;
    }
    cmd->args = tokens;
    return cmd;
}
