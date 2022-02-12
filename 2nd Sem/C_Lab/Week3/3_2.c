#include<stdio.h>
int gcd(int, int, int);
int main(){
    int a,b,c,g;
    printf("Enter the values of a,b and c: ");
    scanf("%d %d %d",&a, &b, &c);
    g = gcd(a,b,c);
    printf("GCD(%d,%d,%d)=%d",a,b,c,g);
    return 0;
}
int gcd(int x, int y, int z){
    int a;
    for (int i =1; i <= x && i <= y && i <= z; i++){
        if (x%i==0 && y%i==0 && z%i==0)
            a = i;
    }
    return a;
}