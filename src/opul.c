#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "opul.h"
#include "tokenizer.h"
#include "debug.h"

int opul_compile(char *code){
#ifdef DEBUG
    print_code(code);
#endif

    // Tokenizer
    // FIXME: Not very memory-efficient
    // TODO: Move into tokenizer.c
    token_t *tokens = malloc(sizeof(token_t)*(strlen(code)+2));

    if(tokenize(code, tokens)){
        return 1;
    }

#ifdef DEBUG
    print_tokens(tokens);
#endif

    // TODO: Parse

    // TODO: Optimize

    // TODO: Compile
    
    return OPUL_COMP_RES_SUCCESS;
}