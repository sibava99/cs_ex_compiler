#include<stdio.h>
int tmp;

int fact(n){
    int i;
    if (n == 1){
        i = 1;
        return i;
    }
    else{
        fact(n-1);
        i = i *n;
        return 5;
    }
}
int two(){
    return 2;
}
int main(){
    int n = 3;
    int ret;
    ret = fact(n);
    printf("%d\n",ret);
    n = two();
    return 0;
}