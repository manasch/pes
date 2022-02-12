#include<stdio.h>

int mySearch(int [],int ,int ,int);
int main(){
    int a[100];
    int n,key,i;
    FILE *fp = fopen("search.txt", "r");

    printf("How many number to read from file: ");
    scanf("%d", &n);

    for (i=0; i<n; i++)
        fscanf(fp, "%d", &a[i]);
    

    fclose(fp);

    printf("Enter the element to be searched: ");
    scanf("%d", &key);

    int res = mySearch(a, 0, n-1, key);

    if (res == -1)
        printf("not found");
    else
        printf("Found at %d", res);
    return 0;
}


int mySearch(int a[],int l,int h,int k){
    int res;
    if (l>h)
        res = -1;
    else{
        int mid = (l + h)/2;
        if(a[mid] == k)
            res = mid;
        else if(a[mid] > k){
            l = mid+1;
            mySearch(a, l, h, k);
        }
        else{
            h = mid-1;
            mySearch(a, l, h, k);
        }
    }
    return res;
}