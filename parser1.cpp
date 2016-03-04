#include <stdio.h>
#include <string.h>
#include <stack>
#include <iostream>


#include "symbols.h"

using namespace std;

extern int yylex();
extern int yylineno;
extern char* yytext;


#define row 500
#define col 16
#define MAX_STATES 24
#define MAX_SYMBOLS 14

stack<string> s;




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


int getValueFromMatrix(int state, int symbol) {
    
    int val = (state-1)*15 + symbol;  //see formula_helper.txt
    
    return val;
    
    //printf("(%d,%d)  =  %s  ,val = %d",symbol,state,x[val], val);
}

void read_table(FILE* fp, char x[row][col]){
    
    char buf[300];
    
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
    st = 24, sy = LBRACE;
    int va = getValueFromMatrix(st, sy);
    
    //HELPER extract first char from string
    printf("First Charecter : (%d,%d)  =  %c\n",st,sy, *x[va]);
    printf("String : (%d,%d)  =  %s\n",st,sy,x[va]);
    
   
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

void print_table_to_console(char x[row][col]){
    
    for (int st=1; st<=MAX_STATES; st++) {
        for (int sy = 1; sy<=MAX_SYMBOLS; sy++) {
            printf("%s\t",x[getValueFromMatrix(st, sy)]);
        }
        printf("\n");
    }
}


void run(char x[row][col], FILE *file)
{
    read_table(file,x);
    //start_parser();
    print_table_to_console(x);
    
    s.push("A");
    s.push("B");
    s.push("C");
    s.push("D");
    
    cout << "Stack pop = " << s.top() << endl;
    
//    for(int i = 0; i< row; i++){
//        printf("%d :%s\n",i,x[i]);
//    }
}

int main(int argc, char *argv[] )
{
    if ( argc != 2 ) /* argc should be 2 for correct execution */
    {
        
        printf( "usage: %s filename", argv[0] );
    }
    else
    {
        char x[row][col];
        FILE *file = fopen( argv[1], "r" );
        if ( file == 0 )
        {
            printf( "Could not open file\n" );
        }
        else
        {
            run(x, file);
        }
    }
 return 0;
}








