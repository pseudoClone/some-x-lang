#ifndef PARSER_H
#define PARSER_H
#include "lexer.h"
#include "ast.h"


typedef struct PARSER_STRUCT{
	lexer_t* lexer;
	token_t* cur_token;
}parser_t;


parser_t* init_parser(lexer_t* lexer);


/* If the expected token is not passed to this function, it dies
 else, accept the token and move to nexer token*/
void eat_parser(parser_t* parser, int tok_type);

/* Returns the whole AST of the source code. VVI func */
ast_t* parser_parse(parser_t* parser);

ast_t* parser_parse_statement(parser_t* parser);

ast_t* parser_parse_statements(parser_t* parser);

ast_t* parser_parse_term(parser_t* parser); /* Parses addition statments */

ast_t* parser_parse_factor(parser_t* parser); /* Parses muliplicative
						 statements */

ast_t* parser_parse_expr(parser_t* parser); /* Combination of factor and
					     terms functions*/

ast_t* parser_parse_func_call(parser_t* parser);

ast_t* parser_parse_var(parser_t* parser);

ast_t* parser_parse_string(parser_t* parser);

#endif /* PARSER_H */
