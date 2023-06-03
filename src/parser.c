#include "include/parser.h"


parser_t* init_parser(lexer_t* lexer){
	parser_t* parser = calloc(1, sizeof(parser_t));
	parser -> lexer = lexer;
	parser -> cur_token = lexer_get_next_token(lexer);
	return parser;
}

void eat_parser(parser_t* parser, int tok_type){
	if(parser -> cur_token -> type == tok_type){
		parser -> cur_token = lexer_get_next_token(parser -> lexer);
	}
	else{
		printf("Unexpected token '%s', with type %d" ,
		       parser -> cur_token -> value,
		       parser -> cur_token -> type);
		exit(0);
	}
}


ast_t* parser_parse(parser_t* parser){
	return parser_parse_statements();
}

ast_t* parser_parse_statement(parser_t* parser){
	
}

ast_t* parser_parse_statements(parser_t* parser){
	
}

ast_t* parser_parse_term(parser_t* parser){
	
}

ast_t* parser_parse_factor(parser_t* parser){
	
}

ast_t* parser_parse_expr(parser_t* parser){
	
}

ast_t* parser_parse_func_call(parser_t* parser){
	
}

ast_t* parser_parse_var(parser_t* parser){
	
}

ast_t* parser_parse_string(parser_t* parser){
	
}
