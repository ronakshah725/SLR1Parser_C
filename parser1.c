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

void start_parser(void)
{
    int ntoken;
    
    ntoken = yylex();
    
    while(ntoken!=EOF) {
        
        
        printTokens(ntoken);
        ntoken = yylex();
    }
     printf("$\nThanks!!");
}

int main(int argc, char *argv[] )
{
    if ( argc != 2 ) /* argc should be 2 for correct execution */
    {
        
        printf( "usage: %s filename", argv[0] );
    }
    else
    {
        // We assume argv[1] is a filename to open
        FILE *file = fopen( argv[1], "r" );
        
        /* fopen returns 0, the NULL pointer, on failure */
        if ( file == 0 )
        {
            printf( "Could not open file\n" );
        }
        else
        {
            int x;
            /* read one character at a time from file, stopping at EOF, which
             indicates the end of the file.  Note that the idiom of "assign
             to a variable, check the value" used below works because
             the assignment statement evaluates to the value assigned. */
            while  ( ( x = fgetc( file ) ) != EOF )
            {
                printf( "%c", x );
            }
            fclose( file );
        }
    }

    //readTable();
    
    start_parser();
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
