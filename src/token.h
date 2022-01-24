#include <stdint.h>

#define TOKEN_TYPE_NONE (uint8_t) 0
#define TOKEN_TYPE_EOF (uint8_t) 1
#define TOKEN_TYPE_PLUS (uint8_t) 2

typedef struct {
    uint8_t type;
} token_t;

void token_init(token_t *token, uint8_t type);