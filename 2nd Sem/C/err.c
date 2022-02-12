#include<stdio.h>
#include<errno.h>
#include<string.h>

int main(){
    FILE *fp = fopen("file1.txt","r");

    //printf("Error details: ID %d and message : %s\n", errno, strerror(errno));

    //fputc('A',fp);

    //perror("MESSAGE");

    /*
    if (fp == NULL){
        printf("Failure\n");
    }
    else{
        char ch = fgetc(fp);
        //printf("%c\n", ch);
        fputc(ch, stdout);

        printf("file read successfully\n");
    }
    */
    