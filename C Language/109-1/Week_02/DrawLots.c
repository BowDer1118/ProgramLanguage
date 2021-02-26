#include <stdio.h>

int main(){
    int caseNum;    //The number of cases
    int n;  //The number of counting
    int start; //The counting entry
    int personNum; //The total person number
    int result;

    scanf("%d",&caseNum);
    for(int i=1;i<=caseNum;i++){
        //init variable
        scanf("%d %d %d",&n,&start,&personNum);
        //calculate
        if((start+n)%personNum==0){
            result=personNum;
        }else
        {
            result=(start+n)%personNum;
        }
        //output
        printf("Case %d: %d\n",i,result);
        
    }
}