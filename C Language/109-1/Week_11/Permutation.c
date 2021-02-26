#include <stdio.h>

//做升序排列
void sort(int start,int end,char data[]){
    for(int i=start;i<end;i++){
        for(int j=start;j<end;j++){
            if(data[j+1]<data[j]){
                char temp=data[j+1];
                data[j+1]=data[j];
                data[j]=temp;
            }
        }
    }
}

int main(){
    int cases;
    scanf("%d",&cases);
    
    for(int i=0;i<cases;i++){
        char string[1000];
        scanf("%s",&string);
        //算字串長度
        int len=0;
        for(int i=0;i<1000;i++){
            //檢查字元陣列的結尾
            if(string[i]=='\0'){
                break;
            }
            len++;
        }
        //記住要交換的位置
        int start=len-1;
        //記住要轉換的次數
        int request;
        scanf("%d",&request);
        for(int i=0;i<request;i++){
            
        }
    }
    return 0;
}