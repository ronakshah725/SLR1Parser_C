//
//  tester.c
//  p2
//
//  Created by Ronak Shah on 3/2/16.
//  Copyright © 2016 Ronak Shah. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "symbols.h"

//TODO
char* getValueFromMatrix(int state, int symbol, char* x[]) {
    
    int val = (state-1)*15 + symbol;  //see formula_helper.txt
    
    return x[val];
    
//    printf("(%d,%d)  =  %s  ,val = %d",symbol,state,x[val], val);
}
int main(){
    int row, col;
    row = 50;
    col = 16;
    char x[row][col];
    char buf[300];
    FILE* fp;
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
    printf("(%d,%d)  =  %s  ,val = %d",st,sy,x[val], val);
}



//HELPER to print
//for(i=0;i<row;i++)
//printf("Row %d:%s\n",i,x[i]);
