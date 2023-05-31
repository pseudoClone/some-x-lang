#ifndef LEXER_H
#define LEXER_H
#include <ctype.h>
#include "token.h"


typedef struct LEXER_STRUCT {
	char c;			/* Current character*/
	unsigned int i; 	/* Like line number */
	char* content; 		/* The actual thing that is going to be parsed */
}lexer_t;

lexer_t* init_lexer(char* content); /* Initializes the lexer */

void lexer_advance(lexer_t* lexer); /* Takes the current state of the lexer as
				     the argument*/

void lexer_skip_whitespacec(lexer_t* lexer);

token_t* lexer_get_next_token(lexer_t* lexer); /* VVI func,
						  Call this to get to the
						  next token*/
token_t* lexer_collect_string(lexer_t* lexer); /* Defines how to parse
						strings*/
char* lexer_get_current_char_as_string(lexer_t* lexer); /* Get the current char
							 as an array*/

token_t* lexer_advance_with_token(lexer_t* lexer, token_t* token);

token_t* lexer_collect_id(lexer_t* lexer);
#endif /* lexer_h */
