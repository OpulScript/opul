#pragma once

#include <stdint.h>

enum token_type{
    TOKEN_TYPE_NONE,
    TOKEN_TYPE_EOF,
    TOKEN_TYPE_PLUS,
    TOKEN_TYPE_MINUS,
    TOKEN_TYPE_MUL,
    TOKEN_TYPE_DIV,
    TOKEN_TYPE_LPAREN,
    TOKEN_TYPE_RPAREN,
    TOKEN_TYPE_LBRACE,
    TOKEN_TYPE_RBRACE,
    TOKEN_TYPE_EQ,
    TOKEN_TYPE_STR_LIT,
    TOKEN_TYPE_INT_LIT,
    TOKEN_TYPE_CHAR_LIT,
    TOKEN_TYPE_FLOAT_LIT,
    TOKEN_TYPE_SECO,
    TOKEN_TYPE_PERIOD,
    TOKEN_TYPE_USE_STD,
    TOKEN_TYPE_USE,
    TOKEN_TYPE_IDENTIFIER,
    TOKEN_TYPE_KEYWORD,
};

#define VALUE_TYPE_NONE (uint8_t) 0
#define VALUE_TYPE_STRING (uint8_t) 1

typedef struct {
    uint8_t type;
    uint8_t valueType;
    void *value;
} token_t;

void token_init(token_t *token, uint8_t type, uint8_t valueType, void *value);