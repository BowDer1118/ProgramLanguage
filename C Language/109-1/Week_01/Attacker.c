#include <stdio.h>
#include <stdlib.h>

int main()
{
    int att,life,temp;
    //EOF=EndOfFile
    //���{���B��@������input�����A
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
