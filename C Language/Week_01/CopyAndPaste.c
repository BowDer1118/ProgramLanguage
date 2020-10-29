#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0;
    int num;
    int times=0;
    int total=1;
    scanf("%d",&num);
    while(num>=-1){
            n++;
        while(1){
            if(total>=num){
                break;
            }else{
                times++;
                total=total*2;
            }
            //printf("%d %d\n",total,times);
        }
        if(num==1){
            times=0;
        }
        printf("Case %d: %d\n",n,times);
        times=0;
        total=1;
        scanf("%d",&num);
    }
    return 0;
}
