#include<stdio.h>
int tmp;

void fact(n){
    if (n == 1){
        tmp = 1;
    }
    else{
        fact(n-1);
        tmp = tmp*n;
    }
}

int main(){
    int n = 3;
    fact(n);
    printf("%d\n",tmp);
    return 0;
}