#include <stdio.h>

int main(){
    int a,b,c,temp;
    while(scanf("%d %d %d",&a,&b,&c)!=EOF){
        //check value 
        if(a>b&&a>c){
            temp=c;
            c=a;
            a=temp;
        }else if (b>a&&b>c)
        {
            temp=c;
            c=b;
            b=temp;
        }
        
        //calculate
        if(c*c==a*a+b*b){
            puts("yes");
        }else
        {
            puts("no");
        }
    }
}