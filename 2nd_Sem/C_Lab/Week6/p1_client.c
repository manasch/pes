#include<stdio.h>

int main(){
    int matrix[5][5];

    for (int i=1; i<=5; i++)
        for (int j=1; j<=5; j++){
            if (i+j<=5)
                matrix[i-1][j-1] = 1;
            else if (i+j>=7)
                matrix[i-1][j-1] = -1;
            else
                matrix[i-1][j-1] = 0;
        }
    
    printf("The required 5 x 5 matrix: \n");

    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++)
            printf("%2d\t",matrix[i][j]);
        printf("\n");
    }
    return 0;
}