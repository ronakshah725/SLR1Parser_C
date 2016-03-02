
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

void take_symbols2(void)
{
    FILE *fp;
    fp = fopen("sample.pt","r");
    char line[16] = { 0 } ;
    
    char* buffer[16];
    char* t;
    int i=0;
    fgets(line, 100, fp);
    t = strtok(line, "\t");
    while(t!=NULL){
        buffer[i++] = t;
        
        t = strtok(NULL, "\t");
        
    }
    
    
    
    
    
    
    for (int i = 0; i<16; i++) {
        printf("|%4s\t", buffer[i]);
    }
    
    printf("|"); // for the last column
}

int main()

{
    
    
    take_symbols2();
    
    
    
    return 0;
}

//
//void try(){
//
//
//    char ints[400][400] = { { 0 } };
//    char buffer[1024];
//    FILE *fp;
//    fp = fopen("sample.sfp","r");
//    fgets(buffer, 1024, fp);
//
//    for (int i = 0; i < 4 && fgets(buffer, 1024, fp); i++)
//    {
//        int pos;
//        sscanf(buffer,
//                   "%t%s %s %s %s%n",
//                   &ints[i][0],
//                   &ints[i][1],
//                   &ints[i][2],
//                   &ints[i][3],
//               &pos);
//        {
//            fprintf(stderr, "Invalid format: <%s>\n", buffer);
//            exit(1);
//        }
//    }
//
//
//}




//    for (int i = 0; i < 4 && fgets(buffer, 1024, fp); i++)
//    {
//        int pos;
//        if (sscanf(buffer,
//                   "%d %d %d %d%n",
//                   &ints[i][0],
//                   &ints[i][1],
//                   &ints[i][2],
//                   &ints[i][3],
//                   &pos) != 4 || pos != strlen(buffer) - 1)
//        {
//            fprintf(stderr, "Invalid format: <%s>\n", buffer);
//            exit(1);
//        }
//    }




////sample split code

// 
//#include <stdio.h>
//#include <string.h>
//
//int main ()
//{
//    char buf[] ="abc/qwe/ccd";
//    int i;
//    char *p;
//    char *array[3];
//    i = 0;
//    p = strtok (buf,"/");
//    while (p != NULL)
//    {
//        array[i++] = p;
//        p = strtok (NULL, "/");
//    }
//    for (i=0;i<3; ++i)
//        printf("%s\n", array[i]);
//    return 0;
//}
// 


