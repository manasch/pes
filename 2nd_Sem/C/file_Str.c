#include<stdio.h>
/*
int main(){

    FILE* fp = fopen("input.txt", "r");

    if (fp == NULL)
        printf("Failure\n");
    else{
        char ch_arr[500];*/
        /*fgets(ch_arr, 3, fp);
        fputs(ch_arr, stdout);*/

//        while((fgets(ch_arr,3,fp)) != NULL)
            //printf("%s",ch_arr);
//           fputs(ch_arr, stdout);
//    }
//    fclose(fp);
//    return 0;
//}


//Find the sum of 5 numbers which are in file_data.txt

int find_sum(int *, int );
//void read(FILE *, int *, int );
int new_read(FILE *, int *);

int main(){
    FILE *fp = fopen("format_data.txt","r");
    FILE *fp1 = fopen("formatdata_output.txt","w");

    if (fp == NULL)
        printf("Faliure\n");
    else{
        int i;
        //fscanf(fp, "%d",&i);
        //fprintf(stdout,"Value of i is %d",i);


        //int n=5;
        int a[10];
        //read(fp,a,n);

        int n = new_read(fp,a);
        int s = find_sum(a,n);
        fprintf(stdout,"Sum is = %d",s);
    }
    fclose(fp);
    fclose(fp1);
    return 0;
}
/*
void read(FILE *fp, int *a, int n){
    for (int i = 0;i<n;i++)
        fscanf(fp,"%d",&a[i]);//a+i also works
}*/

int new_read(FILE *fp, int *a){
    int i=0;
    while(fscanf(fp,"%d", a+i) != EOF) //something about being appended
        i++;
    return i;
}


int find_sum(int *a, int n){
    int sum = 0;
    for (int i = 0;i < n; i++)
        sum += a[i];
    
    return sum;
}
