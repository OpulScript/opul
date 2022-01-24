#include <stdio.h>

#include "token.h"

int tokenize(char *code, token_t *tokens){

    uint64_t token_count = 0;

    while(*code){
        if(*code == '+'){
            token_t token;
            token_init(&token, TOKEN_TYPE_PLUS);
            tokens[token_count] = token;
            token_count++;
            code++;
        }
        else{
            printf("\x1b[31m\x1b[1mError\x1b[0m: illegal character \'%c\'\n", *code);
            return 1;
        }
    }

    // add EOF token
    token_t eof_token;
    token_init(&eof_token, TOKEN_TYPE_EOF);
    tokens[token_count] = eof_token;
    token_count++;

    // add terminator token
    token_t none_token;
    token_init(&none_token, TOKEN_TYPE_NONE);
    tokens[token_count] = none_token;
    token_count++;

    return 0;
}