#include <stdio.h>

void checkArray(int data[],int len){
    for(int i=0;i<len;i++){
        printf("%d ",data[i]);
    }
}

void rMajar(int input[],int output[],int len){
    for(int i=0;i<len;i++){
        output[i]=input[i];
    }
}

void cMarjar(int input[],int output[],int len,int offset){
    int position=0;
    for(int i=0;i<len;i++){
        if(position>(len-1)){
            position-=(len-1);
        }
        output[i]=input[position];
        position+=offset;
    }
}


void dimensionUp(int output[],int len,int col){
    for(int i=0;i<len;i++){
        if(i!=0&&(i+1)%col==0){
            printf("%d\n",output[i]);
        }else{
            printf("%d ",output[i]);
        }
    }
}

void dimensionDown(int output[],int len){
    for(int i=0;i<len;i++){
        if(i!=len-1){
            printf("%d ",output[i]);
        }else{
            printf("%d\n",output[i]);
        }
    }
}

int main(){
    int row,col,len;
    char mode,majar;
    int count=0;
    while(scanf("%d %d %d %c %c",&row,&col,&len,&mode,&majar)==5){
        int input[len];
        int output[len];
        for(int i=0;i<len;i++){
            scanf("%d",&input[i]);
        }
        
        if(count!=0){
            puts("");
        }

        if(mode=='U'){
            if(majar=='R'){
                rMajar(input,output,len);
            }else{
                cMarjar(input,output,len,row);
            }
            dimensionUp(output,len,col);
        }else{
            if(majar=='R'){
                rMajar(input,output,len);
            }else{
                cMarjar(input,output,len,col);
            }
            dimensionDown(output,len);
        }
        count++;
    }
    return 0;
}