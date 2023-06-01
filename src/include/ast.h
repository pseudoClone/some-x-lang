#ifndef AST_H
#define AST_H
#include <stdlib.h>

typedef struct AST_STRUCT {
	enum{
		AST_FUNC_CALL,
		AST_VAR_DEF,
		AST_VAR, 	/* used in any scope. not definition */
		AST_STR,
		AST_COMPOUND	/* List of AST node, possibly of the
				   source code*/
	}type;

	// For ast_var_def
	char* AST_VAR_DEF_NAME;
	struct AST_STRUCT* AST_VAR_DEF_VALUE;


	//For ast_var
	char* AST_VAR_NAME;



	//For func_call
	char* AST_FUNC_CALL_NAME;
	struct AST_STRUCT** AST_FUNC_CALL_ARGS; /* Pointer to list of
						   pointers */
	size_t AST_FUNC_CALL_ARG_SIZE;


	//For strings
	char* AST_STR_VAL;


	//For compounds
	struct AST_STRUCT** AST_COMPOUND_VAL;
	size_t AST_COMPOUND_SIZE;
}ast_t;


ast_t* init_ast(int type);


#endif /* AST_H */
