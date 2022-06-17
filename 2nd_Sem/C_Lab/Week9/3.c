#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the number of elements you want to sort: ");
    scanf("%d",&n);

    printf("Enter the Elements: ");
    int arr[n];
    for (int i = 0;i < n; i++)
        scanf("%d",&arr[i]);
    
    printf("\nArray before sorting:\n");
    for (int i = 0;i < n; i++)
        printf("%d ",arr[i]);

    for (int i = 1;i < n; i++){
        int curr = arr[i];
        int j = i-1;
        while(arr[j] > curr && j>=0){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = curr;
    }

    printf("\n\nArray after sorting:\n");
    for (int i = 0;i < n; i++)
        printf("%d ",arr[i]);
    printf("\n");
    
    return 0;
}