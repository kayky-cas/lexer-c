#include <stddef.h>
#include <stdio.h>

typedef enum {
    TOKEN_END = 0,
} TokenType;

typedef struct {
    const char *buffer;
    size_t len;
    TokenType type;
} Token;

typedef struct {
    const char* buffer;
    size_t len;
    size_t cursor;
} Lexer;

Lexer new_lexer(const char* buffer, size_t len) {
    Lexer lexer = {
        .buffer = buffer,
        .len = len,
        .cursor = 0
    };

    return lexer;
}

int main(void) {
    const char *input = "#include <stdio.h>";
    return 0;
}
