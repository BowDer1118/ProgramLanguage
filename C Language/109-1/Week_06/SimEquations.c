#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int main(){
    int u,v,w;
    int a1,a2,a3;
    bool flag;
    while(scanf("%d %d %d",&u,&v,&w)!=EOF){
        flag=true;
        //暴力搜索法
        for(int i=(int)pow(w,1.0/3.0);i>=1;i--){
            if(flag){
                int temp=(int)pow((w-pow(i,3)),1.0/2.0)+1;
                for(int j=temp;j>=1;j--){
                    if(flag){
                        int temp2=(u-i-2*j)/3;
                        for(int k=temp2;k>=1;k--){
                            a1=i+2*j+3*k;
                            a2=i*j*k;
                            a3=i*i*i+j*j+k;
                            if(a1==u&&a2==v&&a3==w){
                                int t3=0;
                                int t2=0;
                                int t1=0;
                                //從小排到大(搜索所有可能的組合)
                                if(i>j&&i>k){   //假設i最大
                                    t3=i;
                                    if(j>k){
                                        t2=j;
                                        t1=k;
                                    }else{
                                        t2=k;
                                        t1=j;
                                    }
                                }else if(j>k&&j>i){ //假設j最大
                                    t3=j;
                                    if(k>i){
                                        t2=k;
                                        t1=i;
                                    }else{
                                        t2=i;
                                        t1=k;
                                    }
                                }else{  //假設k最大
                                    if(i>j){
                                        t3=k;
                                        t2=i;
                                        t1=j;
                                    }else{
                                        t3=k;
                                        t2=j;
                                        t1=i;
                                    }
                                }
                                i=t1;
                                j=t2;
                                k=t3;
                                printf("%d %d %d\n",i,j,k);
                                flag=false;
                                break;
                            }
                        }
                    }else{ 
                        break;
                    }
                }
            }else{
                break;
            }
        }
    }
    return 0;
}