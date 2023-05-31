#ifndef TOKEN_H
#define TOKEN_H
#include <stdlib.h>
typedef struct TOKEN_STRUCT {
	enum{
		TOKEN_ID,
		TOKEN_EQUALS,
		TOKEN_STRINGS,
		TOKEN_SEMI,
		TOKEN_LPAREN,
		TOKEN_RPAREN,
		TOKEN_COMMA,
		TOKEN_PLUS,
		TOKEN_MINUS,
		TOKEN_MUL,
		TOKEN_DIV,
		TOKEN_MODULO
	}type;
	
	char* value;
}token_t;

token_t* init_token(int type, char* value);

#endif /* TOKEN_H */
