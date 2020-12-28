#include <stdio.h>
#include <stdbool.h>
 
int getLeftUnderAttack(int row,int col,int size,int chess_board[size][size]){
    int count=0;
    while(row<size-1&&col>0){
        row++;
        col--;
        if(chess_board[row][col]==1){
            count++;
        }
    }
    return count;
}

int getRightUnderAttack(int row,int col,int size,int chess_board[size][size]){
    int count=0;
    while(row<size-1&&col<size-1){
        row++;
        col++;
        if(chess_board[row][col]==1){
            count++;
        }
    }
    return count;
}

int main(){
    int size;
    bool flag=false;

    while(true){
        scanf("%d",&size);
        if(size==0){
            break;
        }

        int chess_board[size][size];
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                scanf("%d",&chess_board[i][j]);
            }
        }

        int count=0;

        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                if(chess_board[i][j]==1){
                    count+=getLeftUnderAttack(i,j,size,chess_board);
                    count+=getRightUnderAttack(i,j,size,chess_board);
                }
            }
        }

        if(count==0){
            printf("There is no attack.");
        }else if(count==1){
            printf("There is 1 attack.");
        }else{
            printf("There are %d attacks.",count);
        }
        puts("");
    }
}