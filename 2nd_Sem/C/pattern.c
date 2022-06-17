#include<stdio.h>
#include<string.h>

int pattern_match(char [],int , char [], int);

int main(){
    char s1[20],s2[20];
    int l1,l2;
    printf("Enter a string: ");
    scanf("%[^\n]s",s1);
    printf("Enter pattern to match: ");
    fflush(stdin);
    scanf("%s",s2);
    
    l1=strlen(s1);
    l2=strlen(s2);

    int index = pattern_match(s1,l1,s2,l2);
    if (index>0)
        printf("\nPattern matched at %d",index);
    else
        printf("\nPattern doesn't exist");

    return 0;
}

int pattern_match(char txt[], int txt_len, char pattern[], int pat_len){
    int dex,t,d;

    if (pat_len>txt_len)
        return -1;
    
    for (int i=0;i<=(txt_len-pat_len);i++){
        dex=t=i;
        for(d=0;d<pat_len;d++){
            if (pattern[d] == txt[t]){
                t++;
            }
            else
                break;
        }
        if (d == pat_len)
            return dex;
    }
    return -1;
}

/*
int pattern_match(char[],int,char[],int);
#include<stdio.h>
#include<string.h>
int main()
{
    printf("enter the text string\n");
    char text[100];
    char pat[100];
    scanf("%[^\n]s",text);
    fflush(stdin);
    printf("enter the pattern string\n");
    scanf("%[^\n]s",pat);
    int n = strlen(text);
    int m = strlen(pat);
    int pos = pattern_match(text,n,pat,m);
    if(pos == -1)
        printf("pattern not available in text string\n");
    else
        printf("pattern at position %d\n",pos);
    return 0;
}
int pattern_match(char text[],int n,char pat[],int m)
{
    int res = -1;
    int i;
    int j;
    for(i = 0;res == -1 && i<=n-m;i++) // for(i = 0;i<=n-m;i++) for last occurance.
    {
        for(j=0;j<m && text[i+j] == pat[j];)
        {
            j++;
        }
        
        if(j==m)
            //return i-m;// we will see
            res = i;
    }
    return res;
}
*/