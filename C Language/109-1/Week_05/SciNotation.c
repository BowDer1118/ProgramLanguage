#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int p;
    int k;
    double sum;
    int count;
    while(scanf("%d %d",&p,&k)!=EOF){
        sum=1.0/p;
        count=0;
        for(int i=0;i<k-1;i++){
            sum/=p;
        }
        while(sum<1.0){
            sum*=10;
            count--;
        }
        printf("%d^-%d = %.6lfE%d\n",p,k,sum,count);
    }
}
