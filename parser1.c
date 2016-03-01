#include <stdio.h>
#include "symbols.h"

extern int yylex();
extern int yylineno;
extern char* yytext;



void printTokens(int ntoken)
{
    //todo
		  switch (ntoken) {
                  
              case LBRACE:printf("lb ");break;
                  
              case RBRACE:printf("rb ");break;
                  
              case IDENTIFIER:
                  printf("x ");
                  break;
                  
              case PRINT:
                  printf("p ");break;
                  break;
              case LOOP:
                  printf("l ");break;
                  break;
              case FUNCTION:
                  printf("f ");
                  break;
              case ASSIGN:
                  
                  printf("= ");
                  break;
                  
              case NUMBER:
                  printf("n ");
                  break;
              default:
                  printf("Syntax error in line %d\n",yylineno);
          }
}

int main(void)
{

	int ntoken, vtoken;

	ntoken = yylex();
	while(ntoken) {


        printTokens(ntoken);
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
