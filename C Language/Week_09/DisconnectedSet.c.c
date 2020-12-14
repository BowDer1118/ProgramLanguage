#include <stdio.h>

int disconnectedSet(int n,int a,int b,int c){
    if(n>3){
        return disconnectedSet(n-1,b,c,a+b);
    }
    if(n<3){
        return b;
    }
    return c;
}

int main(){
    int N;
    while(scanf("%d",&N)!=EOF){
        printf("%d\n",disconnectedSet(N+1,1,1,2));
    }
}