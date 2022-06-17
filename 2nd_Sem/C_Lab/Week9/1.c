#include<stdio.h>
#include<stdlib.h>

int main(){
    char c;
    FILE *fp1 = fopen("file1.txt", "r");
    FILE *fp2 = fopen("file2.txt", "r");
    FILE *fp3 = fopen("file3.txt", "w");

    if (fp1 == NULL || fp2 == NULL){
        puts("Files could not be opened");
        exit(0);
    }

    while((c = fgetc(fp1)) != EOF)
        fprintf(fp3, "%c", c);
    
    fprintf(fp3, "\n");
    while((c = fgetc(fp2)) != EOF)
        fprintf(fp3, "%c", c);
    
    printf("Merged Text");

    fclose(fp1); fclose(fp2); fclose(fp3);
    return 0;
}