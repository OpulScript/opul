#include <stdint.h>

#include "token.h"

void token_init(token_t *token, uint8_t type){
    token->type = type;
}