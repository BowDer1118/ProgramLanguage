#include <stdio.h>
#include <stdbool.h>

int main(){
    bool flag=false;
    while(1){
        int num;
        scanf("%d",&num);

        if(num==0){
            break;
        }

        unsigned int ta,tb,tc,td,len;
        scanf("%u.%u.%u.%u/%u",&ta,&tb,&tc,&td,&len);

        if(flag){
            puts("");
        }

        puts("--------------------------------------------------------------------------------");
        printf("The following addresses are within the subnetwork %u.%u.%u.%u/%u:\n",ta,tb,tc,td,len);

        unsigned int domain=0;
        domain+=(ta<<24);
        domain+=(tb<<16);
        domain+=(tc<<8);
        domain+=(td);
        
        domain>>=(32-len);

        for(int i=0;i<num;i++){
            scanf("%u.%u.%u.%u",&ta,&tb,&tc,&td);
            unsigned int sub=0;
            sub+=(ta<<24);
            sub+=(tb<<16);
            sub+=(tc<<8);
            sub+=td;

            sub>>=32-len;

            if(sub==domain){
                printf("%u.%u.%u.%u\n",ta,tb,tc,td);
            }
        }

        puts("--------------------------------------------------------------------------------");
        flag=true;
    }


    return 0;
}
