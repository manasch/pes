#include<stdio.h>
#include<string.h>
#include<errno.h>

int main(){
    FILE* fp = fopen("file1.txt","r");

    char ch;
    while(!feof(fp)){
        ch = fgetc(fp);
        fputc(ch, stdout);
    }

    perror("\nMESSAGE");
    //if(ferror)
}