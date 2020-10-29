#include <stdio.h>


int main(){
    int cases;
    scanf("%d",&cases);
    int base,data1,data2,next,sum;

    for(int i=1;i<=cases;i++){
        scanf("%d%d%d",&base,&data1,&data2);
        printf("Case %d: %d + %d (base %d)\n",i,data1,data2,base);
        next=0;
        sum=0;

        while(data1>=1||data2>=1||next!=0){
            sum=data1%10+data2%10+next;
            if(sum>=base){
                printf("%d + %d + %d = %d with one carry\n",data1%10,data2%10,next,data1%10+data2%10+next-base);
                next=1;
            }else{
                printf("%d + %d + %d = %d\n",data1%10,data2%10,next,data1%10+data2%10+next);     
                next=0;
            }
            data1/=10;
            data2/=10;
        }
        printf("\n");
    }    
    return 0;
}