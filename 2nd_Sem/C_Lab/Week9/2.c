#include<stdio.h>
#include<stdlib.h>

int main(){
    char filename[50];
    printf("Enter the file name: ");
    scanf("%s",filename);

    int n;
    char data[100];
    printf("Enter the number of lines to be written: ");
    scanf("%d",&n);
    printf("\nEnter lines..\n");

    FILE *fp = fopen(filename,"w");
    for (int i = 0; i<n+1; i++){
        gets(data);
        fputs(data, fp);
        fputs("\n",fp);
    }

    fclose(fp);

    char c;
    fp = fopen(filename, "r");
    printf("\nFile Contents.....\n");
    c = fgetc(fp);
    while(c != EOF){
        printf("%c",c);
        c = fgetc(fp);
    }
    fclose(fp);

    return 0;
}