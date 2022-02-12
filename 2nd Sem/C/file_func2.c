#include<stdio.h>
#include<unistd.h>

/*
int main(){
    FILE* fp = fopen("file.txt","a");
    if(fp == NULL)
        printf("FP is not present!\n");
    else{
        printf("FP present at location %p\n",fp);
        //char ch = fgetc(fp);
        //printf("char is %c",ch); //append option will be at the EOF location

        //fputc(ch, stdout);
        fputc('A',fp);
    }


    return 0;
}*/

int main(){
    FILE* fp = fopen("file.txt", "r");
    FILE* fp1 = fopen("out.txt","w");
    if (fp == NULL || fp1 == NULL)
        printf("NOT PRESENT\n");
    else{
        printf("SUCCESS\n");
        char ch = getc(fp);
        putc(ch , stdout);
        while(ch != EOF){
            sleep(1);
            //putc(ch, fp1);
            putc(ch, stdout);
            ch = fgetc(fp);
        }
    }
    fclose(fp);
    fclose(fp1);
}