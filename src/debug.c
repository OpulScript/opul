#include <stdio.h>

#include "token.h"

void print_tokens(token_t *tokens){
    printf("=== Tokens ===\n");
    for(int i = 0; tokens[i].type != TOKEN_TYPE_NONE; i++){
        switch(tokens[i].type){
            case TOKEN_TYPE_NONE: printf("TOKEN_TYPE_NONE\n"); break;
            case TOKEN_TYPE_EOF: printf("TOKEN_TYPE_EOF\n"); break;
            case TOKEN_TYPE_PLUS: printf("TOKEN_TYPE_PLUS\n"); break;

            default:
                printf("Unknown token (%i)\n", tokens[i].type);
                break;
        }
    }
}