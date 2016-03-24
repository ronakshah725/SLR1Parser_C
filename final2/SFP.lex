%{
#include "stdlib.h"
#include "symbols.h"

%}


%%

"\n"					{yylineno++; return LINE;}
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
<<EOF>>                 {
                            
                            return DOLLAR;
                        }
.              			{
							
							return ERROR;
						}

%%

int yywrap(void){
	
	return 1;
}


