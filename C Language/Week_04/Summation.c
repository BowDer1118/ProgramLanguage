#include <stdio.h>

int main(){
    int lb,ub,a,b;
    int total;
    while(scanf("%d %d %d %d",&lb,&ub,&a,&b)==4){
        total=0;
        for(int i=lb;i<=ub;i++){
            //printf("%d %d\n",i,a*i);
            if(a*i<=b){
                total+=i;
            }
        }
        printf("%d\n",total);
    }
    return 0;
}