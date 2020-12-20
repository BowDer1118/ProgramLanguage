#include <stdio.h>

int main(){
    //Matrix Row Column
    int row,col,sRow,sCol,eRow,eCol;
    int count=0;
    while(scanf("%d %d %d %d %d %d",&row,&col,&sRow,&sCol,&eRow,&eCol)==6){
        if(count!=0){
            puts("\n");
        }
        int matrix[row][col];
        //Input data to multiple array(Matrix)
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                scanf("%d",&matrix[i][j]);
            }
        }
        
        //Output sub multiple array(SubMatrix)
        for(int i=sRow;i<=eRow;i++){
            for(int j=sCol;j<=eCol;j++){
                if(j!=eCol){
                    printf("%d ",matrix[i][j]);
                }else{
                    printf("%d",matrix[i][j]);
                }
            }
            if(i!=eRow){
                puts("");
            }
        }
        count++;
    }
    return 0;
}