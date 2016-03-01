//
//  main.c
//  parser
//
//  Created by Ronak Shah on 3/1/16.
//  Copyright © 2016 Ronak Shah. All rights reserved.
//

#include <stdio.h>

void printer1(char* str);
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    printf("my\n");
    char* a = "as";
    printer1(a);
    return 0;
}

void printer1(char* str){
    printf("String : %s\n",str);
}
