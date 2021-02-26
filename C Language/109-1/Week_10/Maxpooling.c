#include <stdio.h>

int main(){
    int m,n,s,t,q;
    int count=0;
    while(scanf("%d %d %d %d %d",&m,&n,&s,&t,&q)==5){
        if(count!=0){
            puts("");
        }
        int data[m][n];
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                scanf("%d",&data[i][j]);
            }
        }
        //上下可走次數
        int u=(m-s)/q+1;
        //左右可走次數
        int v=(n-t)/q+1;
        
        int answer[u][v];

        for(int i=0;i<u;i++){
            for(int j=0;j<v;j++){
                int max=data[i*q][j*q];
                for(int x=i*q;x<=i*q+s-1;x++){
                    for(int y=j*q;y<=j*q+t-1;y++){
                        if(data[x][y]>max){
                            max=data[x][y];
                        }
                    }
                }
                answer[i][j]=max;
            }
        }

        for(int i=0;i<u;i++){
            for(int j=0;j<v;j++){
                if(j!=v-1){
                    printf("%d ",answer[i][j]);
                }else{
                    printf("%d",answer[i][j]);
                }
            }
            puts("");
        }

        count++;
    }   
}