#include <stdio.h>
#include <string.h>
#include <stack>
#include <iostream>
#include <stdlib.h>
#include <fstream>



#include "symbols.h"

using namespace std;

extern int yylex();
extern int yylineno;
extern char* yytext;


#define row 500
#define col 16

#define MAX_SYMBOLS 14
#define shift 55
#define reduce 77

stack<string> s;
int tokIndex =0;
int MAX_STATES = 0;


char tokens[] = {'#','{',	'}',	'l',	'p',	'=',	'f',	'n',	'x',	'$',	'P',	'T',	'S',	'R',	'C'};





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
    printf("\t\t\t\t\t\t------------TABLE----------\n\n");
    puts(buf);
         printf("\n");
    
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

    
   
}

int getToken(void){
    return yylex();
}



int getSym(char sym){
    for (int i = 0; i<=MAX_SYMBOLS; i++)
        if(tokens[i] == sym)
            return i;
    return -1;
}


int slr(char x[row][col]){
    
    
    int accepted = 0;
    int token = getToken();
    int state = 1;
    s.push(to_string(state));
    int method = getAction(state, token, x);
    int val = getValueFromMatrix(state, token);
    string action = "";
    method = getAction(state, token, x);
    action = x[val];
    int i = 0;
    
    
    while(action!="0" || action!="9999"){
    
        if (method==shift){
            s.push(string(1,tokens[token]));
            
            s.push(action);
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
            s.push(string(1,nt));
            s.push(x[gotoval]);
        }
        
        
        
        state = stoi(s.top());
        method = getAction(state, token, x);
        val = getValueFromMatrix(state, token);
        action = x[val];
        i++;
        if(action=="9999"){
            break;
        }
        
    }
    
    if(action=="0")
        accepted =-1;
    else if(action=="9999")
        accepted = 1;
    
   

    
    
    
    return accepted;

    
    

}


int states(string fname) {
    int number_of_lines = 0;
    string line;
    ifstream myfile(fname);
    
    while (std::getline(myfile, line))
        ++number_of_lines;
    
    return number_of_lines;
    
}










void start_parser(void)
{
    int ntoken;
    
    ntoken = yylex();
    
    while(ntoken!=DOLLAR) {
        
        
        //printTokens(ntoken);
        printf("%d ",ntoken);
        ntoken = yylex();
    }

}

void print_table_to_console(char x[row][col]){
    
    
    
    printf("\t");
    for (int st=1; st<=MAX_STATES; st++) {
        for (int sy = 1; sy<=MAX_SYMBOLS; sy++) {
            printf("%s\t",x[getValueFromMatrix(st, sy)]);
        }
        printf("\n");
        printf("\t");

    }


}


void run(char x[row][col], FILE *file)
{

    read_table(file,x);
    print_table_to_console(x);
    

    int accepted = slr(x);
    
    if(accepted==1)
            printf("\nProgram parsed successfully!!\n\n");
    else
         printf("\nProgram parsed successfully!!\n\n");
    


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
        MAX_STATES = states(argv[1]);
        MAX_STATES -= 2;

        if ( file == 0 )
        {
            printf( "Could not open file\n" );
        }
        else
        {
            //start_parser();
            run(x, file);
        }
    }
 return 0;
}








