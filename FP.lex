%{
#include "stdlib.h"
int yylineno;
%}


%%

"\n"					yylineno++;
[ \t]*					;
(\{|\})					;
return					printf(" TOKEN KEYWORD %s \n",  yytext );
print					printf(" TOKEN PREDEFINED FUNCTION %s \n",  yytext );
loop					printf(" TOKEN KEYWORD %s \n",  yytext );
	

[\-]?[ ]*((0)|([1-9][0-9]*))+\.([0-9])+([E](\+|\-)[0-9]+)?		printf(" TOKEN FLOAT %s \n",  yytext );
[\-]?[ ]*([0-9]+)		{       int num = atoi(yytext);
                                if(num>10000000)
                                        printf("INVALID INTEGER %s, GREATER THAN 1000000 \n",yytext);
                                else
                                        printf(" TOKEN INTEGER %s \n",  yytext );
                        }


"<"             		printf(" TOKEN COMPARISON-OPERATOR %s \n",  yytext );
">"             		printf(" TOKEN COMPARISON-OPERATOR %s \n",  yytext );
"="             		printf(" TOKEN ASSIGNMENT %s \n",  yytext );

"+"             		printf(" TOKEN PREDEFINED FUNCTION %s \n",  yytext );
"*"             		printf(" TOKEN PREDEFINED FUNCTION %s \n",  yytext );
[a-z]+          		printf(" TOKEN IDENTIFIER %s \n",  yytext );

.              			printf(" INVALID CHARACTER  %s IN LINE %d \n",yytext,  yylineno);

%%

int yywrap(void){
	
	return 1;
}


int main(void){
	printf("TOKENS are as follows : \n");
    yylex();
    return 0;
}


