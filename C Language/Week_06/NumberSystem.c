#include <stdio.h>
#include <math.h>

int main(){
    int number,base;
    int size,index;
    int temp;
    while(scanf("%d %d",&number,&base)!=EOF){
        size=1;
        index=0;
        //Check array size
        while(pow(base,size)<number){
            size++;
        }
        int result[size];
        //Do transformation
        temp=number;
        while(temp>0){
            result[index]=temp%base;
            temp/=base;
            index++;
        }
        //Output result
        printf("Change %d to base %d number system: ",number,base);
        for(int i=index-1;0<=i;i--){
            printf("%d",result[i]);
        }
        puts("");
    }
    return 0;
}

//(11)d=(1011)b
//11/2=5...1
//5/2=2...1
//2/2=1...0
//1/2=0...1

//size
//11<=2*4
