#include "include/main.h"
#include "include/lexer.h"
int main(int argc, char *argv[])
{
	lexer_t* lexer = init_lexer(
		"john_name string = \"John MacAfee\";\n"
		"john_age int = 29;\n"
		"print(\"The name is:\", prince);"
		"print(\"The age is: @i\", john_age); #This is single line comment!\n"
		);
	token_t* token = (void*)0;
	while((token = lexer_get_next_token(lexer)) != (void*)0) /* (void*)0
								  means NULL*/
		printf("TOKEN(%d, %s)\n" , token -> type, token -> value);
	return 0;
}
