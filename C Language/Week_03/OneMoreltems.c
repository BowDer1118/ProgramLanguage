#include <stdio.h>
#include <stdlib.h>

int main()
{
    int b,p,m;
    int reward,em;
    while(scanf("%d%d%d",&b,&p,&m)!=EOF){
        reward=b/p;
        em=b/p;
        while(em>=m){
            reward+=em/m;
            em=(em/m)+(em%m);
        }
        printf("%d\n",reward);
    }
    return 0;
}
