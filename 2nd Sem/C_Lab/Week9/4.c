#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"4.h"


int main()
{
    FILE* fp = fopen("student.csv","r");
    if(fp == NULL)
        printf("File doesn't exist");
    else
    {
        char buffer[500];
        char *item;
        int i = 0;
        student s[100];

        while(fgets(buffer, 500, fp))
        {
            item = strtok(buffer, ",");
            s[i].rno = atoi(item);
            item = strtok(NULL, ",");
            strcpy(s[i].name,item);

            i++;
        }

        int n = i;
        fclose(fp);

        student *p[100];
        
        for(i = 0; i < n; i++)
            p[i] = &s[i];

        //menu
        printf("Enter your option: \n");
        printf("1. Sort based on roll no.\n");
        printf("2. Sort based on name\n");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: app(p, n, sort_roll);
            printf("\nSorted based on roll no. :\n");
            for (int i = 0; i < n; i++)
                printf("%d,%s", p[i]->rno, p[i]->name);
            break;
        
        case 2: app(p, n, sort_name);
            printf("\nSorted based on name:\n");
            for (int i = 0; i < n; i++)
                printf("%d,%s", p[i]->rno, p[i]->name);
            break;

        default:
            printf("\nExiting the program");
            break;
            exit(0);
        }

    }
    return 0;
}