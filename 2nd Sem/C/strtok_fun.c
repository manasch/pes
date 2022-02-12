#include<stdio.h>
#include<string.h>

int main(){
    FILE *fp = fopen("sample.txt","r");

    char buffer[100];

    fgets(buffer, 100, fp);
    fputs(buffer, stdout);

    char* word = strtok(buffer, " ");
    printf("\n%s", word);

    word = strtok(buffer," ");
    printf("\n%s", word);

    //word = strtok(NULL," ");
    //printf("\n%s", word);

    while (word != NULL)
    {
        word = strtok(NULL, " ");
        printf("\n%s", word);
    }

    

}