#include <stdio.h>
#include <stdbool.h>

bool isCorrect(int n1,int n2){
    int data[10];
    int temp;
    //Initial array
    for(int i=0,len=sizeof(data)/sizeof(data[0]);i<len;i++){
        data[i]=0;
    }
    //Start process the number of n1,n2
    for(int i=0;i<10;i++){
        if(i<5){
            temp=n1%10;
            data[temp]-=1;
            n1/=10;
        }else{
            temp=n2%10;
            data[temp]-=1;
            n2/=10;
        }
    }
    //Check array data
    for(int i=0;i<10;i++){
        if(data[i]!=-1){
            return false;
        }
    }
    return true;
}

int main(){
    int c,n2;
    int count=0;
    bool flag;
    while(scanf("%d",&c)!=EOF){
        if(c==0){
            break;
        }
        flag=true;
        if(count!=0){
            puts("");
        }
        for(int i=1234;i<=98765;i++){
            if(i%c==0){
                n2=i/c;
                if(i>=n2){
                    if(isCorrect(i,n2)){
                        flag=false;
                        printf("%05d = %d * %05d\n",i,c,n2);
                    }
                }
            }
        }
        if(flag){
            printf("No pair for c = %d.\n",c);
        }
        count++;
    }
    return 0;
}