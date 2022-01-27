#include <stdio.h>
#include <stdlib.h>

#include "token.h"
#include "util.h"
#include "debug.h"

int tokenize(char *code, token_t *tokens){

    //TODO: Implement number literals

    uint64_t token_count = 0;

    while(*code){
        if(*code == ' ' || *code == '\n' || *code == '\t' || *code == '\r'){
            // do nothing, just skip character
            code++;
        }
        else if(*code == '/' && *(code+1) == '/'){
            while(*code != '\n' && *code != '\0'){
                code++;
            }
        }
        else if(*code == '/' && *(code+1) == '*'){ //FIXME: Detect unterminated comment
            while(*code != '*'){
                code++;
            }
        }
        else if(isNumeric(*code)){ // TODO: Avoid double-recursion
            char *start = code; // save literal start address
            uint64_t length = 0; // track length

            while(isNumeric(*code)){ // count digits
                length++;
                code++;
            }

            char *str = malloc(sizeof(char *)*(length+1)); // allocate string
            code = start; // reset pointer

            while(isNumeric(*code)){ // while in literal
                str[code - start] = *code;
                code++;
            }

            str[length] = '\0'; // null terminator

            int num = atoi(str); // convert string to integer
            
            // add token
            token_t token;
            token_init(&token, TOKEN_TYPE_INT_LIT, VALUE_TYPE_INT, &num);
            tokens[token_count] = token;
            token_count++;
            code++;
        }
        else if(*code == '\"'){ // TODO: Optimize this to avoid double-recursion for strings
            code++; // skip first quote

            char *str_start_addr = code;
            uint64_t str_length = 0;

            // scan length
            // FIXME: Handle un-closed strings
            while(*code != '\"'){ // while in string
                str_length++; // add one to string length
                code++; // next character
            }

            char *str = malloc(sizeof(char *)*str_length); // TODO: Handle errors in allocation
            code = str_start_addr; // Now go back to the beggining to save the literal

            // TODO: Try to implement with memcpy()
            // FIXME: Handle un-closed strings
            while(*code != '\"'){ // while in string
                str[code - str_start_addr] = *code;
                code++; // next character
            }

            str[str_length] = '\0'; // add null-terminator

            token_t token;
            token_init(&token, TOKEN_TYPE_STR_LIT, VALUE_TYPE_STRING, str);
            tokens[token_count] = token;
            token_count++;
            code++;
        }
        else if(*code == '+'){
            token_t token;
            token_init(&token, TOKEN_TYPE_PLUS, 0, (void *)NULL);
            tokens[token_count] = token;
            token_count++;
            code++;
        }
        else if(*code == '-'){
            token_t token;
            token_init(&token, TOKEN_TYPE_MINUS, 0, (void *)NULL);
            tokens[token_count] = token;
            token_count++;
            code++;
        }
        else if(*code == '*'){
            token_t token;
            token_init(&token, TOKEN_TYPE_MUL, 0, (void *)NULL);
            tokens[token_count] = token;
            token_count++;
            code++;
        }
        else if(*code == '/'){
            token_t token;
            token_init(&token, TOKEN_TYPE_DIV, 0, (void *)NULL);
            tokens[token_count] = token;
            token_count++;
            code++;
        }
        else if(*code == '('){
            token_t token;
            token_init(&token, TOKEN_TYPE_LPAREN, 0, (void *)NULL);
            tokens[token_count] = token;
            token_count++;
            code++;
        }
        else if(*code == ')'){
            token_t token;
            token_init(&token, TOKEN_TYPE_RPAREN, 0, (void *)NULL);
            tokens[token_count] = token;
            token_count++;
            code++;
        }
        else if(*code == '{'){
            token_t token;
            token_init(&token, TOKEN_TYPE_LBRACE, 0, (void *)NULL);
            tokens[token_count] = token;
            token_count++;
            code++;
        }
        else if(*code == '}'){
            token_t token;
            token_init(&token, TOKEN_TYPE_RBRACE, 0, (void *)NULL);
            tokens[token_count] = token;
            token_count++;
            code++;
        }
        else if(*code == '='){
            token_t token;
            token_init(&token, TOKEN_TYPE_EQ, 0, (void *)NULL);
            tokens[token_count] = token;
            token_count++;
            code++;
        }
        else if(*code == ';'){
            token_t token;
            token_init(&token, TOKEN_TYPE_SECO, 0, (void *)NULL);
            tokens[token_count] = token;
            token_count++;
            code++;
        }
        else if(*code == '.'){
            token_t token;
            token_init(&token, TOKEN_TYPE_PERIOD, 0, (void *)NULL);
            tokens[token_count] = token;
            token_count++;
            code++;
        }
        // TODO: Optimize this
        else if(*code == '@' && *(code+1) == 'u' && *(code+2) == 's' && *(code+3) == 'e' && *(code+4) == ' '){
            code += 4;

            code++; //TODO: Jump all whitespaces

            if(*code == '<'){ // STD lib
                code++; // skip '<'

                char *str_start_addr = code;
                uint64_t str_length = 0;

                // scan length
                // FIXME: Handle un-closed <>
                while(*code != '>'){
                    str_length++;
                    code++;
                }

                char *str = malloc(sizeof(char *)*str_length); // TODO: Handle errors in allocation
                code = str_start_addr; // Now go back to the beggining to save the literal

                // TODO: Try to implement with memcpy()
                // FIXME: Handle un-closed <>
                while(*code != '>'){ // while in string
                    str[code - str_start_addr] = *code;
                    code++; // next character
                }

                str[str_length] = '\0'; // add null-terminator

                token_t token;
                token_init(&token, TOKEN_TYPE_USE_STD, VALUE_TYPE_STRING, str);
                tokens[token_count] = token;
                token_count++;
                code++;
            }
            else if(*code == '\"'){
                code++; // skip first quote

                char *str_start_addr = code;
                uint64_t str_length = 0;

                // scan length
                // FIXME: Handle un-closed strings
                while(*code != '\"'){
                    str_length++;
                    code++;
                }

                char *str = malloc(sizeof(char *)*str_length); // TODO: Handle errors in allocation
                code = str_start_addr; // Now go back to the beggining to save the literal

                // TODO: Try to implement with memcpy()
                // FIXME: Handle un-closed strings
                while(*code != '\"'){ // while in string
                    str[code - str_start_addr] = *code;
                    code++; // next character
                }

                str[str_length] = '\0'; // add null-terminator

                token_t token;
                token_init(&token, TOKEN_TYPE_USE, VALUE_TYPE_STRING, str);
                tokens[token_count] = token;
                token_count++;
                code++;
            }
            else{
                printf("\x1b[31m\x1b[1mError\x1b[0m: expected '<' or '\"', but found '%c'\n", *code);
                return 1;
            }
        }
        else if(isAlpha(*code) || *code == '_'){
            // TODO: Avoid double-recursion

            uint64_t length = 0;
            char *start = code;
            
            while(isAlphaNumeric(*code) || *code == '_'){
                code++;
                length++;
            }

            code = start;
            char *str = malloc(sizeof(char *)*length);
            
            while(isAlphaNumeric(*code) || *code == '_'){
                str[code-start] = *code;
                code++;
            }

            //add null-terminator
            str[length] = '\0';

            // TODO: Check if keyword

            token_t token;
            token_init(&token, TOKEN_TYPE_IDENTIFIER, VALUE_TYPE_STRING, str);
            tokens[token_count] = token;
            token_count++;
        }
        else{
            printf("\x1b[31m\x1b[1mError\x1b[0m: illegal character \'%c\'\n", *code);
            return 1;
        }
    }

    // add EOF token
    token_t eof_token;
    token_init(&eof_token, TOKEN_TYPE_EOF, 0, (void *)NULL);
    tokens[token_count] = eof_token;
    token_count++;

    // add terminator token
    token_t none_token;
    token_init(&none_token, TOKEN_TYPE_NONE, 0, (void *)NULL);
    tokens[token_count] = none_token;
    token_count++;

    return 0;
}
