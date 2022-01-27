#include <stdint.h>

#include "token.h"



void token_init(token_t *token, uint8_t type, uint8_t valueType, void *value){
    token->type = type;
    token->valueType = valueType;
    token->value = value;
}