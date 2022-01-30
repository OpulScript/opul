#include <stdio.h>

#include "token.h"

void print_tokens(token_t *tokens){
    printf("=== Tokens ===\n");
    for(int i = 0; tokens[i].type != TOKEN_TYPE_NONE; i++){
        switch(tokens[i].type){
            case TOKEN_TYPE_NONE:       printf("TOKEN_TYPE_NONE       "); break;
            case TOKEN_TYPE_EOF:        printf("TOKEN_TYPE_EOF        "); break;
            case TOKEN_TYPE_PLUS:       printf("TOKEN_TYPE_PLUS       "); break;
            case TOKEN_TYPE_MINUS:      printf("TOKEN_TYPE_MINUS      "); break;
            case TOKEN_TYPE_MUL:        printf("TOKEN_TYPE_MUL        "); break;
            case TOKEN_TYPE_DIV:        printf("TOKEN_TYPE_DIV        "); break;
            case TOKEN_TYPE_LPAREN:     printf("TOKEN_TYPE_LPAREN     "); break;
            case TOKEN_TYPE_RPAREN:     printf("TOKEN_TYPE_RPAREN     "); break;
            case TOKEN_TYPE_LBRACE:     printf("TOKEN_TYPE_LBRACE     "); break;
            case TOKEN_TYPE_RBRACE:     printf("TOKEN_TYPE_RBRACE     "); break;
            case TOKEN_TYPE_EQ:         printf("TOKEN_TYPE_EQ         "); break;
            case TOKEN_TYPE_STR_LIT:    printf("TOKEN_TYPE_STR_LIT    "); break;
            case TOKEN_TYPE_INT_LIT:    printf("TOKEN_TYPE_INT_LIT    "); break;
            case TOKEN_TYPE_CHAR_LIT:   printf("TOKEN_TYPE_CHAR_LIT   "); break;
            case TOKEN_TYPE_FLOAT_LIT:  printf("TOKEN_TYPE_FLOAT_LIT  "); break;
            case TOKEN_TYPE_SECO:       printf("TOKEN_TYPE_SECO       "); break;
            case TOKEN_TYPE_PERIOD:     printf("TOKEN_TYPE_PERIOD     "); break;
            case TOKEN_TYPE_USE_STD:    printf("TOKEN_TYPE_USE_STD    "); break;
            case TOKEN_TYPE_USE:        printf("TOKEN_TYPE_USE        "); break;
            case TOKEN_TYPE_IDENTIFIER: printf("TOKEN_TYPE_IDENTIFIER "); break;
            case TOKEN_TYPE_KEYWORD:    printf("TOKEN_TYPE_KEYWORD    "); break;

            default:
                printf("Unknown token (%i)    ", tokens[i].type);
                break;
        }

        switch(tokens[i].valueType){
            case VALUE_TYPE_NONE: break;
            case VALUE_TYPE_STRING:
                printf("%s", (char *)tokens[i].value);
                break;
            case VALUE_TYPE_INT:
                printf("%i", *((int *)tokens[i].value));
                break;
        }

        printf("\n");
    }
}

void print_code(char *code){
    printf("=== Code ===\n%s\n", code);
}