#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num,fir,sec;
    int n=0;
    scanf("%d",&num);
    while(n<num)
    {
        scanf("%d %d",&fir, &sec);

        if(fir<sec){
            printf("<");
        }
        if(fir>sec){
            printf(">");
        }
        if(fir==sec){
            printf("=");
        }
        printf("\n");
        n++;
    }
    return 0;
}
