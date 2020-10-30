#include <stdio.h>
#include <math.h>

int main(){
    unsigned long long  n,p,result;
    while(scanf("%llu %llu",&p,&n)!=EOF){
        result=1;
        while(pow(result,p)<n){
             result++;
         }
        printf("%d\n",result);

    }
    return 0;
}
