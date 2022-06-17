#include<stdio.h>
#include<stdlib.h>

void main(){
    char txt[100],pat[100];
    int n,m;
    printf("Enter the text: ");
    scanf("%[^\n]s",txt);
    fflush(stdin);
    printf("\nEnter the pattern to be searched: ");
    scanf("%s[^\n]s",pat);
    n = strlen(txt);
    m = strlen(pat);
    int pos = pattern_match(txt,n,pat,m);
    if (pos == -1)
        printf("\nNot Found");
    else
        printf("String matched at %d location", pos);
}

int pattern_match(char txt[],int n,char pat[],int m){
    int i,j;
    for(i=0;i<=n-m;i++){
        for(j=0;j<m && txt[i+j] == pat[j] ;j++)

        if (j==m)
            return i;
    }
    return -1;
}