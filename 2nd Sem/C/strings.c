/*#include<stdio.h>

void main(){
    //char c[] = {'a','t','m','o','\0'};
    char c[] = "atmo"; // \0 is added automatically
    printf("size = %d\n",sizeof(c));
    printf("%s",c);
}*/

// c[] = "atmo\\0" first \ negates hte 2nd \ and therefore 0 is part of the string, whe "" is used a \0 will be attached to the end automatically

/*
#include<stdio.h>

int main(){
    
    char fname[50], lname[50];
    printf("Enter a name\n");
    scanf("%s %s",fname,lname);
    printf("%s %s",fname,lname);
    
    char name[50];
    printf("Enter a name: ");
    //scanf("%[^\n]s",name); //if this is not done then when the user gives a space, the compiler automatically gives a \0 and hence won't display the full name
    scanf("%[^aeiou]s",name); // stops when it comes across vowel, if ^ is not used then it only accepts vowels
    printf("Hi %s",name); //This was called edit conversion
}*/    


#include<stdio.h>
#include<string.h>

void main(){
    char s1[10] = "pes";
    char s2[10] = "pesu";
    char s3[10] = "lklk";
    //printf("%d %d",sizeof(s1),sizeof(s2));
    printf("\nlenght of s1 = %d",strlen(s1));
    strcat(s3,s2);
    printf("\n%s",s3);

}