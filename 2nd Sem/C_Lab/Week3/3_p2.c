#include<stdio.h>

int tri();
void main(){
    int x,y,z,a;
    printf("Enter the three angles of triangle: ");
    scanf("%d %d %d",&x,&y,&z);
    a=tri(x,y,z);
    if (a == 180)
        printf("Triangle is valid");
    else
        printf("Triangle is not valid");
}
int tri(int x, int y, int z){
    return (x+y+z);
}