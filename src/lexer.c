#include "include/lexer.h"
#include <stdlib.h>
#include <string.h>

lexer_t* init_lexer(char* content){
	lexer_t* lexer = calloc(1, sizeof(lexer_t));
	lexer -> content = content;
	lexer -> i = 0;
	lexer -> c = content[lexer -> i]; /* Basically 0, want to know more
					     about non-zero cases*/
	return lexer;
}


/* This  function takes us to the next character*/
void lexer_advance(lexer_t* lexer){
	if(lexer -> c != '\0' && lexer -> i < strlen(lexer -> content)){
		(lexer -> i)++;
		lexer -> c = lexer -> content[lexer -> i];
	}
}

void lexer_skip_whitespacec(lexer_t* lexer){
	while(lexer -> c = '\x20' || lexer -> c == '\n')
		lexer_advance(lexer);
	
}
void lexer_skip_singleline_comment(lexer_t* lexer) {
	while(lexer -> c != '\n')
		lexer_advance(lexer);
}
/* void lexer_skip_multiline_comment(lexer_t* lexer) { */
/* 	while(lexer -> c != '#' && if()) */
/* } */

/* Helper function to return the token after we jump to next token */
token_t* lexer_advance_with_token(lexer_t* lexer, token_t* token){
	lexer_advance(lexer);
	return token;
}

token_t* lexer_get_next_token(lexer_t* lexer){
	while(lexer -> c != '\0' && lexer -> i < strlen(lexer -> content)){
		if(lexer -> c == '\x20' || lexer -> c == '\n')
			lexer_advance(lexer);
		if(lexer -> c == '"')
			return lexer_collect_string(lexer);
		if(isalnum(lexer -> c))
			return lexer_collect_id(lexer);
		if(lexer -> c == '#')
			lexer_skip_singleline_comment(lexer);
		switch(lexer -> c){
		case '=':
			return lexer_advance_with_token(lexer,
							init_token(TOKEN_EQUALS,
								   lexer_get_current_char_as_string(lexer)));
			break;
		case ';':
			return lexer_advance_with_token(lexer,
							init_token(TOKEN_SEMI,
								   lexer_get_current_char_as_string(lexer)));
			break;
		case '(':
			return lexer_advance_with_token(lexer,
							init_token(TOKEN_LPAREN,
								   lexer_get_current_char_as_string(lexer)));
			break;
		case ')':
			return lexer_advance_with_token(lexer,
							init_token(TOKEN_RPAREN,
								   lexer_get_current_char_as_string(lexer)));
			break;
		case ',':
			return lexer_advance_with_token(lexer,
							init_token(TOKEN_COMMA,
								   lexer_get_current_char_as_string(lexer)));
			break;
		default:
			break;
		}
		
	}
	return (void*)0;
}

token_t* lexer_collect_string(lexer_t* lexer){
	char* value = calloc(1, sizeof(char));
	value[0] = '\0';
	lexer_advance(lexer); 	/* With this we skip the initial quote and get
				   to the string*/

	/* Append current character to value variable */
	while(lexer -> c != '"'){
		char* s = lexer_get_current_char_as_string(lexer);
		value = realloc(value,
				(strlen(value) + strlen(s) + 1) * sizeof(char));
		strcat(value, s);
		lexer_advance(lexer);
	}
	lexer_advance(lexer);
	return init_token(TOKEN_STRINGS, value);
}

token_t* lexer_collect_id(lexer_t* lexer){
	char* value = calloc(1, sizeof(char));
	value[0] = '\0';
	/* No need to advance since ids don't have quotes */

	
	/* Append current character to value variable */
	while(isalnum(lexer -> c)){
		char* s = lexer_get_current_char_as_string(lexer);
		value = realloc(value,
				(strlen(value) + strlen(s) + 1) * sizeof(char));
		strcat(value, s);
		lexer_advance(lexer);
	}
	lexer_advance(lexer);
	return init_token(TOKEN_ID, value);
}

char* lexer_get_current_char_as_string(lexer_t* lexer){
	char* str = calloc(2, sizeof(char));
	str[0] = lexer -> c;
	str[1] = '\0';
	return str;
}
