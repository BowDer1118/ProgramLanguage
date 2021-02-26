#include <stdio.h>

void hammingDistance(int arr[],int index,int N,int H){
    if(N>H&&H>0){
        arr[index]=0;
        hammingDistance(arr,index+1,N-1,H);
        puts("");
        arr[index]=1;
        hammingDistance(arr,index+1,N-1,H-1);
    }

    if(N>H&&H==0){
        for(int i=0;i<index;i++){
            printf("%d",arr[i]);
            
        }
        for(int j=0;j<N;j++){
            printf("%d",0);
            
        }
    }

    if(N==H&&H>0){
        for(int i=0;i<index;i++){
            printf("%d",arr[i]);
        }
        for(int j=0;j<N;j++){
            printf("%d",1);
            
        }
    }
}   

int main(){
    int count;
    int N=0,H=0;
    
    scanf("%d",&count);
    
    for(int i=0;i<count;i++){
        scanf("%d %d",&N,&H);
        int arr[100]={0};
        int index=0;
        hammingDistance(arr,index,N,H);
        if(i!=count-1){
            puts("\n");
        }
    }   
    return 0;
}