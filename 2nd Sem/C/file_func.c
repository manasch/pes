#include<stdio.h>

int main(){
    FILE* fpp = fopen("read_file.txt","r");
    if(fpp == NULL)
        printf("FPP is not present!\n");
    else
        printf("FPP present at location %p\n",fpp);
    
    FILE *fp = fopen("data_file.txt","r");
    if (fp == NULL)
        printf("FP not present!\n");
    else{
        printf("FP present at location %p\n",fp);
        char ch = fgetc(fp);
        //printf("Character read is ---%c",ch);
        while(ch != EOF){
            printf("%c", ch);
            //fputc(ch, stdout);
            ch = fgetc(fp);
        }
    }
    fclose(fpp);
    //fclose(fp);
    int n = fclose(fp);
    //char ch = fgetc(fp);
    //printf("\nCharacter read is ---%c",ch);
    printf("\nafter closing %p", fp);
    if (n == 0)
        printf("\nFile is closed");
    else
        printf("\nNot closed");

    fp = NULL; //to prevent it from being a dangling pointer

    return 0;
}