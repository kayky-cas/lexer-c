#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define TODO(name) \
    do { \
        fprintf(stderr, "\"%s\" isn't ready to use.\n", name); \
        exit(1); \
    } while(0); \

bool is_aplha(char c) {
    return (c >= 'a' && c <= 'z') ||
        (c >= 'A' && c <= 'Z') ||
        (c >= '0' && c <= '9');
}

typedef enum {
    TOKEN_END = 0,
    TOKEN_PREPRO,
} TokenType;

const char *token_type_to_string(TokenType type) {

    switch (type) {
        case TOKEN_END:
            return "end of the token";
        case TOKEN_PREPRO:
            return "pre-process token";
    }
}

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

#define END(lexer) lexer->cursor <= lexer->len
#define CURSOR(lexer) lexer->buffer[lexer->cursor]

Token next_token(Lexer *lexer) {
    Token token = {
        .type = TOKEN_END
    };

    if (lexer->cursor >= lexer->len) {
        token.len = 1;
        token.buffer = &CURSOR(lexer);
    }

    else if (CURSOR(lexer) == '#') {
        token.type = TOKEN_PREPRO;
        token.buffer = &CURSOR(lexer);
        token.len = 1;

        lexer->cursor += 1;

        while (is_aplha(CURSOR(lexer)) && END(lexer)) {
            token.len += 1;
            lexer->cursor += 1;
        }
    } else if (CURSOR(lexer) == '<') {
    } else if (CURSOR(lexer) == '>') {
    }


    return token;
}

int main(void) {
    const char *input = "#include <stdio.h>";

    Lexer lexer = new_lexer(input, strlen(input));
    Token token = next_token(&lexer);

    while (token.type != TOKEN_END) {
        printf("%.*s: %s\n", (int) token.len, token.buffer, token_type_to_string(token.type));
        token = next_token(&lexer);
    }

    return 0;
}
