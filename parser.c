#include <stdio.h>
#include "symbols.h"

extern int yylex();
extern int yylineno;
extern char* yytext;



int main(void) 
{

	int ntoken, vtoken;

	ntoken = yylex();
	while(ntoken) {


		
		switch (ntoken) {

		case LBRACE:printf(" LBRACE\n");break;

		case RBRACE:printf(" RBRACE\n");break;

		case IDENTIFIER:
			printf("ID : %s\n", yytext);
			break;
		
		case PRINT:
			printf(" PRINT\n");break;
			break;
		case LOOP:
			printf(" LOOP\n");break;
			break;
		case FUNCTION:
			printf("FUNCTION : %s\n", yytext);
			break;
		case ASSIGN:
			printf("ASSIGN \n");
			break;
		case NUMBER:
			printf("NUMBER : %s\n", yytext);
			break;		
		default:
			printf("Syntax error in line %d\n",yylineno);
		}
		ntoken = yylex();
	}
	return 0;
}


  // #define IDENTIFIER 98
  // #define RBRACE 17
  // #define LBRACE 16
  // #define ASSIGN 18
  // #define PLUS 60
  // #define MULT 14
  // #define MINUS 61
  // #define ERROR 1
  // #define FUNCTION 101
  // #define LOOP 102
  // #define PRINT 103
  // #define NUMBER 104

