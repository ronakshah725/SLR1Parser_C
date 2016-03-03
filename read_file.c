
//

#include <stdio.h>   /* required for file operations */
#include <stdlib.h>
#include <string.h>

char head[16] = { 0 } ;

void take_symbols(void)
{
    FILE *fp;
    fp = fopen("sample1.pt","r");

    fscanf(fp, "\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s",
           
           &head[1],&head[2],&head[3],&head[4],&head[5],&head[6],&head[7],
           &head[8],&head[9],&head[10],&head[11],&head[12],&head[13],&head[14]);
    
    
    for (int i = 0; i<16; i++) {
        printf("|%4c\t", head[i]);
    }

}



int main()

{
    
    
    take_symbols();
    
    
    
    return 1;
}

//

//void take_symbols2(void)
//{
//    FILE *fp;
//    fp = fopen("sample.pt","r");
//    char line[16] = { 0 } ;
//
//    char* buffer[16];
//    char* t;
//    int i=0;
//    fgets(line, 100, fp);
//    t = strtok(line, "\t");
//
//    while(t!=NULL){
//        buffer[i++] = t;
//
//        t = strtok(NULL, "\t");
//
//    }
//
//
//    line[15] = '\0';
//
//
//
//    for (int i = 0; i<16; i++) {
//        printf("|%4s\t", buffer[i]);
//    }
//
////    printf("|"); // for the last column
//}





