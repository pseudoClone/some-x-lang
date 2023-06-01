#include "include/ast.h"

ast_t* init_ast(int type)
{
	ast_t* ast = calloc(1, sizeof(ast_t));
	ast -> type = type;


	// For ast_var_def
	ast -> AST_VAR_DEF_NAME = (void*)0;
	ast -> AST_VAR_DEF_VALUE = (void*)0;


	//For ast_var
	ast -> AST_VAR_NAME = (void*)0;



	//For func_call
	ast -> AST_FUNC_CALL_NAME = (void*)0;
	ast -> AST_FUNC_CALL_ARGS = (void*)0;
	ast -> AST_FUNC_CALL_ARG_SIZE = 0;


	//For strings
	ast -> AST_STR_VAL = 0;


	//For compounds
	ast -> AST_COMPOUND_VAL = (void*)0;
	ast -> AST_COMPOUND_SIZE = 0;
	
	return ast;
}
