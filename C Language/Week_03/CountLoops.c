#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int counter=0;
    int iteration=0;
    while(scanf("%d",&x)!=EOF){
        //Init global variable
        iteration=1;
        counter++;
        printf("Case %d:\n",counter);
        printf("Iteration %d: %d\n",iteration,x);

        while(x>1){
            iteration++;
            if(x%2==0){
                x=x/2;
            }else if(x%2!=0){
                x=3*x+1;
            }
            printf("Iteration %d: %d\n",iteration,x);
        }
        printf("The number of iterations is %d.\n",iteration);
        printf("\n");
    }
    return 0;
}
