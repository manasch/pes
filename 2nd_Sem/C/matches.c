#include<stdio.h>
#include<string.h>

int main(){
    FILE* fp = fopen("matches.csv","r");
    int count = 0;

    char buffer[100];

    if (fp == NULL)
        printf("Error in opening\n");
    else{
        while(fgets(buffer, 500, fp) != NULL){
            char* val = strtok(buffer, ",");
            val = strtok(NULL, ",");

            fputs(val, stdout);
            if(strcmp(val,"2008") == 0)
                count++;

        }
        printf("No. of matches in 2008 are %d", count);
    }
}