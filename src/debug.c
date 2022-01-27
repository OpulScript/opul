#include <stdio.h>

#include "token.h"

void print_tokens(token_t *tokens){
    printf("=== Tokens ===\n");
    for(int i = 0; tokens[i].type != TOKEN_TYPE_NONE; i++){
        switch(tokens[i].type){ //TODO: Add all token types
            case TOKEN_TYPE_NONE:       printf("TOKEN_TYPE_NONE       "); break;
            case TOKEN_TYPE_EOF:        printf("TOKEN_TYPE_EOF        "); break;
            case TOKEN_TYPE_PLUS:       printf("TOKEN_TYPE_PLUS       "); break;
            case TOKEN_TYPE_MINUS:      printf("TOKEN_TYPE_MINUS      "); break;
            case TOKEN_TYPE_MUL:        printf("TOKEN_TYPE_MUL        "); break;
            case TOKEN_TYPE_DIV:        printf("TOKEN_TYPE_DIV        "); break;
            case TOKEN_TYPE_STR_LIT:    printf("TOKEN_TYPE_STR_LIT    "); break;

            default:
                printf("Unknown token (%i)    ", tokens[i].type);
                break;
        }

        switch(tokens[i].valueType){
            case VALUE_TYPE_NONE: break;
            case VALUE_TYPE_STRING:
                printf("%s", (char *)tokens[i].value);
                break;
        }

        printf("\n");
    }
}

void print_code(char *code){
    printf("=== Code ===\n%s\n", code);
}