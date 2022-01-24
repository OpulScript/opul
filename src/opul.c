#include <stdio.h>
#include <stdlib.h>

#include "opul.h"
#include "tokenizer.h"

int opul_compile(char *code){
    token_t *tokens = malloc(sizeof(token_t)*5);
    if(tokenize(code, tokens)){
        return 1;
    }

    for(int i = 0; tokens[i].type; i++){
        printf("%i\n", tokens[i].type);
    }

    // TODO: Parse

    // TODO: Optimize

    // TODO: Compile
    
    return OPUL_COMP_RES_SUCCESS;
}