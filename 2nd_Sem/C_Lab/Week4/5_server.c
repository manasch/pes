#include<stdio.h>
#include"5_header.h"

int prime(int n){
    int cnt = 0;
    for(int i=1;i<=n;i++){
        if(n%i==0)
            cnt++;
    }
    if(cnt == 2)
        return 1;
    else if(cnt > 2)
        return 0;
}

int next(int n){
    int i=n+1;
    while(1){
        if (prime(i))
            break;
        i++;
    }
    return i;
}