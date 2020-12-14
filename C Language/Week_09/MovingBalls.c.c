#include <stdio.h>
#include <math.h>
#include <stdbool.h>

void makeResultSheet(int result[]){
    bool canContain;
    int pegs[51]={0};
    int rIndex=0;
    int pIndex=0;
    int incoming=1;
    
    pegs[pIndex]=1;
    pIndex++;

    while(rIndex<51){
        canContain=false;
        incoming++;

        for(int i=0;i<rIndex+1;i++){
            if(pegs[i]!=0){
                int temp=pegs[i]+incoming;
                if((int)sqrt(temp)*(int)sqrt(temp)==temp){
                    pegs[i]=incoming;
                    canContain=true;
                    break;
                }
            }
        }

        if(!canContain){
            pegs[pIndex]=incoming;
            pIndex++;
            result[rIndex]=incoming-1;
            rIndex++;
        }
    }
}   

int main(){
    int result[51]={0};
    makeResultSheet(result);
    int count;
    while(scanf("%d",&count)!=EOF){
        printf("%d\n",result[count-1]);
    }
}
