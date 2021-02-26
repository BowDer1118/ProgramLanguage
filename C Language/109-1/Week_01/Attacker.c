#include <stdio.h>
#include <stdlib.h>

int main()
{
    int att,life,temp;
    //EOF=EndOfFile
    //讓程式處於一直等待input的狀態
    while(scanf("%d %d",&att,&life)!=EOF){
        if(att>life){
            temp=life;
            life=att;
            att=temp;
        }
        printf("%d\n",life-att);
    }
    return 0;
}
