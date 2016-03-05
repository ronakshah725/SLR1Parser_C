#include <stdio.h>
#include <string.h>
#include <stack>
#include <iostream>
#include <stdlib.h>


#include "symbols.h"

using namespace std;

extern int yylex();
extern int yylineno;
extern char* yytext;


#define row 500
#define col 16
#define MAX_STATES 24
#define MAX_SYMBOLS 14
#define shift 55
#define reduce 77

stack<string> s;
char tokens[] = {'{',	'}',	'l',	'p',	'=',	'f',	'n',	'x',	'$',	'P',	'T',	'S',	'R',	'C'};




void printTokens(int ntoken)
{
    
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
              case DOLLAR:
                  printf("$");
                  break;
              default:
                  printf("Syntax error in line %d\n",yylineno);
          }
}


int getValueFromMatrix(int state, int token) {
    
    int val = (state-1)*15 + token;  //see formula_helper.txt
    
    return val;
    
    //printf("(%d,%d)  =  %s  ,val = %d",token,state,x[val], val);
}

char* getVal(int state, int token, char x[row][col]) {
    
    return x[getValueFromMatrix(state, token)];

}

int getAction(int state, int token, char x[row][col]){
    
    char* actionString = getVal(state, token, x);
    
    if(isdigit(*actionString))
        return shift;
    else if (isalpha(*actionString))
        return reduce;
    else
        return -100;
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
        printf("done");
    }
//    int st, sy; //state and token
//    st = 1, sy = LBRACE;
//    int va = getValueFromMatrix(st, sy);
//    
//    //HELPER extract first char from string
//    printf("First Charecter : (%d,%d)  =  %c\n",st,sy, *x[va]);
//    printf("Stringdw : (%d,%d)  =  %s\n",st,sy,x[va]);
//    printf("Ended");
    
   
}

int getToken(void){
    return yylex();
}



int getSym(char sym){
    for (int i = 0; i<=MAX_SYMBOLS; i++)
        if(tokens[i] == sym)
            return i+1;
    return -1;
}


/////TODO
int slr(char x[row][col]){
    
    int accepted = 0;
    printf("in slr");
    int token = getToken();
    int state = 1;


    s.push(to_string(state));
    
    int method = getAction(state, token, x);
    int val = getValueFromMatrix(state, token);
    string action = "";
    method = getAction(state, token, x);
    action = x[val];
    
    
    while(action!="0" && action!="9999"){

        if (method==shift){
            s.push(to_string(getSym(token)));
            s.push(to_string(state));
            token = getToken();
            
        }
        else if (method == reduce){
            
            string al = x[val];
            char first = al[2];
            char nt = al[0];
            while(s.top()[0]!=first){
                s.pop();
            }
            s.pop();
            int gotostate = stoi(s.top());
            int sy = getSym(nt);
            int gotoval = getValueFromMatrix(gotostate, sy);
            s.push(to_string(nt));
            s.push(x[gotoval]);
        }

        

        state = stoi(s.top());
        method = getAction(state, token, x);
        action = x[val];
     
    }
    
    if(action=="0")
        accepted =-1;
    else if(action=="9999")
        accepted = 1;
        
    
    
    
    //initialize stack to 1st state

    
    
    return accepted;
}



void print_table_to_console(char x[row][col]){
    
    for (int st=1; st<=MAX_STATES; st++) {
        for (int sy = 1; sy<=MAX_SYMBOLS; sy++) {
            printf("%s\t",x[getValueFromMatrix(st, sy)]);
        }
        printf("\n");
    }
    printf("done printing");
}
void start_parser(void)
{
    int ntoken;
    
    ntoken = yylex();
    
    while(ntoken!=DOLLAR) {
        
        
        printTokens(ntoken);
        ntoken = yylex();
    }
    printf("$\nThanks!!");
}


void run(char x[row][col], FILE *file)
{
    read_table(file,x);
    //print_table_to_console(x);
    printf("String parsed : %d",12);
    int accepted ;
    slr(x);
    
    
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
//            start_parser();
            run(x, file);

        }
    }
 return 0;
}

//PRINT HELPER

////    for(int i = 0; i< row; i++){
//        printf("%d :%s\n",i,x[i]);
//    }






