%{
#include "stdlib.h"
#include "symbols.h"
int yylineno;
%}


%%

"\n"					yylineno++;
[ \t]*					;
"{"                             printf(" LBRACE");
"}"                             printf(" RBRACE");
print					        printf(" PRINT");
loop					        printf(" LOOP");

[\-]?[ ]*((0)|([1-9][0-9]*))+\.([0-9])+([E](\+|\-)[0-9]+)?		printf(" NUMBER");
[\-]?[ ]*([0-9]+)		        printf(" NUMBER");

"="             		printf(" ASSIGN");

"+"             		printf(" FUNCTION");
"*"             		printf(" FUNCTION");
[a-z]+          		printf(" IDENTIFIER");

.              			printf(" INVALID CHARACTER  %s IN LINE %d \n",yytext,  yylineno);

%%

int yywrap(void){
	
	return 1;
}


