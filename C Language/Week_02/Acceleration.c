#include <stdio.h>

int main() {
    int v; //speed
    int t; //time
    int result; //distance of object displacement

    while (scanf("%d %d",&v,&t)!=EOF){
        result=8*v*t;
        printf("%d\n",result);
    }
    
    return 0;
}

/*
    v=0+at -->a=v/t
    x=0+1/2*a*t -->x=1/2*a*(4t)*(4t)
    -->x=1/2*(v/t)*4t*4t
    -->x=v*4*2*t
    -->x=8*v*t
*/


