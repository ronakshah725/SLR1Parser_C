#include <stdio.h>
#include <string.h>
#include "symbols.h"

extern int yylex();
extern int yylineno;
extern char* yytext;

#define row 50
#define col 16



void printTokens(int ntoken)
{
    //todo
		  switch (ntoken) {
                  
              case LBRACE:
                  printf("lb ");break;
              case RBRACE:
                  printf("rb ");break;
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


char* getValueFromMatrix(int state, int symbol, char x[row][col]) {
    
    int val = (state-1)*15 + symbol;  //see formula_helper.txt
    
    return x[val];
    
    //printf("(%d,%d)  =  %s  ,val = %d",symbol,state,x[val], val);
}

void read_table(FILE* fp){
    

    char x[row][col];
    char buf[300];
    fp = fopen("sample2.pt","r");
    
    int i = 0;
    size_t n;
    fgets(buf,sizeof(buf),fp);
    
    while(fgets(buf,sizeof(buf),fp))
    {
        char *p = strtok(buf,"\t");
        while( p != NULL)
        {
            n = strlen(p);
            if(i>= row && n> col)
                break;
            strcpy(x[i],p);
            i++;
            p = strtok(NULL,"\t");
        }
    }
    int st, sy; //state and symbol
    st = 6, sy = DOLLAR;
    int val = (st-1)*15 + sy;  //see formula_helper.txt
    char* va = getValueFromMatrix(st, sy, x);
    printf("(%d,%d)  =  %s  ,val = %s",st,sy,x[val], va);
   
}

void start_parser(void)
{
    int ntoken;
    
    ntoken = yylex();
    
    while(ntoken!=EOF) {
        
        
        //printTokens(ntoken);
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
        FILE *file = fopen( argv[1], "r" );
        if ( file == 0 )
        {
            printf( "Could not open file\n" );
        }
        else
        {
            read_table(file);
        }
    }

    
    
    start_parser();
	return 0;
}





