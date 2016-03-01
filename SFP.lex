%{
#include "stdlib.h"
#include "symbols.h"

%}


%%

"\n"					yylineno++;
[ \t]*					;
"{"                             return LBRACE;
"}"                             return RBRACE;
print					        return PRINT;
loop					        return LOOP;

[\-]?[ ]*((0)|([1-9][0-9]*))+\.([0-9])+([E](\+|\-)[0-9]+)?		return NUMBER;
[\-]?[ ]*([0-9]+)		        return NUMBER;

"="             		return ASSIGN;

"+"             		return FUNCTION;
"*"             		return FUNCTION;
[a-z]+          		return IDENTIFIER;
<<EOF>>                 return EOF;
.              			printf(" INVALID CHARACTER  %s IN LINE %d \n",yytext,  yylineno);

%%

int yywrap(void){
	
	return 1;
}


