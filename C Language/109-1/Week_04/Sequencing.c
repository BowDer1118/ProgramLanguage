#include <stdio.h>


int main(){
    int a,ratio,times;
    char type;

    while(scanf("%d %d %d %c",&a,&ratio,&times,&type)!=EOF){
        if(type=='a'){
            for(int i=0;i<times;i++){
                if(i==times-1){
                    printf("%d",a+ratio*i);
                }else{
                    printf("%d, ",a+ratio*i);
                }
            }
        }else{
            for(int i=0;i<times;i++){
                if(i!=0){
                    a*=ratio;
                }
                if(i==times-1){
                    printf("%d",a);
                }else{
                    printf("%d, ",a);
                }
            }
        }
        printf("\n");
    }
    return 0;
}